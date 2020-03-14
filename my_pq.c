#include "pQueue.h"
#include <stdlib.h>
#include <stdio.h>

void    initPQueue(pQueue **queue)
{
    (*queue) = (pQueue*)malloc(sizeof(pQueue));
    (*queue)->first = NULL;
    (*queue)->size = 0;
    return;
}

void    addPQueue(pQueue **queue, TYPE val, unsigned int priority)
{
    if ((*queue)->size == MAX_SZ)
    {
        printf("Queue is max\n");
        return;
    }
    pQueueNode *node;
    
    node = (pQueueNode*)malloc(sizeof(pQueueNode));
    node->priority = priority;
    node->val = val;

    if (!((*queue)->first) || !((*queue)->size))
    {
        node->next = NULL;
        (*queue)->first = node;
        (*queue)->size++;
        return;
    }
    else
    {
        if(priority <= (*queue)->first->priority)
        {
            node->next = (*queue)->first;
            (*queue)->first = node;
            (*queue)->size++;
            return;
        }
        else
        {
            pQueueNode *current = (*queue)->first;
            while (current->next)
            {
                if(priority <= current->next->priority)
                {
                    node->next = current->next;//it just swap
                    current->next = node;//SWAAP!!!
                    (*queue)->size++;
                    return;
                }
                current = current->next;
            }
            if (!current->next)
            {
                node->next = NULL;
                current->next = node;
                (*queue)->size++;
                return;
            }

        }
    }
}

TYPE    getPQueue(pQueue **queue)
{
    TYPE returnValue;

    if ((*queue)->size > 0)
    {
        returnValue = (*queue)->first->val;
        (*queue)->first = (*queue)->first->next;
        (*queue)->size--;
    }
    else
		printf("\nQueue is empty.\n");
	return returnValue;
}
