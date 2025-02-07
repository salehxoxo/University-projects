#include <iomanip>
#include <omp.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
    double start, end;
    int N,threds;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter number of threads: " ;
    cin >> threds;

    omp_set_num_threads(threds);

    double** mat = (double**)malloc(N * sizeof(double*));
    
    for (int i = 0; i < N; i++)
        mat[i] = (double*)malloc(N * sizeof(double));
    
    double* b = (double*)malloc(N * sizeof(double));
    
    srand(time(NULL));  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double num2; 
            //cin >> num2;
            mat[i][j] = abs(rand()%100);
        }
        double num;
      //  cin >> num;
        b[i] = abs(rand()%10);
    }
    
    cout << "Randomly Generated Matrix\n";
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << b[i];
        cout << endl;
    }*/

    start = omp_get_wtime();
    int threads;

    for (int i = 0; i < N - 1; i++) {
        #pragma omp parallel for shared(mat, b)
        for (int j = i + 1; j < N; j++) {
            double ratio = mat[j][i] / mat[i][i];
            #pragma omp parallel for shared(mat, b)
            for (int k = i; k < N; k++) {
                mat[j][k] -= (ratio * mat[i][k]);
            }
            #pragma omp atomic
            b[j] -= (ratio * b[i]);
        }
    }

    end = omp_get_wtime();
	cout << endl;
    // Output the results
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << fixed << setprecision(1) << mat[i][j] << " ";
        }
        cout << fixed << setprecision(1) << b[i];
        cout << endl;
    }*/

    cout << "\nSize of Array = " << N << " x " << N << endl;
    cout << "Time taken by program is : " << setprecision(5) << end - start;
    cout << " sec " << endl;

    return 0;
}

