class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int r = 0;
        unordered_map<char,int> m;
        int ans  = 0;
        while(r<s.length()){
            if(m.find(s[r])!=m.end())
                l = max(m[s[r]]+1,l);
            m[s[r]] = r;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};