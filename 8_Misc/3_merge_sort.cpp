#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return;
}

void merge(int arr[], int start, int mid, int end) {
    int left[mid - start + 1];
    int right[end - mid];

    int itr = 0;
    for(int i = start; i <= mid; i++) {
        left[itr] = arr[i];
        itr++;
    }

    itr = 0;
    for(int i = mid+1; i <= end; i++) {
        right[itr] = arr[i];
        itr++;
    }
    
    int left_itr = 0;
    int right_itr = 0;
    itr = 0;
    while((left_itr <= (mid - start)) && (right_itr < (end-mid))) {
        if(left[left_itr] < right[right_itr]) {
            arr[itr] = left[left_itr];
            left_itr++;
        } else {
            arr[itr] = right[right_itr];
            right_itr++;
        }
        itr++;
    }

    printArray(arr, end - start + 1);

    while(left_itr <= (mid-start)) {
        arr[itr] = left[left_itr];
        itr++;
        left_itr++;
    }

    while(right_itr < (end - mid)) {
        arr[itr] = right[right_itr];
        itr++;
        right_itr++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if(end <= start) {
        return;
    }

    int mid = start + (end - start) / 2;

    // mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

int main() {
    int arr[] = {1, 3, 5, 2, 8, 4};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}