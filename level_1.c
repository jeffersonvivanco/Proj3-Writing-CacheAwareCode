/*
 * author: Jefferson Vivanco
 * Function: This function (leverl_1) computes the sum of A[i] and B[i] (at some row determined by j*large) and adds it back to A[i]. It returns
 * 			 the element at A[x+y]. 
 * Optimization: As we can see, in level_1, the inner for loop doesn't access continously the elements at B, so by switching the inner loop with the
 * 				 outerloop, the function can access the elements at B continously and therefore its more cache friendly. (temporal locality) 
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>

#include "proj3.h"




double level_1(double * B, double * A, int x, int y )
{	
    int i, j; 

    for(i = 0; i < LARGE; i++)
        for(j = 0; j < SMALL; j++){
            A[ i ] = A[i] + B[  j*LARGE + i ] ;
		}

    return A[x+y];
}

double level_1_opt(double * B, double * A, int x, int y )
{	
	
	int i, j; 


    for(j = 0; j < SMALL; j++){
		for(i = 0; i < LARGE; i++)
            A[ i ] = A[i] + B[  j*LARGE + i ] ;
		}



	//DO NOT modify the rest of this function 
    return A[x+y];
}
