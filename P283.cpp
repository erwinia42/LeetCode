#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int stop = nums.size();
        for(int i = 0; i < stop; i++){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                stop--;
                i--;
            }
        }
    }
};
