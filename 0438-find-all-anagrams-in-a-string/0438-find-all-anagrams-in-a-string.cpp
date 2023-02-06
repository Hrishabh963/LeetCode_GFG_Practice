class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> p2,s2;
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            p2[p[i]]++;  // adding p string to hash
            s2[s[i]]++;  // adding s string to hash of size p
            
        }
        if(p2 == s2) ans.push_back(0); // checking for index 0
        int j=0; //slide 
        for(int i=p.size();i<s.size();i++){
            s2[s[i]]++; 
            s2[s[j]]--;
            if(s2[s[j]] == 0) s2.erase(s[j]);
            j++;
            if(p2 == s2) ans.push_back(j);

        }

        return ans;
    }
};