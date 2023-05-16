class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return false;
        vector<int> freq1(26,0),freq2(26,0);
        set<char> s1,s2;
        for(auto ch : word1){
            s1.insert(ch);
            freq1[ch -'a']++;
        }
        for(auto ch : word2){
            s2.insert(ch);
            freq2[ch -'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return (s1==s2 && freq1==freq2);
    }
};