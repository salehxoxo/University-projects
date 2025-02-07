#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[]) {
    double start, end;
    int N, threads, rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        cout << "Enter N: ";
        cin >> N;
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    double **mat = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++)
        mat[i] = (double *)malloc(N * sizeof(double));

    double *b = (double *)malloc(N * sizeof(double));

    if (rank == 0) {
        srand(time(NULL));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = abs(rand() % 100);
                cout << mat[i][j] << " ";
            }
            b[i] = abs(rand() % 10);
            cout << b[i] << endl;
        }
        cout << "Generated Matrix" << endl;
    }

    MPI_Bcast(&b[0], N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    for (int i = 0; i < N; i++) {
        MPI_Bcast(&mat[i][0], N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    }

    start = MPI_Wtime();
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = i; k < N; k++) {
                mat[j][k] -= (ratio * mat[i][k]);
            }
            b[j] -= (ratio * b[i]);
        }
    }


    // ... rest of your code remains unchanged ...

    end = MPI_Wtime();

    double local_time = end - start;
    double max_time;

    MPI_Reduce(&local_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "\nFinal Result Matrix" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << fixed << setprecision(1) << mat[i][j] << " ";
            }
            cout << fixed << setprecision(1) << b[i] << endl;
        }
        cout << "\nSize of Array = " << N << " x " << N << endl;
        cout << "Time taken by program is : " << setprecision(5) << max_time;
        cout << " sec " << endl;
    }

    MPI_Finalize();
    return 0;
}

