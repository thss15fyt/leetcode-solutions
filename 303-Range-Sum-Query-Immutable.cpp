class NumArray {
private:
    vector<int> Sum;
public:
    NumArray(vector<int> nums) {
        if(nums.size() > 0)
            Sum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
            Sum.push_back(Sum[i - 1] + nums[i]);
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return Sum[j];
        else
            return Sum[j] - Sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */