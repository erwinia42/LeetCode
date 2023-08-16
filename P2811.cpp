#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() <= 2){
            return true;
        }
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] + nums[i+1] >= m){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution solver;
    vector<int> nums = {38, 96, 25, 55, 62, 62, 58, 55, 4, 32, 35, 100, 12, 87, 16, 55, 16, 53, 77, 57, 44, 87, 23};
    bool temp = solver.canSplitArray(nums, 143);
    cout << temp;
}
