#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <time.h>

#define N 4 // number of cities
#define P 4 // number of processes
#define V 4
#define THREADS 4

int graph[V][V] = {
    {0, 4, 1, 3},
    {4, 0, 2, 1},
    {1, 2, 0, 5},
    {3, 1, 5, 0}
};

int final_path[V+1];
int final_min_path[V+1];
int final_res = INT_MAX; //variable for multithreading
int final_cost = INT_MAX; //variable for multiprocessing
pthread_mutex_t lock;

void copyToFinal(int curr_path[])
{
    for (int i=0; i<V; i++)
        final_path[i] = curr_path[i];
    final_path[V] = curr_path[0];
}

void FinalPath(int* path)
{
    for (int i=0; i<=V; i++)
        final_min_path[i] = path[i];
    final_min_path[V] = path[0];
}

void* TSP(void* arg)
{
    int* path = (int*) arg;
    
    do {
        int curr_res = 0;
        for (int i=0; i<V; i++)
            curr_res += graph[path[i % V]][path[(i+1) % V]];
        
        pthread_mutex_lock(&lock);
        if (curr_res < final_res)
        {
            copyToFinal(path);
            final_res = curr_res;
        }
        pthread_mutex_unlock(&lock);
        
    } while (std::next_permutation(path+1,path+V));
    
    return NULL;
}

void TSP_mp(int* path)
{
    do {
        int curr_res = 0;
        for (int i=0; i<V; i++)
            curr_res += graph[path[i % V]][path[(i+1) % V]];

        if (curr_res < final_cost)
        {
            FinalPath(path);
            final_cost = curr_res;
        }

    } while (std::next_permutation(path+1,path+V));
}


int main()
{
    clock_t startt1,endt1,startt2,endt2;
    //MULTITHREADING
    printf("------------------------------------------------------\n");
    printf("Showing The Travelling Salesman Problem Using MultiThreading\n");
    printf("------------------------------------------------------\n\n");
    
    pthread_t thread_id[THREADS];
    int path[V];
    for (int i=0; i<V; i++)
        path[i] = i;
    startt1 = clock();
    pthread_mutex_init(&lock,NULL);
    
    for (int i=0; i<THREADS; i++)
        pthread_create(&thread_id[i],NULL,TSP,(void*)path);
    
    for (int i=0; i<THREADS; i++)
        pthread_join(thread_id[i],NULL);
    
    printf("Minimum cost : %d\n", final_res);
    
    printf("Path Taken : ");
    
    for (int i=0; i<=V; i++)
        printf("%d ", final_path[i]);
    endt1 = clock();
    double time1 = ((double)endt1-startt1)/CLOCKS_PER_SEC;

    //MULTIPROCESSING
    printf("\n------------------------------------------------------\n");
    printf("Showing The Travelling Salesman Problem Using MultiProcessing\n");
    printf("------------------------------------------------------\n\n");
    for (int i=0; i<V; i++)
        path[i] = i;
    startt2 = clock();
    int *shared_final_res = (int*) mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    *shared_final_res = INT_MAX;

    int (*shared_final_path)[V+1] = (int (*)[V+1]) mmap(NULL, sizeof(int[V+1]), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    for (int p = 0; p < P; p++) 
    {
        if (fork() == 0) 
        {
            int start = p * (V-1) / P + 1;
            int end = (p+1) * (V-1) / P + 1;
            std::sort(path + start, path + end);
            do 
            {
                TSP_mp(path);
                if (final_res < *shared_final_res) 
                {
                    *shared_final_res = final_res;
                    for (int i=0; i<=V; i++)
                        (*shared_final_path)[i] = final_min_path[i];
                }
            } while (std::next_permutation(path + start, path + end));
            exit(0);
        }
    }

    for (int p = 0; p < P; p++) wait(NULL);

    printf("Minimum cost: %d\n", *shared_final_res);
    printf("Path Taken : ");
    for (int i=0; i<=V; i++)
        printf("%d ", (*shared_final_path)[i]);
    printf("\n");

    munmap(shared_final_res, sizeof(int));
    munmap(shared_final_path, sizeof(int[V+1]));
    endt2 = clock();
    double time2 = ((double)endt2-startt2)/CLOCKS_PER_SEC;
    printf("\nMultithreading Time : %f", time1);
    printf("\nMultiProcessing Time : %f\n", time2);
    return 0;
}
