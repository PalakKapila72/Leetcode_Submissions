class Solution {
public:
    void solve(int index,vector<int> current,vector<int> &nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(current);
            return;
        }
        //take
        current.push_back(nums[index]);
        solve(index+1,current,nums,ans);
        current.pop_back();
        //not take
        solve(index+1,current,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,{},nums,ans);
        return ans;
    }
};