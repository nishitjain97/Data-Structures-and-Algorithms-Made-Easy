/*
Title: All Strings of Length N Drawn From 0...k

Problem Type: Backtracking

Description: All possible combinations of 0...k that can be created of size N
*/
#include<iostream>
using namespace std;

const int N = 3;
const int K = 5;
char A[N];

void k_string(int n, int k) {
    if(n < 1) {
        printf("%s\n", A);
    } else {
        for(int j = 0; j < k; j++) {
            A[n-1] = to_string(j)[0];
            k_string(n-1, k);
        }
    }
}

int main() {
    k_string(N, K);
    return 0;
}