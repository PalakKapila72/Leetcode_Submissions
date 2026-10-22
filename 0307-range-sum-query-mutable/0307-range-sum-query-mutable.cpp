class NumArray {
public:
    vector<int> nums,bit;
    int n;
    NumArray(vector<int>& nums) {
        this->n=nums.size();
        this->nums=nums;
        this->bit.resize(this->n+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j+=(j&(-j))){
                bit[j]+=nums[i];
            }
        }
    }
    
    void update(int index, int val) {
        int change=val-nums[index];
        int n=nums.size();
        for(int i=index+1;i<=n;i+=(i&-i)){
            bit[i]+=change;
        }
        nums[index]=val;
    }
    int sum(int index){
        int ans=0;
        for(int i=index+1;i>0;i-=(i&(-i))){
            ans+=bit[i];
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */