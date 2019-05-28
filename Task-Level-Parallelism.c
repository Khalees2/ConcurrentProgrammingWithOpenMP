/* *****************************************************************************************************************************************
 *  Program Name: Task.c                                                                                                             *
 *  Problem : Parallel Sum Reduction with Task level parallelism                                                                                          *
 *  Created by Salman Khaleel Sab on 22/04/2019                                                                                            *
 *  Code Reference :                                                                                                                       *
 *   http://www.computing.dcu.ie/~davids/courses/CA670/CA670_OpenCL_2p.pdf                                                                 *
 *   https://www.youtube.com/watch?v=nE-xN4Bf8XI&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG                                                   *
 ***************************************************************************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
//defining the array size
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
//function to calculate sum with seperate tasks
long calculateSumByTasks(start,end){

	unsigned long tempSize = 10000000000000;
	unsigned long localSum = 0, localSum1, localSum2;
	unsigned long tempDifference;
	if(end-start<tempSize)
	{
        for(unsigned long i=start;i<end;i++)
        {
			localSum = localSum + array[i];
        }
	}
	else
	{
		tempDifference = end - start;
        #pragma omp task shared(localSum1)
        {
            localSum1 = calculateSumByTasks(start,(end-tempDifference/2));
        }   
        #pragma omp task shared(localSum2)
        {
            localSum2 = calculateSumByTasks((end-tempDifference/2),end);
        }
        #pragma omp taskwait
            localSum = localSum1 + localSum2;
    }
    return localSum;
}
int main()
{
	load_array(array);
	unsigned long sum;
	double start_time = omp_get_wtime();
	
    #pragma omp parallel
    {
        #pragma omp single
        {
            sum = calculateSumByTasks((unsigned long)0,(unsigned long)ARRAY_SIZE);
        }
    }

	double end_time = omp_get_wtime();	
	printf("Task::: Sum of the array: %lu\n",sum);
	printf("Task::: Execution Time: %f\n",(end_time-start_time));
	
	return(0);
}



