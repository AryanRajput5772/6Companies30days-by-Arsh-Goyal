#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (718) Maximum Length of Repeated Subarray

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Qs.2-> (1208) Get Equal Substrings Within Budget

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        int ans = 0;
        int cost = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            cost += abs(t[i] - s[i]);
            while (cost > maxCost)
            {
                cost -= abs(t[j] - s[j]);
                j++;
            }

            ans = max(i - j + 1, ans);
        }

        return ans;
    }
};

// Qs.3-> (419) Battleships in a Board

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char prevH = '.';
                char prevV = '.';

                if (i > 0)
                {
                    prevV = board[i - 1][j];
                }
                if (j > 0)
                {
                    prevH = board[i][j - 1];
                }

                if (board[i][j] == 'X' && prevH == '.' && prevV == '.')
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};