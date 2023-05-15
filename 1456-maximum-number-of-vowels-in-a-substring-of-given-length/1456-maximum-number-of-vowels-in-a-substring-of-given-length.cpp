class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st{'a','e','i','o','u'};
        int count = 0;
        int maxi = 0;
        for(int i = 0; i<s.length(); i++){
            if(st.count(s[i]))
                count++;
            if(i>=k && st.count(s[i-k])){
                count--;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};