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

void heap_pop(Heap* pq)
{
  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;
  
  //Realizar proceso de hundir el elemento
  int currentIndex = 0;

  while(1)
    {
      int leftChildIndex = 2 * currentIndex + 1;
      int rightChildIndex = 2 * currentIndex + 2;
      
      int largeIndex = currentIndex;

      //Encontrar el indice del elemento mas grande
      if (leftChildIndex < pq->size && pq->heapArray[leftChildIndex].priority > pq-> heapArray[largeIndex].priority)
      {
        largeIndex = leftChildIndex;
      }
      if (rightChildIndex < pq->size && pq->heapArray[rightChildIndex].priority > pq->heapArray[largeIndex].priority)
      {
        largeIndex = rightChildIndex;
      }
      if (largeIndex != currentIndex)
      {
        //Intercambiar el elemento con el hijo mas grande
        heapElem temp = pq->heapArray[currentIndex];
        pq->heapArray[currentIndex] = pq->heapArray[largeIndex];
        pq->heapArray[largeIndex] = temp;

        currentIndex = largeIndex;
      }
      else
      {
        break;
      }
    }
}

Heap* createHeap()
{
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->capac = 3;
  newHeap->size = 0;
  newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * newHeap->capac);
  return newHeap;
}
