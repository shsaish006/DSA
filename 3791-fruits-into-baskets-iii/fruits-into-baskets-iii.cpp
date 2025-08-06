class SegmentTree {
private:
    vector<int> tree;
    vector<int> data;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start - 1]; // 1-based to 0-based adjustment
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int index, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid)
                update(2 * node, start, mid, index, value);
            else
                update(2 * node + 1, mid + 1, end, index, value);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int findFirstFit(int node, int start, int end, int required) {
        if (tree[node] < required) return -1;
        if (start == end) return start;

        int mid = (start + end) / 2;
        if (tree[2 * node] >= required)
            return findFirstFit(2 * node, start, mid, required);
        else
            return findFirstFit(2 * node + 1, mid + 1, end, required);
    }

public:
    SegmentTree(const vector<int>& input) {
        data = input;
        n = input.size();
        tree.resize(4 * n);
        build(1, 1, n);
    }

    int query(int required) {
        return findFirstFit(1, 1, n, required);
    }

    void modify(int index, int value) {
        update(1, 1, n, index, value);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree segTree(baskets);
        int n = baskets.size();
        int unplaced = 0;

        for (int fruit : fruits) {
            int index = segTree.query(fruit);
            if (index == -1) {
                unplaced++;
            } else {
                segTree.modify(index, 0); // Mark basket as used
            }
        }

        return unplaced;
    }
};
