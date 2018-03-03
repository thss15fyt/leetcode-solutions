class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxSum;
        if(nums.size() == 0)
            return INT_MIN;
        maxSum.push_back(nums[0]);
        int max = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(maxSum[i - 1] <= 0)
                maxSum.push_back(nums[i]);
            else
                maxSum.push_back(maxSum[i - 1] + nums[i]);
            if(maxSum[i] > max)
                max = maxSum[i];
        }
        return max;
    }
};