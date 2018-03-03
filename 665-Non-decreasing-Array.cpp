class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        int len = nums.size() - 1;
        for(int i = 0; i < len; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(modified)
                    return false;
                modified = true;
                if(i != 0 && nums[i + 1] < nums[i - 1])
                    nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};