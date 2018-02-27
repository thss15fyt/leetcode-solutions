class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1;
        int dominant = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > max) {
                if(nums[i] >= 2 * max) {
                    dominant = i;
                }
                else {
                    dominant = -1;
                }
                max = nums[i];
            }
            else {
                if(max < 2 * nums[i]) {
                    dominant = -1;
                }
            }
        }
        return dominant;
    }
};