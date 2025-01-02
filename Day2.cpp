#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (1248) Count Number of Nice Subarrays
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int subarraycnt = 0;
        int s = 0;
        int e = 0;

        int oddcnt = 0;
        int prefix = 0;
        while (e < n)
        {

            if (nums[e] % 2 != 0)
            {
                oddcnt++;
                prefix = 0;
            }

            while (s < n && oddcnt > k)
            {
                if (nums[s] % 2 != 0)
                {
                    oddcnt--;
                }
                s++;
            }

            if (oddcnt == k)
            {

                while (s < n && nums[s] % 2 == 0)
                {
                    prefix++;
                    s++;
                }
                subarraycnt += prefix + 1;
            }

            e++;
        }

        return subarraycnt;
    }
};

// Qs.2 -> (462)  Minimum Moves to Equal Array Elements II

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int idx = n / 2;
        int median = nums[idx];

        for (auto c : nums)
        {
            cnt += abs(c - median);
        }

        return cnt;
    }
};

// Qs.3 -> (1823) Find the Winner of the Circular Game
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> arr(n);

        for (int i = 1; i <= n; i++)
        {
            arr[i - 1] = i;
        }
        int cnt = 0;
        int idx = 0;

        while (arr.size() != 1)
        {
            cnt++;
            if (cnt == k)
            {
                cnt = 0;
                arr.erase(arr.begin() + idx);
            }
            else
            {
                idx++;
            }

            idx %= arr.size();
        }

        return arr[0];
    }
};