class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left <= right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return vector<int>({left + 1, right + 1});
            else if(sum < target) {
                int l = left, r = right;
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(numbers[mid] + numbers[right] < target)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                left = l;
            }
            else {
                int l = left, r = right;
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(numbers[mid] + numbers[left] > target)
                        r = mid - 1;
                    else
                        l = mid + 1;
                } 
                right = r;
            }
        }
    }
};