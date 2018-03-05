class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        vector<int> num(len + 1);
        num[len] = 1;
        num[len - 1] = (s[len - 1] == '0') ? 0 : 1;
        for(int i = len - 2; i >= 0; --i) {
            if(s[i] == '0')
                num[i] = 0;
            else if(s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
                num[i] = num[i + 1] + num[i + 2];
            else
                num[i] = num[i + 1];
        }
        return num[0];
    }
};