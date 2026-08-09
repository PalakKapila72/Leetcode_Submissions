class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=m-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top<=bottom && left<=right){
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }}
            right--;
            if(left<=right && top<=bottom){
            for(int w=right;w>=left;w--){
                ans.push_back(matrix[bottom][w]);
            }}
            bottom--;
            if(bottom>=top && left<=right){
            for(int k=bottom;k>=top;k--){
                ans.push_back(matrix[k][left]);
            }}
            left++;
           
        }
        return ans;
    }
};