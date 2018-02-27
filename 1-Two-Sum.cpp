#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> nummap;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0) {
                if(nummap.find(target - nums[i]) != nummap.end()) {
                    ans.push_back(nummap[target - nums[i]]);
                    ans.push_back(i);
                    break;
                }
            }
            nummap[nums[i]] = i;
        }
        return ans;
    }
};