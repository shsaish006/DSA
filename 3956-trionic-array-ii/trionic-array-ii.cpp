// class Solution {
// public:
//     long long maxSumTrionic(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = LLONG_MIN;
//         int i = 0;
//         while(i < n) {
//             int l = i;
//             i++;
//             while(i < n && nums[i-1] < nums[i]) i++;
//             if(i == l+1) continue;

//             int peak = i-1;
//             long long s = nums[peak-1] + nums[peak];

//             while(i < n && nums[i-1] > nums[i]) {
//                 s += nums[i];
//                 i++;
//             }
//             if(i == peak+1 || i == n) continue;

//             int q = i-1;
//             s += nums[i]; 
//             i++;

//             long long mx_right = 0, t = 0;
//             while(i < n && nums[i-1] < nums[i]) {
//                 t += nums[i];
//                 mx_right = max(mx_right, t);
//                 i++;
//             }
//             s += mx_right;

//             long long mx_left = 0;
//             t = 0;
//             for(int j = peak-2; j >= l; j--) {
//                 t += nums[j];
//                 mx_left = max(mx_left, t);
//             }
//             s += mx_left;

//             ans = max(ans, s);
//             i = q;
//         }
//         return ans;
//     }
// };
// TC 857/858
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = LLONG_MIN;
        while (i < n) {
            int l = i;
            i++;
            while (i < n && nums[i-1] < nums[i]) i++;
            if (i == l + 1) continue;

            int p = i - 1;
            long long s = nums[p-1] + nums[p];
            while (i < n && nums[i-1] > nums[i]) {
                s += nums[i];
                i++;
            }
            if (i == p + 1 || i == n || nums[i-1] == nums[i]) continue;

            int q = i - 1;
            s += nums[i];
            i++;

            long long mx = 0, t = 0;
            while (i < n && nums[i-1] < nums[i]) {
                t += nums[i];
                mx = max(mx, t);
                i++;
            }
            s += mx;

            mx = 0;
            t = 0;
            for (int j = p - 2; j >= l; j--) {
                t += nums[j];
                mx = max(mx, t);
            }
            s += mx;

            ans = max(ans, s);
            i = q;
        }
        return ans;
    }
    };
