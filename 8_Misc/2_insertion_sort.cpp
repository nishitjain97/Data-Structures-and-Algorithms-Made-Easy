#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int cur_element;
    int j;

    for(int i = 1; i < n; i++) {
        cur_element = arr[i];
        j = i - 1;
        while((cur_element < arr[j]) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = cur_element;
    }
    return;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return;
}

int main() {
    int input_arr[] = {1, 3, 2, 7, 8, 5, 10};
    int n = sizeof(input_arr) / sizeof(int);

    printArray(input_arr, n);
    insertionSort(input_arr, n);
    printArray(input_arr, n);

    return 0;
}