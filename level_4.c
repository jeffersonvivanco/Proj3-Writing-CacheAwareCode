/*
 * author: Jefferson Vivanco
 * Function: The function (level_4.c) takes a linked list and copies each node into an array of nodes and links each node in the array to the node
 * 			 the follows it in the array. This way, the linked list will have its nodes located in one block of memory and not scattered. 
 * Optimization: We saw that the original function uses to loops. One to copy each node and then added to the array. And the other, to link each node
 * 				 in the array and free the node in the original linked list. The two loops would require the program two access the elements twice, 
 * 				 which increases cache use, therefore it having more misses in reading and writing, but if we do it all in one loop, cache gets
 * 				 used less therefore reducing the misses in reading and writing. We are able to link the elements at the same time that we free 
 * 				 each node because since its in an array, we know where the next location is. 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

 
 

void level_4(node** head, int length)
{
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node* new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    node* n = *head;
    int i;
    for(i = 0 ; i < length ; ++i) {
        node copy = { n->value, NULL };
        new_list[i] = copy;
        n = n->next;
    }

    // go through the list again and "link" each node in 
    // the contiguous block to the next node in memory; 
    // free all the nodes in the old list
    n = *head;
    for(i = 0 ; i < length - 1 ; ++i) {
        // link each node in the new list
        new_list[i].next = &new_list[i+1];
        // free the old nodes
        node* free_me = n;
        n = n->next;
        free(free_me);
    }

    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;
}



void level_4_opt(node** head, int length)
{ 
	
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.

    node* new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    
    node* n = *head; 
    int i;
	
    for(i = 0 ; i < length-1 ; ++i) {		
        new_list[i].next = &new_list[i+1];//linkning elements 
		new_list[i].value = n->value; 
		node* p = n;
        n = n->next;
        free(p);		
        
    } 
    new_list[i].value = n->value; //since our loop only goes up to length -1, we are left with one element before the terminating element, which
								  //which is what this line does. 
    new_list[i].next  = NULL;      
     		
    free(n);
    
    *head = new_list;//points to new list (array) 
}
/* DO NOT MODIFY THE FUNCTION THAT FOLLOWS */


void addFront(data * s,  node ** head) {
	if (head == 0 ) return;
	if (s == 0 ) return; 
	
    //allocate memory for storing the node 
    node *n = ( node *)malloc(sizeof( node));
    //make sure that the memory was allocated,
    //if not, just quit
    if (n == NULL) return;
    n->value = *s;
    
    n->next = (*head);
    (*head) = n;
}


