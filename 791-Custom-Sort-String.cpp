class Solution {
public:
    string customSortString(string S, string T) {
        int order[26] = {0};
        for(int i = 0; i < S.size(); ++i)
            order[S[i] - 'a'] = i;
        int n = T.size();
        for(int i = 0; i < n - 1; ++i) {
            for(int j = 0; j < n - i - 1; ++j) {
                if(order[T[j] - 'a'] > order[T[j + 1] - 'a']) {
                    char temp = T[j];
                    T[j] = T[j + 1];
                    T[j + 1] = temp;
                }    
            }    
        }
        return T;
    }
};