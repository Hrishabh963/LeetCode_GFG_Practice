class Solution {
public:
    double power(double x,int n){
        if(n==0) return double(1.0);
        double temp = power(x,n/2);
        if(n%2 == 0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
    }
    double myPow(double x, int n) {
        long nn = n;
        if(nn<0) nn = -1*nn;
        double ans = power(x,nn);
        // double ans = 1.0;
        // while(nn){
        //     if(nn%2 == 1){
        //         ans = ans*x;
        //         nn = nn-1;
        //     }
        //     else{
        //         x = x*x;
        //         nn = nn/2;
        //     }
        // }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};