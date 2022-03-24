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