/*
 * author: Jefferson Vivanco
 * Function: This function (level_3) adds the element at some position in B with some element at some position in A and sets it to an index in C. In
 * 			 the end, the array is suppose to have the elements of both Matrices A and B, with elements at some position added together. But because
 * 			 of an error in the code, the function overwrites the elements at C[r] instead of adding elements to it. 
 * Optimization: Since, as stated before, elements at C[r] get overwritten, it would be more cache friendly if we only compute C[r] on the last set of
 * 				 iterations (when c = N-1), therefore to optimize it, we put an if statement before C[r] = ...., to only compute it when c=N-1. Had
 * 				 the function been correct, we would be able to split the for loops into two sets of two for loops. This way, each set would add the
 * 				 elements of A and B continously (spatial locality). 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"



long level_3(long * B, long * A, int x)
{
	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 
	
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] = B[ r*N + c ] + A[ c*N + r ] ;
	

	long ret = C[x];
	free (C); C = 0; 
    return ret;
}

long level_3_opt(long * B, long * A, int x)
{
	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 	
    int c, r; 

	for(c = 0; c < N; c++){
        for(r = 0; r < N; r++){
			if(c == (N-1))//We observed that since each element at gets overwritten when c increases by one, we only calculate the sum when c = N-1
				C[ r ] = B[ r*N + c ] + A[ c*N + r ] ;
     }
	}
	//DO NOT modify the rest of this function 
	long ret = C[x];
	free (C); C = 0; 
    return ret;
}

