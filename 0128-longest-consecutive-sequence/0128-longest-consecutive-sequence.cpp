class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int current=0;
        int count=0;
        int mx=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int it:st){
            int num=it;
            if(st.find(num-1)==st.end()){
                count=1;
                current=num;

            }
            while(st.find(current+1)!=st.end()){
                current++;
                count++;
            }
            mx=max(count,mx);
        }
        return mx;


    }
};