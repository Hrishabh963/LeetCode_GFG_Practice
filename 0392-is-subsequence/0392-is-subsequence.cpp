class Solution {
public:
    int f(string s,string t,int i,int j){
        if(i>=s.length() || j>=t.length())return 0;
        if(s[i] == t[j])
            return 1+f(s,t,i+1,j+1);
        return f(s,t,i,j+1);
    }
    bool isSubsequence(string s, string t) {
        return f(s,t,0,0)==s.length();
    }
};