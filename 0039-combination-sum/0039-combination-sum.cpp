class Solution {
public:
    void solve(int index,int target,vector<int> current,vector<int> &candidates,vector<vector<int>> &ans){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(current);
            }
            return;
        }
        if(candidates[index]<=target){
            current.push_back(candidates[index]);
            solve(index,target-candidates[index],current,candidates,ans);
            current.pop_back();
        }
        solve(index+1,target,current,candidates,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;
        solve(0,target,current,candidates,ans);
        return ans;
        
    }
};