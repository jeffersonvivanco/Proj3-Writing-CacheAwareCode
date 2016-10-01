/*
 * author: Jefferson Vivanco
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>

#include "proj3.h"



int level_0( int * B, int x, int y )
{
	if (!B) return -1; 
	
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            B[ r*N + c ] = 2*(B[ r*N + c ] + 2);

    
    return  B[ x*N + y ];
}


int level_0_opt( int * B, int x, int y )
{
	if (!B) return -1; 

    int c, r; 
	for(r = 0; r < N; r++)
		for(c = 0; c < N; c++)
            B[ r*N + c ] = 2*(B[ r*N + c ] + 2);
	
    

    
    return  B[ x*N + y ];
}
