#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.max_size(); i++) {
            for (int j = i; j < nums.max_size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return { i,j };
                }
            }
        }
    }
};