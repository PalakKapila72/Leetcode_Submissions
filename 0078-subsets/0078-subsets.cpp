class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index,vector<int> current,vector<int> &nums){
        if(index==nums.size()){
            ans.push_back(current);
            return;
        }
        //take
        current.push_back(nums[index]);
        solve(index+1,current,nums);
        current.pop_back();
        //not take
        solve(index+1,current,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,{},nums);
        return ans;
    }
};