#include <bits/stdc++.h>
using namespace std;
// Qs.1-> (661)  Image Smoother

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int srow = i;
                if (i > 0)
                {
                    srow = i - 1;
                }

                int scol = j;
                if (j > 0)
                {
                    scol = j - 1;
                }
                int erow = i;
                if (i + 1 < m)
                {
                    erow = i + 1;
                }
                int ecol = j;
                if (j + 1 < n)
                {
                    ecol = j + 1;
                }
                long long sum = 0;
                int cnt = 0;

                for (int k = srow; k <= erow; k++)
                {
                    for (int l = scol; l <= ecol; l++)
                    {
                        sum += img[k][l];
                        cnt++;
                    }
                }

                ans[i][j] = sum / cnt;
            }
        }

        return ans;
    }
};

// Qs.2-> (2970) Count the Number of Incremovable Subarrays I

class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int flag = 1;
                int prev = -1;
                for (int k = 0; k < n; k++)
                {
                    if (k >= i && k <= j)
                    {

                        continue;
                    }
                    if (prev >= nums[k])
                    {
                        flag = 0;
                        break;
                    }
                    prev = nums[k];
                }

                if (flag)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// Qs.3-> (324) Wiggle Sort II

class Solution
{
public:
    void wiggleSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        sort(arr.begin(), arr.end());
        int l = n - 1, mid = (n - 1) / 2;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans[i] = arr[mid--];
            }
            else
            {
                ans[i] = arr[l--];
            }
        }

        arr = ans;
    }
};