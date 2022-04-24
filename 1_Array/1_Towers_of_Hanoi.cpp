/*
Title: Towers of Hanoi

Problem Type: Recursion

Description: In this problem, we have 3 pegs (A, B, C) and a set of N rings on peg A increasing in size from top to bottom. We need to move these rings from peg A to peg C using peg B as an auxiliary peg, while constrained by the following rules:
    - Move only 1 ring at a time
    - No larger ring can be put on top a relatively smaller ring
*/
#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char frompeg, char topeg, char auxpeg) {
    // When only 1 disk is left, make the move and return from function
    if(n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }

    // Move top n-1 disks from A to B, using C as auxiliary
    TowerOfHanoi(n-1, frompeg, auxpeg, topeg);

    // Move remaining disks from A to C
    printf("Move disk %d from peg %c to peg %c\n", n, frompeg, topeg);

    // Move n-1 disks from B to C, using A as auxiliary
    TowerOfHanoi(n-1, auxpeg, topeg, frompeg);
}

int main() {
    TowerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}