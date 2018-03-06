class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k % n - 1);
        reverse(nums, k % n, n - 1);
    }
    void reverse(vector<int>& nums, int left, int right) {
        while(left <= right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
};