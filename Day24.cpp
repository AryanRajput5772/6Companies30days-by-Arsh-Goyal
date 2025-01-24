#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (2343) Query Kth Smallest Trimmed Number

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

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (1994) The Number of Good Subsets

class Solution
{
    const int MOD = 1e9 + 7;

    vector<int> getPrimes(int n)
    {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> factors;

        for (int prime : primes)
        {
            if (n % prime == 0)
            {
                if ((n / prime) % prime == 0)
                    return {};
                factors.push_back(prime);
            }
        }
        return factors;
    }

public:
    int numberOfGoodSubsets(vector<int> &nums)
    {

        vector<int> freq(31, 0);
        for (int num : nums)
            freq[num]++;

        map<vector<int>, int> dp;
        dp[{}] = 1;

        for (int i = 2; i <= 30; ++i)
        {
            if (freq[i] == 0)
                continue;

            vector<int> primes = getPrimes(i);
            if (primes.empty())
                continue;

            map<vector<int>, int> new_dp = dp;
            for (auto &[currentPrimes, Count] : dp)
            {
                vector<int> newPrimes = currentPrimes;

                bool isValid = true;
                for (int prime : primes)
                {
                    if (find(currentPrimes.begin(), currentPrimes.end(),
                             prime) != currentPrimes.end())
                    {
                        isValid = false;
                        break;
                    }
                    newPrimes.push_back(prime);
                }

                if (isValid)
                {
                    sort(newPrimes.begin(), newPrimes.end());
                    new_dp[newPrimes] =
                        (new_dp[newPrimes] + (long long)Count * freq[i]) % MOD;
                }
            }

            dp = move(new_dp);
        }

        int result = 0;
        for (auto &[primes, Count] : dp)
        {
            if (!primes.empty())
            {
                result = (result + Count) % MOD;
            }
        }

        if (freq[1] > 0)
        {
            long long powerOfOnes = 1;
            for (int i = 0; i < freq[1]; ++i)
                powerOfOnes = (powerOfOnes * 2) % MOD;
            result = (result * powerOfOnes) % MOD;
        }

        return result;
    }
};

// Qs.3-> (2211) Count Collisions on a Road

class Solution
{
public:
    int countCollisions(string directions)
    {
        int n = directions.size();
        int rcnt = 0;
        int lcnt = 0;
        int scnt = 0;
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (flag && directions[i] == 'L')
                lcnt++;
            else
            {
                flag = 0;
            }

            if (directions[i] == 'S')
                scnt++;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (directions[i] == 'R')
                rcnt++;
            else
            {
                break;
            }
        }

        return n - (lcnt + rcnt + scnt);
    }
};