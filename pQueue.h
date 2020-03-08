//We make sure the header is only loaded once
#pragma once
#ifndef _PQUEUE_H
#define _PQUEUE_H

#include "huffman.h"

//The type of the data stored int the queue
#define TYPE htNode *

//We can easily modify the maximum number of nodes allowed in the queue
#define MAX_SZ 256

//Node type definition
typedef struct			_pQueueNode 
{
	TYPE				val;
	unsigned int 		priority;
	struct _pQueueNode	*next;
	
}						pQueueNode;

//Queue type definition
typedef struct		_pQueue 
{
	unsigned int	size;
	pQueueNode		*first;
}					pQueue;


//The function prototypes
void initPQueue(pQueue **queue);
void addPQueue(pQueue **queue, TYPE val, unsigned int priority);
TYPE getPQueue(pQueue **queue);

#endif