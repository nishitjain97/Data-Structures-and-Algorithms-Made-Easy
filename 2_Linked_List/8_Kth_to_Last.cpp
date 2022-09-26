#include<iostream>
using namespace std;
struct node {
    int val;
    node* next;
};

node* createNode(int val) {
    struct node* newNode = new node();
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

node* addNode(struct node* head, int val) {
    node* newNode = createNode(val);

    if(head == NULL) {
        head = newNode;
    } else {
        struct node* itr = head;
        while(itr->next != NULL) {
            itr = itr->next;
        }
        itr->next = newNode;
    }
    return head;
}

void printNodes(struct node* head) {
    struct node* itr = head;

    while(itr != NULL) {
        cout<<itr->val<<' ';
        itr = itr->next;
    }
    cout<<endl;
    return;
}

int nthToLast1(struct node* head, int n) {
    if(head == NULL) {
        return 0;
    }
    int ind = nthToLast1(head->next, n) + 1;
    if(ind == n) {
        cout<<"Found: "<<head->val<<endl;
    }
    return ind;
}

node* nthToLast2(struct node* head, int n, int& i) {
    if(head == NULL) {
        return NULL;
    }
    node* nd = nthToLast2(head->next, n, i);
    i = i + 1;
    if(i == n) {
        return head;
    }
    return nd;
}

node* nthToLast3(struct node* head, int n) {
    struct node* p1 = head;

    for(int i = 0; i < n; i++) {
        if(p1 == NULL) {
            return NULL;
        }
        p1 = p1->next;
    }

    struct node* p2 = head;
    while(p1 != NULL) {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p2;
}

int main() {
    struct node* head = NULL;
    for(int i = 1; i <= 10; i++) {
        head = addNode(head, i);
    }
    printNodes(head);

    // nthToLast1(head, 11);
    // int i = 0;
    // cout<<"Found: "<<nthToLast2(head, 1, i)->val<<endl;
    cout<<"Found: "<<nthToLast3(head, 1)->val<<endl;

    return 0;
}