#include "module.hpp"

#include <iostream>

#include "mpi.h"

int fib(int n)
{
	if(n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int MPI_Test(unsigned int MPI_rank)
{
	unsigned int counter = 0;
	MPI_Win window;
	MPI_Win_create(&counter, sizeof(unsigned int), sizeof(unsigned int), MPI_INFO_NULL, MPI_COMM_WORLD, &window);

	if(MPI_rank == 0)
	{
		printf("[MPI process 0] Value in my window_buffer before MPI_Accumulate: %d.\n", counter);
	}

	MPI_Win_fence(0, window);
	if(MPI_rank != 0)
	{
		printf("[MPI process %d] I accumulate data %d in MPI process 0 window via MPI_Accumulate.\n", MPI_rank, MPI_rank);
		MPI_Accumulate(&MPI_rank, 1, MPI_UNSIGNED, 0, 0, 1, MPI_UNSIGNED, MPI_SUM, window);
	}
	MPI_Win_fence(0, window);

	if(MPI_rank == 0)
	{
		printf("[MPI process 0] Value in my window_buffer after MPI_Accumulate: %d.\n", counter);
	}

	MPI_Win_free(&window);
	return counter;
}