class NumArray {
public:
    vector<int> seg;
    int n;

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid, nums);
        build(2 * idx + 2, mid + 1, r, nums);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateTree(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            updateTree(2 * idx + 1, l, mid, pos, val);
        else
            updateTree(2 * idx + 2, mid + 1, r, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        // complete overlap
        if (ql <= l && r <= qr)
            return seg[idx];

        // no overlap
        if (r < ql || l > qr)
            return 0;

        int mid = (l + r) / 2;

        return query(2 * idx + 1, l, mid, ql, qr) +
               query(2 * idx + 2, mid + 1, r, ql, qr);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
