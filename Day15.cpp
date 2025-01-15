#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (2572) Count the Number of Square-Free Subsets

class Solution
{
public:
    int squareFreeSubsets(vector<int> &nums)
    {
        using ll = long long;
        map<ll, ll> mp;
        int MOD = 1e9 + 7;

        for (int num : nums)
        {
            bool flag = false;

            for (int i = 2; i <= 5; i++)
            {
                if (num % (i * i) == 0)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
                continue;

            vector<pair<ll, ll>> temp;

            for (auto [k, v] : mp)
            {
                if (__gcd(k, (ll)num) == 1)
                {
                    temp.push_back({k * num, v});
                }
            }

            for (auto [k, v] : temp)
            {
                mp[k] = (mp[k] + v) % MOD;
            }

            mp[num] = (mp[num] + 1) % MOD;
        }

        int result = 0;

        for (auto [k, v] : mp)
        {
            result = (result + v) % MOD;
        }

        return result;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Qs.2-> (331) Verify Preorder Serialization of a Binary Tree

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        stringstream s(preorder);
        string word;
        int indeg = 0, outdeg = 0;
        while (getline(s, word, ','))
        {
            indeg++;

            if (indeg > outdeg + 1)
                return false;

            if (word != "#")
                outdeg += 2;
        }

        // cout<<indeg<<" -- "<<outdeg<<endl;
        if (indeg - outdeg == 1)
        {
            return true;
        }
        return false;
    }
};

// Qs.3-> (396) Rotate Function

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        long long Fk = 0;

        for (int i = 0; i < n; i++)
        {
            Fk += (i * nums[i]);
            sum += nums[i];
        }
        long long ans = Fk;
        for (int i = 1; i < n; i++)
        {
            Fk = Fk + sum - (n * nums[n - i]);
            ans = max(ans, Fk);
        }

        return ans;
    }
};