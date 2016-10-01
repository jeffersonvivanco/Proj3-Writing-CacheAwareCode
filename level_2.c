/*
 * author: Jefferson Vivanco
 * Function: This function creates an array of type data_2 and populates it with 0's. Then it creates an array of chars. The for loop adds sums up
 * 			 all the floats and integers in each data_2 and stores it in a variable. The loop also sets chars 1 and 2 to a position in the array of
 * 			 chars. Then it returns the array of chars. 
 * Optimization: We learned that structures are stored in memory according to the variables that make up the structures. For example, if the variables
				are all doubles, then they will be stored continously because they will take up all the memory space separated for each variable, but
				we had an int and then a double, then there will be padding in between the int and the double which will make the strides between
				memory locations longer. So what we changed was the structure of data_2. We put the doubles first and then the ints and then the
				chars. This would eleminate padding in the begining and then reduce padding between the ints and chars. We named this new structure
				data_3.
 */
  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

char * level_2()
{
	
    data_2 * B = (data_2 * ) calloc( LARGER, sizeof(data_2) ) ;
	if (!B) return 0; 
	double sum_f = 0.0;
	double sum_n = 0; 
	char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );	
	sum_c[2*LARGER] = '\0'; 
	
    int i; 

	for(i = 0; i < LARGER; i++){
		sum_f += B[i].f1 + B[i].f2; 
		sum_n += B[i].n1 + B[i].n2; 
		sum_c[2*i] = B[i].c1;
		sum_c[2*i+1] = B[i].c2;
	}
	
	
    free(B); 
    return sum_c;
}
char * level_2_opt()
{	
	// create the array of structures (same or equivalent to the one
	// in the function above: 
    data_3 * B = (data_3 * ) calloc( LARGER, sizeof(data_3) );
	if (!B) return 0; 	
	
		
	
	// DO NOT modify the following declarations 
	double sum_f = 0.0;
	double sum_n = 0; 
	char * sum_c = (char*) malloc( (2*LARGER + 1) * sizeof(char) );	
	sum_c[2*LARGER] = '\0'; 	
	
	// enter your code here (make sure to free the array B once 
	// before returning) 
    int i; 

	for(i = 0; i < LARGER; i++){
		sum_f += B[i].f1 + B[i].f2; 
		sum_n += B[i].n1 + B[i].n2; 
		sum_c[2*i] = B[i].c1;
		sum_c[2*i+1] = B[i].c2; 
	}
		
    free(B); 			    
	//DO NOT modify the rest of this function 
    return sum_c;
}
