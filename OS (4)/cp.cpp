#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define N 100
#define MAX_THREADS 4

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int prime_arr[N]={0};

void *printprime(void *ptr)
{
    int  j,flag;
    int i=(int)(long long int)ptr;
    while(i<N)
    {
        printf("Thread id[%d] checking [%d]\n",pthread_self(),i);
        flag=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==0 && (i>1))
        {
            prime_arr[i]=1;
        }
        i+=MAX_THREADS;
  }
}

int main()
{
    int sum = 0;
    clock_t startt1,endt1,startt2,endt2;
    pthread_t tid[MAX_THREADS]={0};
    int count=0;

    printf("------------------------------------------------------\n");
    printf("Showing Count of Prime Using MultiThreading\n");
    printf("------------------------------------------------------\n\n");
    
    startt1 = clock();
    
    for(count=0;count<MAX_THREADS;count++)
    {
        printf("\r\n CREATING THREADS %d",count+1);
        pthread_create(&tid[count],NULL,printprime,(void*)count);
    }
    printf("\n");
    for(count=0;count<MAX_THREADS;count++)
    {
        pthread_join(tid[count],NULL);
    }

    int c=0;
    for(count=0;count<N;count++)
        if(prime_arr[count]==1)
        {
            sum = sum + 1;
		}
           
	printf("Total Prime : %d",sum);
    endt1 = clock();
    double time1 = ((double)endt1-startt1)/CLOCKS_PER_SEC;
 //   printf("\nTime : %f\n", time);

    //MULTIPROCESS
    printf("\n\n------------------------------------------------------\n");
    printf("Showing Count of Prime Using MultiProcessing\n");
    printf("------------------------------------------------------\n\n");
    int start = 1;    
    int end = 100;
    startt2 = clock();
    int range = end - start + 1;
    int chunk_size = range / 4;

    for (int i = 0; i < 4; i++) {
        int pid = fork();
        if (pid == 0) {
            // Child process counts primes in its chunk of the range
            int chunk_start = start + i * chunk_size;
            int chunk_end = chunk_start + chunk_size - 1;
            if (i == 3) {
                chunk_end = end;
            }
            int count = 0;
            for (int j = chunk_start; j <= chunk_end; j++) {
                if (is_prime(j)) {
                    count++;
                }
            }
            printf("Child process %d found %d primes in range [%d, %d]\n", i, count, chunk_start, chunk_end);
            exit(count);
        } else if (pid < 0) {
            // Fork failed
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
    }

    // Parent process waits for all child processes to finish
    int total_count = 0;
    for (int i = 0; i < 4; i++) {
        int child_status;
        wait(&child_status);
        if (WIFEXITED(child_status)) {
            total_count += WEXITSTATUS(child_status);
        } else {
            fprintf(stderr, "Child process failed to exit normally\n");
            exit(1);
        }
    }
    endt2 = clock();
    double time2 = ((double)endt2-startt2)/CLOCKS_PER_SEC;    
    printf("Parent process: Total primes found in range [%d, %d]: %d\n", start, end, total_count);
    printf("\nMultithreading Time : %f", time1);
    printf("\nMultiProcessing Time : %f\n", time2);
    return 0;
 }


