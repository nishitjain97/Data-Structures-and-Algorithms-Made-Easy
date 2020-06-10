#include <iostream>

using namespace std;

int isArrayInSortedOrder(int A[], int n) {
    if(n == 1) return 1;

    return(A[n-1] < A[n-2])?0:isArrayInSortedOrder(A, n-1);
}

int main() {
    
    int temp[] = {1, 3, 4, 2};

    cout<<isArrayInSortedOrder(temp, 4)<<endl;
    return 0;
}