#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (825) Friends Of Appropriate Ages

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int n = ages.size();
        int cnt = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[ages[i]]++;
        }

        for (auto &x : mp)
        {
            for (auto &y : mp)
            {
                if (y.first <= (0.5 * x.first) + 7 || y.first > x.first ||
                    (y.first > 100 && x.first < 100))
                {
                    continue;
                }
                else
                {
                    if (x.first == y.first)
                    {
                        cnt += x.second * (y.second - 1);
                    }
                    else
                    {
                        cnt += x.second * y.second;
                    }
                }
            }
        }
        return cnt;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Qs.2-> (2707) Extra Characters in a String

class Solution
{
public:
    int solve(int idx, int n, string &s, unordered_set<string> &st,
              vector<int> &dp)
    {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        int minExtra = n;
        string curstr = "";

        for (int i = idx; i < n; i++)
        {
            curstr += s[i];
            int currextra = 0;
            if (st.find(curstr) == st.end())
            {
                currextra += curstr.size();
            }
            int remainextra = solve(i + 1, n, s, st, dp);

            int total = remainextra + currextra;
            minExtra = min(minExtra, total);
        }

        return dp[idx] = minExtra;
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {

        int n = s.size();
        vector<int> dp(n + 1, -1);
        unordered_set<string> st;
        for (auto c : dictionary)
            st.insert(c);
        return solve(0, n, s, st, dp);
    }
};

// Qs.3-> (139) Word Break

class Solution
{
public:
    bool solve(int idx, int n, string &s, unordered_set<string> &st,
               vector<int> &dp)
    {
        if (idx == n)
        {
            return true;
        }

        if (dp[idx] != -1)
            return dp[idx];

        string curstr = "";
        for (int i = idx; i < n; i++)
        {
            curstr += s[i];

            if (st.find(curstr) != st.end() && solve(i + 1, n, s, st, dp))
            {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        unordered_set<string> st;
        for (auto c : wordDict)
            st.insert(c);
        return solve(0, n, s, st, dp);
    }
};