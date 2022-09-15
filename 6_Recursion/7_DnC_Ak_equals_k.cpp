/*
Title: Ak = k

Problem Type: Recursion

Description: We need to find if a sorted array with distinct integers has A[k] = k in log(N) time.
*/
#include<iostream>
using namespace std;

bool searchArray(int A[], int left, int right) {
    if(left == right) {
        if(A[left] == left) {
            return true;
        } else {
            return false;
        }
    }
    
    int k = (left + right) / 2;

    if(A[k] == k) {
        return true;
    } else if(A[k] > k) {
        return searchArray(A, left, k);
    } else {
        return searchArray(A, k+1, right);
    }
}

int main() {
    int A[] = {0, 1, 2, 3, 4, 5, 10, 20, 30, 40, 60};
    cout<<searchArray(A, 0, sizeof(A) / sizeof(int)-1)<<endl;
    return 0;
}