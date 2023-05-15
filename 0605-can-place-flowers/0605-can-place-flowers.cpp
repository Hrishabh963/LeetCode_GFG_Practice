class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int count = 0;
        for(int i = 0; i<f.size(); i++){
            if(f[i]==0)
            {int prev = (i==0 || f[i-1]==0);
            int next = (i==f.size()-1 || f[i+1]==0);
            if(prev&&next){
                f[i] = 1;
                count++;
            }
            }
        }
        return count>=n;
    }
};