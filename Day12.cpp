#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (368) Largest Divisible Subset
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);
        int lsi = 0;
        int maxL = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {

                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }

                    if (dp[i] > maxL)
                    {
                        maxL = dp[i];
                        lsi = i;
                    }
                }
            }
        }

        vector<int> result;
        while (lsi != -1)
        {
            result.push_back(nums[lsi]);
            lsi = prev_idx[lsi];
        }

        return result;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Qs.2-> (692) Top K Frequent Words

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        vector<string> ans;

        for (auto c : words)
        {
            mp[c]++;
        }

        for (auto c : mp)
        {
            ans.push_back(c.first);
        }

        sort(ans.begin(), ans.end(), [&](string a, string b)
             {
            if (mp[a] == mp[b]) {
                return a < b;
            } else {
                return mp[a] > mp[b];
            } });
        ans.erase(ans.begin() + k, ans.end());

        return ans;
    }
};

// Qs.3-> (532) K-diff Pairs in an Array

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {

            int a = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - a == k)
                {
                    cnt++;
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return cnt;
    }
};