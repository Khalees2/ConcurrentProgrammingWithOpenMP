/* *****************************************************************************************************************************************
 *  Program Name: ParallelReduction.c                                                                                                      *
 *  Problem : Parallel Sum Reduction using Parallel reduction                                                                              *
 *  Created by Salman Khaleel Sab on 22/04/2019                                                                                            *
 *  Code Reference :                                                                                                                       *
 *   http://www.computing.dcu.ie/~davids/courses/CA670/CA670_OpenCL_2p.pdf                                                                 *
 *   https://www.youtube.com/watch?v=nE-xN4Bf8XI&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG                                                   *
 ***************************************************************************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>

//defining array size
#define ARRAY_SIZE 1073741824
static unsigned long array[ARRAY_SIZE];
static unsigned long sum = 0;

//function for initializing the array with numbers ranging from 1 to array size
void load_array(unsigned long array[]){
for(unsigned long i=0;i<ARRAY_SIZE;i++)
	{
		array[i]=i+1;
	}
	
}

int main(){
	
	load_array(array);
	double start_time = omp_get_wtime();
	
	#pragma omp parallel for reduction(+:sum)
		for(unsigned long j=0;j<ARRAY_SIZE;j++)
		{
			sum = sum+array[j];
		}

	double end_time = omp_get_wtime();	
	printf("Parallel Reduction Sum of the array: %lu\n",sum);
	printf("Parallel Reduction Execution Time: %f\n",(end_time-start_time));
	
	return(0);
}



