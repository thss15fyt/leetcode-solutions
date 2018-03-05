class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for(int i = 0; i <= rowIndex; ++i) {
            int last = result[0];
            for(int j = 1; j <= i / 2; ++j) {
                int temp = last + result[j];
                last = result[j];
                result[j] = temp;
            }
            for(int j = (i / 2) + 1; j < i; ++j)
                result[j] = result[i - j];
        }
        return result;
    }
};