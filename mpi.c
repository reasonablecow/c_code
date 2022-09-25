#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

#define TAG_DONE 0
#define BOSS 0

int main()
{
    int rank;
    int process_count;
    MPI_Init((void*)0, (void*)0);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &process_count);

    if (rank == 0) {
        int length = 10;
        char* buffer = malloc(length * sizeof(*buffer));

        MPI_Status status;
        MPI_Recv(buffer, length, MPI_PACKED, MPI_ANY_SOURCE, TAG_DONE, MPI_COMM_WORLD, &status);
        MPI_Recv(buffer, length, MPI_PACKED, MPI_ANY_SOURCE, TAG_DONE, MPI_COMM_WORLD, &status);
        MPI_Recv(buffer, length, MPI_PACKED, MPI_ANY_SOURCE, TAG_DONE, MPI_COMM_WORLD, &status);

        int received;
        MPI_Get_count(&status, MPI_INT, &received);
        printf("received=%d\n", received);

        MPI_Send((void*)0, 0, MPI_PACKED, 1, TAG_DONE, MPI_COMM_WORLD);
    } else {
        printf("process=%d is sending zero\n", rank);
        MPI_Send((void*)0, 0, MPI_PACKED, BOSS, TAG_DONE, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}
