#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (3154) Find Number of Ways to Reach the K-th Stair

class Solution
{
public:
    vector<long long> power;
    unordered_map<string, int> mp;
    int solve(int i, int jump, int canjumpback, int k)
    {
        if (i > k + 1)
        {
            return 0;
        }

        string key =
            to_string(i) + "_" + to_string(jump) + "_" + to_string(canjumpback);
        if (mp.count(key))
        {
            return mp[key];
        }
        int ways = 0;
        if (i == k)
        {
            ways += 1;
        }

        if (canjumpback)
        {
            ways += solve(i - 1, jump, 0, k);
        }

        ways += solve((i + power[jump]), jump + 1, 1, k);

        return mp[key] = ways;
    }

    int waysToReachStair(int k)
    {
        power.resize(32);
        for (int i = 0; i <= 31; i++)
        {
            power[i] = pow(2, i);
        }
        int canjumpback = 1;
        return solve(1, 0, canjumpback, k);
    }
};

// Qs.2-> Brackets in Matrix Chain Multiplication(gfg)

class Solution
{

public:
    unordered_map<string, pair<string, int>> mp;
    pair<string, int> mcm(vector<int> arr, int i, int j)
    {
        if (i == j)
        {
            string s = "";
            s += 'A' + i - 1;
            return {s, 0};
        }

        string key = to_string(i) + "_" + to_string(j);
        if (mp.count(key))
        {
            return mp[key];
        }
        int mincost = INT_MAX;
        string str = "";

        for (int k = i; k < j; k++)
        {
            auto cost1 = mcm(arr, i, k);
            auto cost2 = mcm(arr, k + 1, j);
            int currcost = cost1.second + cost2.second + (arr[i - 1] * arr[k] * arr[j]);
            if (currcost < mincost)
            {
                str = '(' + cost1.first + cost2.first + ')';
                mincost = currcost;
            }
        }

        return mp[key] = {str, mincost};
    }

    string matrixChainOrder(vector<int> &arr)
    {
        int n = arr.size();
        auto p = mcm(arr, 1, n - 1);
        return p.first;
    }
};

// Qs.3-> (994) Rotting Oranges

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return tm;
    }
};