class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        set<int> s;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: mp){
            s.insert(it.second);
        }
      return s.size() == mp.size();
    }
};