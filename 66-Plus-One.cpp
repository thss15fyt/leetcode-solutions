class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = 0;
        for(i = digits.size() - 1; i >= 0; --i) {
            digits[i] += 1;
            if(digits[i] >= 10)
                digits[i] -= 10;
            else
                break;
        }
        if(i < 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};