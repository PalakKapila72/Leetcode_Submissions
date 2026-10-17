class Solution {
public:
    vector<int> nse(vector<int> &nums){
        int n=nums.size();
        vector<int> nse(n);
        vector<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.back()]>=nums[i]){
                st.pop_back();
            }
            nse[i]=st.empty()?n:st.back();
            st.push_back(i);
        }
        return nse;
    }
    vector<int> psee(vector<int> &nums){
        int n=nums.size();
        vector<int> psee(n);
        vector<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.back()]>nums[i]){
                st.pop_back();
            }
            psee[i]=st.empty()?-1:st.back();
            st.push_back(i);
        }
        return psee;
    }
    vector<int> nge(vector<int> &nums){
        int n=nums.size();
        vector<int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.back()]<=nums[i]){
                st.pop_back();
            }
            nge[i]=st.empty()?n:st.back();
            st.push_back(i);
        }
        return nge;
    }
    vector<int> pgee(vector<int> &nums){
        int n=nums.size();
        vector<int> st;
        vector<int> pgee(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.back()]<nums[i]){
                st.pop_back();
            }
            pgee[i]=st.empty()?-1:st.back();
            st.push_back(i);
        }
        return pgee;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nse(n);
        vector<int> psee(n);
        vector<int> nge(n);
        vector<int> pgee(n);
        nse=this->nse(nums);
        psee=this->psee(nums);
        pgee=this->pgee(nums);
        nge=this->nge(nums);
        long long summax=0;
        long long summin=0;
        for(int i=0;i<n;i++){
            long long leftmin=i-psee[i];
            long long rightmin=nse[i]-i;
            summin=summin+leftmin*rightmin*nums[i];
            long long leftmax=i-pgee[i];
            long long rightmax=nge[i]-i;
            summax=summax+leftmax*rightmax*nums[i];

        }
        return summax-summin;
    }
};