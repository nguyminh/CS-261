//Minh Nguyen
//Asn3: CircListDeque implementation file
//Due Date: 7-20-2014

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	assert(q != 0);
	q->Sentinel = (struct DLink*)malloc(sizeof(struct DLink));
	assert(q->Sentinel != 0);
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
	q->Sentinel->value = 0;
	q->size = 0;	 
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink* link = (struct DLink*)malloc(sizeof(struct DLink));
	link->value = val;
	link->next = 0;
	link->prev = 0;
	return link;

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnK		Pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk)
{
	newLnk->next = lnk->next;
	lnk->next = newLnk;
	newLnk->prev = lnk;
	newLnk->next->prev = newLnk;
	q->size += 1;

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	struct DLink* one = _createLink(val);
	assert(one != 0);
	_addLinkAfter(q, q->Sentinel->prev, one);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	struct DLink* one = _createLink(val);
	assert(one != 0);
	_addLinkAfter(q,q->Sentinel, one);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	struct DLink *first = q->Sentinel->next;
	return first->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	struct DLink *last = q->Sentinel->prev;
	return last->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(lnk != 0);
	free(lnk);
	q->size -= 1;
	
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q)
{
	struct DLink *first = q->Sentinel->next->next;
	struct DLink *sent = q->Sentinel;
	assert(q->size > 0);
	_removeLink(q,q->Sentinel->next);
	q->Sentinel->next = first;
	first->prev = sent;
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	struct DLink *last = q->Sentinel->prev->prev;
	struct DLink *sent = q->Sentinel;
	assert(q->size > 0);
	_removeLink(q, q->Sentinel->prev);
	last->next = sent;
	sent->prev = last;

}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink *current = q->Sentinel->next;
	struct DLink *nextCurr = q->Sentinel->next->next;
	int i;
	for (i=0; i<q->size; ++i)
	{
		free(current);
		current = nextCurr;
		q->size -= 1;
	}
	free (q->Sentinel);	
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q)
{
	if(q->size == 0)
	return 1;
	else
	return 0;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	struct DLink *print = q->Sentinel->next;
	int i;
	for (i=0; i < q->size; ++i)
	{
		printf(",   %d", print->value);
		print = print->next;
	}
	printf("\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	struct DLink *current =  q->Sentinel;
	struct DLink *tmp = q->Sentinel->next;
	int i;
	for (i=0; i<= q->size; ++i)
	{
		current->next = current->prev;
		current->prev = tmp;
		current = tmp;
		tmp = tmp->next;
	}

}
