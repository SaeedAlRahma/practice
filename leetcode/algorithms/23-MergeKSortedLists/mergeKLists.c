/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <stdio.h>
#include <stdlib.h>
 
typedef struct heapData {
    //dummy
} heapData;
 
typedef struct heapNode {
    //int value;
    struct ListNode* node;
    heapData data;               //dummy
} heapNode;
 
typedef struct PQ {
    heapNode* heap;
    int size;
} PQ;
 
void insert(heapNode aNode, heapNode* heap, int size) {
    int idx;
    heapNode tmp;
    idx = size + 1;
    heap[idx] = aNode;
    while ((idx > 1) && heap[idx].node->val < heap[idx/2].node->val) {
    tmp = heap[idx];
    heap[idx] = heap[idx/2];
    heap[idx/2] = tmp;
    idx /= 2;
    }
}
 
void shiftdown(heapNode* heap, int size, int idx) {
    int cidx;        //index for child
    heapNode tmp;
    for (;;) {
        cidx = idx*2;
        if (cidx > size) {
            break;   //it has no child
        }
        if (cidx < size) {
            if (heap[cidx].node->val > heap[cidx+1].node->val) {
                ++cidx;
            }
        }
        //swap if necessary
        if (heap[cidx].node->val < heap[idx].node->val) {
            tmp = heap[cidx];
            heap[cidx] = heap[idx];
            heap[idx] = tmp;
            idx = cidx;
        } else {
            break;
        }
    }
}
 
heapNode removeMin(heapNode* heap, int size) {
    int cidx;
    heapNode rv = heap[1];
    //printf("%d:%d:%dn", size, heap[1].value, heap[size].value);
    heap[1] = heap[size];
    --size;
    shiftdown(heap, size, 1);
    return rv;
}
void enqueue(heapNode node, PQ *q) {
    insert(node, q->heap, q->size);
    ++q->size;
}
 
heapNode dequeue(PQ *q) {
   heapNode rv = removeMin(q->heap, q->size);
   --q->size;
   return rv; 
}
 
void initQueue(PQ *q, int n) {
   q->size = 0;
   q->heap = (heapNode*)malloc(sizeof(heapNode)*(n+1));
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* sortedList;
    struct ListNode* sortedRoot;
    if(listsSize == 0)
        return NULL;
    printf("Lists Size = %d\n", listsSize);
    PQ q;
    initQueue(&q, listsSize);
    
    // build initial PQ
    heapNode hn;
    for(int i=0; i<listsSize; i++) {
        if(lists[i] != NULL) {
            hn.node = lists[i];
            //printf("hn.node->val = %d\n", hn.node->val);
            enqueue(hn, &q);
        }
    }
    // add root
    hn = dequeue(&q); 
    sortedRoot = hn.node;
    sortedList = sortedRoot;
    
    // sort all lists
    while(q.size > 0) {
        if(sortedList->next != NULL) { // add next node in list
            hn.node = sortedList->next;
            enqueue(hn, &q);
        }
        hn = dequeue(&q); // get min node between all curNodes
        sortedList->next = hn.node;
        sortedList = sortedList->next; // move node
    }
    
    return sortedRoot;
}
