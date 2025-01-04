#include <bits/stdc++.h>
using namespace std;
// Qs.1-> (354) Russian Doll Envelopes

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp;

        for (auto env : envelopes)
        {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size())
                dp.push_back(height);
            dp[left] = height;
        }

        return dp.size();
    }
};

// Qs.2-> (1334) Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto c : edges)
        {
            dist[c[0]][c[1]] = c[2];
            dist[c[1]][c[0]] = c[2];
        }

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntcity = n;
        int cityno = -1;

        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int adjcity = 0; adjcity < n; adjcity++)
            {
                if (dist[city][adjcity] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if (cnt <= cntcity)
            {
                cntcity = cnt;
                cityno = city;
            }
        }

        return cityno;
    }
};

// Qs.3-> (2976) Minimum Cost to Convert String I

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        int n = cost.size();
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            dist[original[i] - 'a'][changed[i] - 'a'] =
                min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] == target[i])
                continue;
            if (dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
            {
                return -1;
            }
            else
            {
                sum += dist[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return sum;
    }
};