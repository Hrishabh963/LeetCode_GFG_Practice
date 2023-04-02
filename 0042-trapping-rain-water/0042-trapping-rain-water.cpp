class Solution {
public:
    int trap(vector<int>& h) {
        int lmax = 0,rmax = 0,water = 0;
        vector<int> lsum(h.size(),0),rsum(h.size(),0);
        for(int i = 1; i<h.size(); i++){
            if(h[i-1]>lmax)
                lmax = h[i-1];
            lsum[i] = lmax;
        }
        for(int i = h.size()-2; i>=0; i--){
            if(h[i+1]>rmax)
                rmax = h[i+1];
            rsum[i] = rmax;
        }
        for(int i = 1; i<h.size()-1; i++){
            int mini = min(lsum[i],rsum[i]);
            if(mini>h[i])
                water+=mini-h[i];
        }
        return water;
    }
};