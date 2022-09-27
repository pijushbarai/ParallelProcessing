#include<stdio.h>
#include<mpi.h>

int main()
{
    MPI_Init(NULL, NULL);
    int r;
    MPI_Comm_ran(MPI_COMM_WORLD, &r);
    printf("%d", r);
    MPI_Finalize();
    

}