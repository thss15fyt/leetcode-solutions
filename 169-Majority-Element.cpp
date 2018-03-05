class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int times = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == majority)
                times++;
            else
                times--;
            if(times < 0) {
                majority = nums[i];
                times = 1;
            }
        }
        return majority;
    }
};