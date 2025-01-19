#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (23) Merge k Sorted Lists

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }

        return NULL;
    }

    ListNode *partitionAndMerge(int start, int end, vector<ListNode *> &lists)
    {
        if (start > end)
            return NULL;
        if (start == end)
            return lists[start];

        int mid = start + (end - start) / 2;

        ListNode *l1 = partitionAndMerge(start, mid, lists);
        ListNode *l2 = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoSortedLists(l1, l2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        return partitionAndMerge(0, n - 1, lists);
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (354) Russian Doll Envelopes
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp;

        for (auto env : envelopes)
        {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size())
                dp.push_back(height);
            dp[left] = height;
        }

        return dp.size();
    }
};

// Qs.3-> (1568) Minimum Number of Days to Disconnect Island
class Solution
{
public:
    int n;
    int m;
    void DFS(vector<vector<int>> &grid, int i, int j,
             vector<vector<bool>> &vis)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 ||
            vis[i][j] != 0)
            return;

        vis[i][j] = 1;

        DFS(grid, i + 1, j, vis);
        DFS(grid, i - 1, j, vis);
        DFS(grid, i, j - 1, vis);
        DFS(grid, i, j + 1, vis);
    }

    int cntIslands(vector<vector<int>> &grid, int m, int n)
    {
        int islands = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    DFS(grid, i, j, vis);
                    islands++;
                }
            }
        }

        return islands;
    }
    int minDays(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        int islands = cntIslands(grid, m, n);

        if (islands > 1 || islands == 0)
            return 0;
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                        islands = cntIslands(grid, m, n);

                        if (islands > 1 || islands == 0)
                            return 1;

                        grid[i][j] = 1;
                    }
                }
            }
        }

        return 2;
    }
};