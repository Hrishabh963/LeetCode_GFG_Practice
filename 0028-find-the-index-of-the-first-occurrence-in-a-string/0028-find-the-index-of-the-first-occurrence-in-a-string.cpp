class Solution {
public:
    vector<int> prefix(string s){
        vector<int> pre(s.length());
        int j = 0;
        for(int i = 1; i<s.length(); i++){
            if(s[i]==s[j]){
                pre[i] = j+1;
                j++;
            }
            else if(j==0) pre[i] = 0;
            else{
                j = pre[j-1];
                i--;
            }
        }
        return pre;
    }
    int strStr(string haystack, string needle) {
        vector<int> pre = prefix(needle);
        int i = 0, j = 0;
        while(i<haystack.length()){
            if(haystack[i] == needle[j]){
                i++; j++;
            }
            else{
                if(j!=0) j = pre[j-1];
                else i++;
            }
            if(j == needle.length()){
                return (i - needle.length());
            }
        }
        return -1;
    }
};