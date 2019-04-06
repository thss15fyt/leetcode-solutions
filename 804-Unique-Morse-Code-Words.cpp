class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string Morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int num = 0;
        map<string, bool> strmap;
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            string code = "";
            int len = words[i].size();
            for(int j = 0; j < len; ++j)
                code += Morse[words[i][j] - 'a'];
            if(strmap.find(code) == strmap.end()) {
                num++;
                strmap[code] = true;
            }
        }
        return num;
    }
};