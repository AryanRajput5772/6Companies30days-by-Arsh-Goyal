#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (1385) Find the Distance Value Between Two Arrays

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int cnt = 0;

        for (int i = 0; i < n1; i++)
        {
            int flag = 1;
            for (int j = 0; j < n2; j++)
            {
                if (abs(arr1[i] - arr2[j]) <= d)
                    flag = 0;
            }

            if (flag)
                cnt++;
        }

        return cnt;
    }
};
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (2958) Length of Longest Subarray With at Most K Frequency

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        int s = 0;
        unordered_map<int, int> mp;

        for (int e = 0; e < n; e++)
        {

            mp[nums[e]]++;

            while (mp[nums[e]] > k)
            {
                mp[nums[s]]--;
                s++;
            }
            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};

// Qs.3-> (2745) Construct the Longest New String

class Solution
{
public:
    int longestString(int x, int y, int z)
    {
        if (x != y)
        {
            return 2 * ((2 * min(x, y)) + 1 + z);
        }

        return 2 * ((2 * x) + z);
    }
};