/*
Title: Unrolled Link List

Problem Type: LinkedList

Description: Unrolled link list is a type of LL that is more efficient at searching for elements.
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int blockSize; // max number of nodes in a block

struct ListNode {
    struct ListNode *next;
    int value;
};

struct LinkedBlock {
    struct LinkedBlock *next;
    struct ListNode *head;
    int nodeCount;
};

struct LinkedBlock *blockHead;

struct LinkedBlock *newLinkedBlock() {
    struct LinkedBlock *block = (struct LinkedBlock *)malloc(sizeof(struct LinkedBlock));
    block->next = NULL;
    block->head = NULL;
    block->nodeCount = 0;
    return block;
}

struct ListNode *newListNode(int value) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    temp->value = value;
    return temp;
}

void searchElement(int k, struct LinkedBlock **fLinkedBlock, struct ListNode **fListNode) {
    int j = (k + blockSize - 1) / blockSize; // k-th node is in the j-th block
    struct LinkedBlock *p = blockHead;

    while(--j) {
        p = p->next;
    }

    *fLinkedBlock = p;

    struct ListNode *q = p->head;
    k = k % blockSize;
    if(k == 0) k = blockSize;
    k = p->nodeCount+1-k;
    while(k--) {
        q = q->next;
    }
    *fListNode = q;
}

int main() {
    return 0;
}