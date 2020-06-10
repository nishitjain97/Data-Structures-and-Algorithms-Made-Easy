#include<iostream>

using namespace std;

void TowersOfHanoi(int n, char frompeg, char topeg, char auxpeg) {
    if(n == 1) {
        /* Exit condition, for 1 disk */
        printf("\nMove disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }

    /* Move top n-1 disks from A to B, using C as auxiliary */
    TowersOfHanoi(n-1, frompeg, auxpeg, topeg);

    /* Move remaining disks from A to C */
    printf("\nMove disk %d from peg %c to peg %c", n, frompeg, topeg);

    /* Move n-1 disks from B to C using A as auxiliary */
    TowersOfHanoi(n-1, auxpeg, topeg, frompeg);
}

int main() {
	TowersOfHanoi(5, 'A', 'B', 'C');
}
