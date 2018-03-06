class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end = 0;
        while(begin < s.size() && end < s.size()) {
            while(s[end] != ' ' && end < s.size())
                end++;
            reverse(s, begin, end - 1);
            begin = end = end + 1;
        }
        return s;
    }
    void reverse(string& s, int begin, int end) {
        for(int i = begin; i < begin + (end - begin + 1) / 2; ++i) {
            char temp = s[i];
            s[i] = s[begin + end - i];
            s[begin + end - i] = temp;
        }
    }
};