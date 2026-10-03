class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int sum=lsum;
        int j=n;
        while(k>0){
            lsum-=cardPoints[k-1];
            rsum+=cardPoints[j-1];
            k--;
            j--;
            sum=max(sum,lsum+rsum);

        }
        return sum;
    }
};