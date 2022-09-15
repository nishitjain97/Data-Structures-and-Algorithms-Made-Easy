#include<iostream>
using namespace std;

void arrange(int arr[], int n) {
    for(int i = 0; i < n-3; i++) {
        int optima = arr[i];
        int optimal_index = i;
        int j = i;
        for(; j < i+3; j++) {
            if(i % 2 == 0) {
                if(arr[j] > optima) {
                    optima = arr[j];
                    optimal_index = j;
                }
            }

            if(i % 2 == 1) {
                if(arr[j] < optima) {
                    optima = arr[j];
                    optimal_index = j;
                }
            }
        }
        swap(arr[i+1], arr[j]);
    }
    return;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;

    arrange(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}