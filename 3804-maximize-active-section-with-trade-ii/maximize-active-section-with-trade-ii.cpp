class SegmentTree {
public:
    int n;
    vector<int> a, seg;

    SegmentTree(vector<int> &nums) {
        a = nums;
        n = a.size();
        seg.assign(4 * max(1, n), 0);
        if (n) build(1, 0, n - 1);
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    int dfs(int idx, int l, int r, int s, int e) {
        if (s <= l && r <= e) return seg[idx];
        int mid = (l + r) / 2;
        int val = 0;
        if (mid >= s) val = max(val, dfs(idx * 2, l, mid, s, e));
        if (e > mid) val = max(val, dfs(idx * 2 + 1, mid + 1, r, s, e));
        return val;
    }

    int query(int l, int r) {
        if (l > r || n == 0) return 0;
        return dfs(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int seg;

    int lowerBound(vector<int> &a, int val) {
        int l = 0, r = seg;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= val) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int upperBound(vector<int> &a, int val) {
        int l = 0, r = seg;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] <= val) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        int n = s.size();
        int cnt = 0;
        for (char c : s) if (c == '1') cnt++;

        vector<int> vals, a, b;
        int idx = 0;
        while (idx < n) {
            int nxt = idx;
            while (nxt < n && s[idx] == s[nxt]) nxt++;
            if (s[idx] == '0') {
                vals.push_back(nxt - idx);
                a.push_back(idx);
                b.push_back(nxt - 1);
            }
            idx = nxt;
        }

        int m = vals.size();
        seg = m;
        vector<int> ans;

        if (m <= 1) {
            for (int i = 0; i < q.size(); i++) ans.push_back(cnt);
            return ans;
        }

        vector<int> nums(m - 1);
        for (int i = 0; i < m - 1; i++) nums[i] = vals[i] + vals[i + 1];

        SegmentTree o(nums);

        for (int i = 0; i < q.size(); i++) {
            int l = q[i][0], r = q[i][1];

            int idx1 = lowerBound(b, l);
            int idx2 = upperBound(a, r) - 1;

            if (idx1 > m - 1 || idx2 < 0 || idx1 >= idx2) {
                ans.push_back(cnt);
                continue;
            }

            int curr = b[idx1] - max(a[idx1], l) + 1;
            int temp = min(r, b[idx2]) - a[idx2] + 1;

            if (idx1 + 1 == idx2) {
                ans.push_back(cnt + curr + temp);
                continue;
            }

            int val = curr + vals[idx1 + 1];
            int upd = temp + vals[idx2 - 1];
            int nums = o.query(idx1 + 1, idx2 - 2);

            ans.push_back(cnt + max(val, max(upd, nums)));
        }

        return ans;
    }
};