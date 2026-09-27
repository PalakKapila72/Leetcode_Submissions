class Solution {
public:
    void solve(int index,vector<int> current,vector<int> &nums,vector<vector<int>> &ans){
        ans.push_back(current);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            current.push_back(nums[i]);
            solve(i+1,current,nums,ans);
            current.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> current;
        vector<vector<int>> ans;
        solve(0,current,nums,ans);
        return ans;
    }
};