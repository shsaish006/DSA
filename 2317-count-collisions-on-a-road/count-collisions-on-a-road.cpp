class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l < n && s[l] == 'L') l++;
        while (r >= 0 && s[r] == 'R') r--;

        if (l > r) return 0; 

        int still = 0;
        for (int i = l; i <= r; i++)
            if (s[i] == 'S') still++;

        return (r - l + 1) - still;
    }
};