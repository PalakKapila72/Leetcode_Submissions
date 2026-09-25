class Solution {
public:
    long long MOD=1e9+7;
    long long power(int x,long long n){
        if(n==0){
            return 1;
        }
        long long half=power(x,n/2);
        if(n%2==0){
            return half*half%MOD;
        }
        return ((x*half%MOD)*half%MOD);
    }
   
    int countGoodNumbers(long long n) {
        long long ans1=power(5,(n+1)/2);
        long long ans2=power(4,n/2);
        return ans1*ans2%MOD;
    }
};