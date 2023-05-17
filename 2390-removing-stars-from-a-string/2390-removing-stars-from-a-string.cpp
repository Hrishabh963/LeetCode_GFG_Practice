class Solution {
public:
    string removeStars(string s) {
        string c="";
        for(auto it : s){
            if(it == '*'){
                c.pop_back();
            }
            else c.push_back(it);
        }
        return c;
    }
};