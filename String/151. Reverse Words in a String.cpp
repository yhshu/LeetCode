class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for (int i = s.size() - 1; i >= 0; ) {
            if(s[i] == ' ') {
                i--;
                continue;
            }
            string word = "";
            int j = i;
            for (; j >= 0 && s[j] != ' '; j--) {
                word = s[j] + word;
            }
            res += word + " ";
            i = j - 1;
        }
        if (res[res.size() - 1] == ' ') 
            res.pop_back();
        return res;
    }
};
