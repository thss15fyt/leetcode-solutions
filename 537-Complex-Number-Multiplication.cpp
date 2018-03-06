class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        parseComplex(a, a1, b1);
        parseComplex(b, a2, b2);
        int a3 = a1 * a2 - b1 * b2;
        int b3 = a1 * b2 + a2 * b1;
        return getComplex(a3, b3);
    }
    void parseComplex(string s, int& a, int& b) {
        int split;
        for(split = 0; split < s.size(); ++split)
            if(s[split] == '+')
                break;
        a = std::stoi(s.substr(0, split), nullptr, 10);
        b = std::stoi(s.substr(split + 1, s.size() - split - 1), nullptr, 10);
    }
    string getComplex(int a, int b) {
        return std::to_string(a) + "+" + std::to_string(b) + "i";
    }
};