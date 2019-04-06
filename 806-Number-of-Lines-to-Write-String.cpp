class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int current_line = 0;
        int line_used = 0;
        for(int i = 0; i < S.size(); ++i) {
            int width = widths[S[i] - 'a'];
            if(line_used + width <= 100) {
                line_used += width;
            }
            else {
                current_line++;
                line_used = width;
            }
        }
        vector<int> ans;
        ans.push_back(current_line + 1);
        ans.push_back(line_used);
        return ans;
    }
};