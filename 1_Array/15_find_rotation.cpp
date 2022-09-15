#include<iostream>
using namespace std;

int findRotation(int arr[], int low, int high) {
    // Base case low > high
    if(arr[high] > arr[low]) {
        return high+1;
    }

    // Find the middle element
    int mid = low + (high - low) / 2;

    // Check if middle is the required element
    if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])) {
        return mid+1;
    }

    if(arr[mid] < arr[low]) {
        return findRotation(arr, low, mid-1);
    } else if(arr[mid] > arr[high]) {
        return findRotation(arr, mid+1, high);
    }
    return -1;
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;

    cout<<findRotation(arr, 0, n-1)<<endl;

    return 0;
}