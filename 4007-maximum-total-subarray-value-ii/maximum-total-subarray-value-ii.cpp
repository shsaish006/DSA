class Solution
{
public:
      long long maxTotalValue(vector<int> &a, int k)
      {
            int n = a.size(), lg = 0;
            while ((1 << lg) <= n)
                  lg++;
            vector<vector<int>> mx(lg, vector<int>(n));
            vector<vector<int>> mn(lg, vector<int>(n));
            for (int i = 0; i < n; i++)
                  mx[0][i] = mn[0][i] = a[i];
            for (int j = 1; j < lg; j++)
                  for (int i = 0; i + (1 << j) <= n; i++)
                  {
                        mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
                        mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
                  }
            vector<int> p(n + 1);
            for (int i = 2; i <= n; i++)
                  p[i] = p[i / 2] + 1;

            auto get = [&](int l, int r)
            {
                  int j = p[r - l + 1];
                  return 1LL * max(mx[j][l], mx[j][r - (1 << j) + 1]) -
                         min(mn[j][l], mn[j][r - (1 << j) + 1]);
            };

            priority_queue<array<long long, 3>> q;

            for (int i = 0; i < n; i++)
                  q.push({get(i, n - 1), i, n - 1});

            long long ans = 0;

            while (k--)
            {
                  auto [val, l, r] = q.top();
                  q.pop();

                  ans += val;

                  if (l < r)
                        q.push({get(l, r - 1), l, r - 1});
            }

            return ans;
      }
};