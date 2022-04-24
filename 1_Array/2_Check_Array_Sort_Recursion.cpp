/*
Title: Check Sorted Array using Recursion

Problem Type: Recursion

Description: Given an array, we need to write a recursive function to check if the array is in a sorted order.
*/
#include<iostream>
using namespace std;

int isArraySorted(int A[], int n) {
    if(n == 1) {
        return 1;
    }
    return (A[n-1] < A[n-2])?0:isArraySorted(A, n-1);
}

int main() {
    int A[] = {4, 3, 2, 1};

    cout<<"Array:";
    for(int i = 0; i < (int)sizeof(A)/sizeof(A[0]); i++) {
        cout<<A[i]<<' ';
    }
    cout<<endl;
    cout<<isArraySorted(A, 4)<<endl;
    return 0;
}