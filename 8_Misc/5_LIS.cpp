#include<iostream>
using namespace std;

int LIS(int arr[], int n) {
    int* counts = new int[n];
    int* previous = new int[n];
    counts[0] = 0;
    int max_size;
    int prev_element;

    for(int i = 0; i < n; i++) {
        max_size = 0;
        prev_element = i;

        for(int j = 0; j < i; j++) {

            if((arr[j] < arr[i]) && (counts[j] > max_size)) {
                max_size = counts[j];
                prev_element = j;
            }
        }
        counts[i] = max_size + 1;
        previous[i] = prev_element;
    }

    max_size = 0;
    prev_element = 0;

    for(int i = 0; i < n; i++) {
        if(counts[i] > max_size) {
            max_size = counts[i];
            prev_element = i;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout<<previous[i]<<' ';
    }
    cout<<endl;
    
    int i = prev_element;
    while(previous[i] != i) {
        cout<<arr[i]<<' ';
        i = previous[i];
    }
    cout<<arr[i]<<endl;
    return max_size;
}

int main() {
    int arr[] = {5, 2, 8, 6, 3, 6, 9, 7};
    int n = sizeof(arr) / sizeof(int);
    cout<<LIS(arr, n)<<endl;
    return 0;
}