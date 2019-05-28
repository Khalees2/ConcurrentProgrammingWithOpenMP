/* *****************************************************************************************************************************************
 *  Program Name: Sequential.c                                                                                                             *
 *  Problem : Parallel Sum Reduction Sequentially                                                                                          *
 *  Created by Salman Khaleel Sab on 22/04/2019                                                                                            *
 ***************************************************************************************************************************************** */

#include<stdio.h>
#include<omp.h>
//defining array size
#define ARRAY_SIZE 1073741824
static unsigned long array[ARRAY_SIZE];
static unsigned long sum = 0;

//function to initialize the array with numbers ranging from 1 to size of the array
void load_array(unsigned long array[]){
for(unsigned long i=0;i<ARRAY_SIZE;i++)
	{
		array[i]=i+1;
	}
	
}

int main(){
	
	load_array(array);
	//starting the clock
	double start_time = omp_get_wtime();
	for(unsigned long j=0;j<ARRAY_SIZE;j++){

		sum = sum+array[j];
	}
    //ending the clock
	double end_time = omp_get_wtime();	

	printf("Sequential Sum of the array: %lu\n",sum);
	printf("Sequential Execution Time: %f\n",(end_time-start_time));
	return(0);
}
