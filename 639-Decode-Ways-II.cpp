class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        vector<long long> num(len + 1);
        num[len] = 1;
        if(s[len - 1] == '0')
            num[len - 1] = 0;
        else if(s[len - 1] == '*')
            num[len - 1] = 9;
        else
            num[len - 1] = 1;
        
        for(int i = len - 2; i >= 0; --i) {
            if(s[i] == '0') {
                num[i] = 0;
            }
            else if(s[i] == '1') {
                if(s[i + 1] == '*')
                    num[i] = num[i + 1] + 9 * num[i + 2];
                else
                    num[i] = num[i + 1] + num[i + 2];
            }
            else if(s[i] == '2') {
                if(s[i + 1] == '*')
                    num[i] = num[i + 1] + 6 * num[i + 2];
                else if(s[i + 1] >= '0' && s[i + 1] <= '6')
                    num[i] = num[i + 1] + num[i + 2];
                else
                    num[i] = num[i + 1];
            }
            else if(s[i] == '*') {
                if(s[i + 1] >= '0' && s[i + 1] <= '6')
                    num[i] = 9 * num[i + 1] + 2 * num[i + 2];
                else if(s[i + 1] == '*')
                    num[i] = 9 * num[i + 1] + 15 * num[i + 2];
                else
                    num[i] = 9 * num[i + 1] + num[i + 2];
            }
            else {
                num[i] = num[i + 1];
            }
            num[i] %= 1000000007;
        }
        return num[0];
    }
};