/*
Title: Generate All Binary Strings of Size N

Problem Type: Backtracking

Description: Given an integer N, generate all possible binary strings (made of 0 and 1) of size N.

Assumption: Array given to function is a global array.
*/
#include<iostream>
using namespace std;

const int N = 5;
char A[N];

void Binary(int n) {
    if(n < 1) {
        printf("%s\n", A);
    } else {
        A[n-1] = '0';
        Binary(n-1);
        A[n-1] = '1';
        Binary(n-1);
    }
}

int main() {
    for(int i = 0; i < N; i++) {
        A[i] = '0';
    }

    Binary(N);
    return 0;
}