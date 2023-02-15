class Solution {
public:
    string reverseWords(string &s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            int c = i;
            while (i < s.length() && s[i] != ' ') i++;
            if (str.length() > 0) str = ' ' + str;
            str = s.substr(c, i - c) + str;
            i--;
        }
        return str;
    }
};