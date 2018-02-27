class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int current_len = 1;
        int max_len = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1]) {
                current_len++;
                if(current_len > max_len)
                    max_len = current_len;
            }
            else {
                current_len = 1;
            }
        }
        return max_len;
    }
};