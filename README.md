## Parallel-Sum-Reduction-in-OpenMP
OpenMP implemention of the Parallel Sum Reduction operator that computes the sum of a large array of values.

In this assignment one has to develop an efficient implemention of the Parallel Sum Reduction operator that computes the sum of a large array of values in both OpenMP and OpenCL. A prime criterion in the assignment will be the efficiency of both the implementations and the evidence presented to substantiate claims that implementations are efficient.

## Implementation: 
The basic idea behind the working of any OpenMP program is that, a normal
sequential program can converted into OpenMP program / parallel program by adding just one line of
statement: “ #pragma omp parallel”. This is called parallel construct, the following lines of code after
parallel construct will be executed by multiple threads. This is a very basic idea of how a simple
OpenMP program works.
In this assignment I have made use of two such constructs to compute sum of all the elements of a large
array also calculated sum of elements sequentially to compare the efficiency.
1. Sequential approach
2. Reduction Clause
3. Task-Level Parallelism

#### For a detailed results and conclusion, please refer the report in the repo
