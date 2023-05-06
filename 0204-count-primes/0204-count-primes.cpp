
class Solution {
public:
    int calcPrime(int n){
        vector<long> currPrimes(n,true);
        currPrimes[0] = false;
        currPrimes[1] = false;
        int curr = 0;
        for(int i = 2; i*i<n; i++){
            if(currPrimes[i]){
                for(int j = 2*i; j<n; j+=i){
                    currPrimes[j] = 0;
                }
            }
        }
        for(auto it : currPrimes){
            if(it)curr++;
        }
        return curr;
    }
    int countPrimes(int n) {
        if(n==0)return 0;
        if(n==1)return 0;
        return calcPrime(n);
    }
};