class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        
        int diff = sum;   // diff = rightSum - leftSum
        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0)
                diff = diff - nums[i];
            else
                diff = diff - nums[i - 1] - nums[i];
            if(diff == 0)
                return i;         
        }
        return -1;
    }
};