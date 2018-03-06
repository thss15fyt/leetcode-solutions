class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        while(nums[p] != 0)
            p++;
        int q = p + 1;
        while(q < nums.size()) {
            if(nums[q] != 0) {
                nums[p] = nums[q];
                p++;
                nums[q] = 0;
            }
            q++;
        }
    }
};