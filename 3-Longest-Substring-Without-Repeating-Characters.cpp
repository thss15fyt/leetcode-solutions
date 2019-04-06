class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int max_len = 0;
        int i = 0, j = 0;
        map<char, int> inCurrent;
        while(j < n) {
            if(inCurrent.find(s[j]) != inCurrent.end() && inCurrent[s[j]] >= 0) {
                int len = j - i;
                max_len = len > max_len ? len : max_len;
                int last_pos = inCurrent[s[j]];
                for(int k = last_pos; k >= i; --k) {
                    inCurrent[s[k]] = -1;
                }
                i = last_pos + 1;
                inCurrent[s[j]] = j;
            }
            else {
                inCurrent[s[j]] = j;
             }
            ++j;
        }
        int len = j - i;
        max_len = len > max_len ? len : max_len;
        return max_len;
    }
};