#include<vector>
#include<iostream>
using namespace std;

void missingAndRepeating();

int main() {
    missingAndRepeating();
    return 0;
}

void missingAndRepeating()
{
    int n = 10;
    int a[] = {4, 5, 2, 9, 8, 1, 1, 7, 10, 3};
  
    vector<int> arr(a, a + n);
    arr.insert(arr.begin(), 0);

    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    
    int slow = arr[1];
    int fast = arr[1];
    
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];

        cout<<slow<<' '<<fast<<endl;
    } while(slow != fast);
    
    fast = arr[1];
    
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    cout<<slow<<' '<<fast<<endl;

    int expected_sum = n * (n+1) / 2;
    int current_sum = 0;
    
    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
    }
    
    int diff;
    
    if(current_sum > expected_sum) {
        diff = current_sum - expected_sum;
    } else {
        diff = expected_sum - current_sum;
    }
    
    int missing = slow - diff;
    
    cout<<missing<<' '<<slow<<endl;
}