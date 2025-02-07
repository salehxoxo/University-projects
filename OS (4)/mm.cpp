#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
//#define N1 4 // matrix size
#define Process 4 // number of processes
#define MAX_THREADS 4
int N, M, P;


int result[1000][1000] = {{0}};
int A[1000][1000], B[1000][1000], C[1000][1000];




void *multiply1(void *arg)
{
    int i,j,k;
    int part = *(int*) arg;
    int start = part * N / MAX_THREADS;
    int end = (part + 1) * N / MAX_THREADS;
	
    for (i = start; i < end; i++)
    {
        for (j = 0; j < P; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}
int main()
{
    int i,j,k;
    clock_t startt1,endt1,startt2,endt2;
    printf("Enter the dimensions of matrix A (NxM): ");
    scanf("%d%d", &N, &M);
    printf("Enter the dimensions of matrix B (MxP): ");
    scanf("%d%d", &M, &P);

    printf("\nEnter the elements of matrix A:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter the elements of matrix B:\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < P; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
	
    //MULTITHREADING
    printf("------------------------------------------------------\n");
    printf("Showing The Matrix Multiplication Using MultiThreading\n");
    printf("------------------------------------------------------\n\n");
    startt1 = clock();
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];
    for (i = 0; i < MAX_THREADS; i++)
    {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, multiply1, &thread_args[i]);
    }

    for (i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("The Product of the Matrices using MultiThreading is:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < P; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    endt1 = clock();
    double time1 = ((double)endt1-startt1)/CLOCKS_PER_SEC;
   //MULTIPROCESSING
    printf("\n------------------------------------------------------\n");
    printf("Showing The Matrix Multiplication Using MultiProcessing\n");
    printf("------------------------------------------------------\n\n");
    startt2 = clock();
    
    int (*C1)[P] = (int (*)[P]) mmap(NULL, sizeof(int[N][P]), PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    for (int i = 0; i < Process; i++) {
        if (fork() == 0) {
            for (int row = i; row < N; row += Process) {
                for (int col = 0; col < P; col++) {
                    C1[row][col] = 0;
                    for (int k = 0; k < M; k++) {
                        C1[row][col] += A[row][k] * B[k][col];
                    }
                }
            }
            exit(0);
        }
    }

    for (int i = 0; i < Process; i++) wait(NULL);

    printf("The Product of the Matrices using MultiProcessing is:\n");
    for (int row = 0; row < N; row++) 
    {
        for (int col = 0; col < P; col++) 
        {
           printf("%d ", C1[row][col]);
        }
       printf("\n");
    }

    munmap(C1, sizeof(int[N][N]));
    endt2 = clock();
    double time2 = ((double)endt2-startt2)/CLOCKS_PER_SEC;
    printf("\nMultithreading Time : %f", time1);
    printf("\nMultiProcessing Time : %f\n", time2);

    return 0;
}

