#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& a) {
        double b = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double c = abs((a[j][0] - a[i][0]) * (a[k][1] - a[i][1]) - (a[k][0] - a[i][0]) * (a[j][1] - a[i][1])) / 2.0;
                    b = max(b, c);
                }
            }
        }
        return b;
    }};