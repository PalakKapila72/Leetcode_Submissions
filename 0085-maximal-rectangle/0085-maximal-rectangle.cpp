class Solution {
public:
    int largest(vector<int> &nums){
        int maxi=0;
        vector<int> nse=this->nse(nums);
        vector<int> pse=this->pse(nums);
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,(nse[i]-pse[i]-1)*nums[i]);
        }
        return maxi;
    }
    vector<int> nse(vector<int> &nums){
        int n=nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int> &nums){
        int n=nums.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse; 
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                    sum++;
                }
                else{
                    sum=0;
                }
                prefix[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largest(prefix[i]));
        }
        return maxArea;
    }
};