#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int forward_product = 1, backward_product = 1;
        int length = nums.size();
        int max_product = nums[0];
        
        for(int i = 0; i < length; i++) {
            forward_product *= nums[i];
            backward_product *= nums[length - 1 - i];
            max_product = max(max_product, max(forward_product, backward_product));
            
            if(forward_product == 0) {
                forward_product = 1;
            }
            if(backward_product == 0) {
                backward_product = 1;
            }
        }
        
        return max_product;
    }
};