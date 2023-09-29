#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
   if (pq == NULL || pq->size == 0)
   {
     return NULL;
   }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority)
{
  if (pq->size >= pq->capac) 
  {
    int newCapac = (pq->capac * 2) + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray,sizeof(heapElem) * newCapac);
  pq->capac = newCapac;
  }

  int currentIndex = pq->size;
  pq->heapArray[currentIndex].data = data;
  pq->heapArray[currentIndex].priority = priority;
  pq->size++;

  while (currentIndex > 0) 
  {
    int parentIndex = (currentIndex - 1) / 2;

    if (pq->heapArray[currentIndex].priority > pq->heapArray[parentIndex].priority) 
    {
      // Intercambiar el elemento con su padre
      heapElem temp = pq->heapArray[currentIndex];
      pq->heapArray[currentIndex] = pq->heapArray[parentIndex];
      pq->heapArray[parentIndex] = temp;

      currentIndex = parentIndex;
      } 
    else 
    {
      break; // El elemento está en la posición correcta
    }
  }

}

void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->capac = 3;
  newHeap->size = 0;
  newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * newHeap->capac);
  return newHeap;
}
