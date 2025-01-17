#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (1686) Stone Game VI

class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        int n = bobValues.size();
        int totalB = 0;
        int totalA = 0;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({aliceValues[i] + bobValues[i], i});
        }

        int i = 0;
        while (!pq.empty())
        {
            auto c = pq.top();
            pq.pop();

            if (i % 2 == 0)
            {
                totalA += aliceValues[c.second];
            }
            else
            {
                totalB += bobValues[c.second];
            }
            i++;
        }

        if (totalB > totalA)
        {
            return -1;
        }
        else if (totalB < totalA)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (2343) Query Kth Smallest Trimmed Number

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums,
                                       vector<vector<int>> &queries)
    {
        int n = queries.size();
        int t = nums[0].size();
        vector<int> ans;

        vector<string> Nums = nums;

        for (int i = 0; i < n; i++)
        {
            auto query = queries[i];

            vector<pair<string, int>> trimEle;
            for (int j = 0; j < Nums.size(); j++)
            {
                string trim = Nums[j].erase(0, t - query[1]);
                trimEle.push_back({trim, j});
            }
            sort(trimEle.begin(), trimEle.end());

            int kth = trimEle[query[0] - 1].second;
            ans.push_back(kth);
            Nums.clear();
            Nums = nums;
        }

        return ans;
    }
};

// Qs.3-> (2223) Sum of Scores of Built Strings {Z - Array Question}

class Solution
{
public:
    long long sumScores(string s)
    {
        long long n = s.size();
        vector<long long> z(n, 0);

        long long ans = 0;
        long long l = 0, r = 0;
        for (long long i = 1; i < n; i++)
        {
            if (i < r)
            {
                z[i] = z[i - l];

                if (i + z[i] > r)
                {
                    z[i] = r - i;
                }
            }

            while (i + z[i] < n && s[z[i]] == s[z[i] + i])
                z[i]++;

            if (i + z[i] > r)
            {
                l = i;
                r = i + z[i];
            }

            ans += z[i];
        }

        ans += n;

        return ans;
    }
};