#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (2461)  Maximum Sum of Distinct Subarrays With Length K

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        long long ans = 0;

        if (n < k)
        {
            return 0;
        }

        int s = 0;
        long long sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }

        if (mp.size() == k)
        {
            ans = sum;
        }

        for (int i = k; i < n; i++)
        {
            sum -= nums[s];
            mp[nums[s]]--;
            if (mp[nums[s]] == 0)
            {
                mp.erase(nums[s]);
            }
            s++;
            mp[nums[i]]++;
            sum += nums[i];

            if (mp.size() == k)
            {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// Qs.2-> K Sized Subarray Maximum (gfg)

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            while (!dq.empty() && arr[dq.back()] < arr[i])
            {
                dq.pop_back();
            }

            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};

// Qs.3-> Nuts and Bolts Problem (gfg)

class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        char comp[9] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nuts[i]]++;
        }
        int j = 0;
        for (int i = 0; i < 9; i++)
        {
            if (mp[comp[i]] != 0)
            {
                nuts[j] = comp[i];
                bolts[j++] = comp[i];
            }
        }
    }
};