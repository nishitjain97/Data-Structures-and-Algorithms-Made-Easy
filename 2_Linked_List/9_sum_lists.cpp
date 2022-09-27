#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* createNode(int val) {
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode* addNode(ListNode* head, int val) {
    ListNode* newNode = createNode(val);

    if(head == NULL) {
        head = newNode;
    } else {
        ListNode* itr = head;
        while(itr->next != NULL) {
            itr = itr->next;
        }
        itr->next = newNode;
    }
    return head;
}

void printNodes(ListNode* head) {
    ListNode* itr = head;
    while(itr->next != NULL) {
        cout<<itr->val<<"->";
        itr = itr->next;
    }
    if(itr != NULL) {
        cout<<itr->val<<endl;
    }
    return;
}

ListNode* addLists(ListNode* l1, ListNode* l2, int carry) {
    if(l1 == NULL && l2 == NULL && carry == 0) {
        return NULL;
    }

    int cur_sum = carry;
    if(l1 != NULL) {
        cur_sum += l1->val;
    }
    if(l2 != NULL) {
        cur_sum += l2->val;
    }

    ListNode* newNode = createNode(cur_sum % 10);

    if(l1 != NULL || l2 != NULL) {
        newNode->next = addLists(
            l1 == NULL ? NULL: l1->next,
            l2 == NULL ? NULL: l2->next,
            cur_sum >= 10 ? 1 : 0
        );
    }
    return newNode;
}

int main() {
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    l1 = addNode(l1, 6);
    l1 = addNode(l1, 1);
    l1 = addNode(l1, 7);

    l2 = addNode(l2, 2);
    l2 = addNode(l2, 9);
    l2 = addNode(l2, 5);

    ListNode* sumList = addLists(l1, l2, 0);
    printNodes(sumList);
    return 0;
}