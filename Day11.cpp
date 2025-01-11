#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (451) Sort Characters By Frequency

//   Definition for a binary tree node.
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;

        priority_queue<pair<int, char>> pq;
        string ans = "";
        for (auto c : s)
        {
            mp[c]++;
        }

        for (auto c : mp)
        {

            pq.push({c.second, c.first});
        }

        while (!pq.empty())
        {
            auto pair = pq.top();
            pq.pop();

            int frq = pair.first;
            char ch = pair.second;

            ans.append(frq, ch);
        }
        return ans;
    }
};
;

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Qs.2-> (2385) Amount of Time for Binary Tree to Be Infected

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode *curr)
    {
        if (curr == NULL)
            return;
        if (parent != -1)
        {
            adj[curr->val].push_back(parent);
        }

        if (curr->left)
        {
            adj[curr->val].push_back(curr->left->val);
        }
        if (curr->right)
        {
            adj[curr->val].push_back(curr->right->val);
        }

        makeGraph(adj, curr->val, curr->left);
        makeGraph(adj, curr->val, curr->right);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> adj;

        makeGraph(adj, -1, root);

        queue<int> q;
        unordered_set<int> vist;
        q.push(start);
        vist.insert(start);

        int Min = 0;

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                int curr = q.front();
                q.pop();

                for (int &nghbr : adj[curr])
                {
                    if (vist.count(nghbr) == 0)
                    {
                        vist.insert(nghbr);
                        q.push(nghbr);
                    }
                }
            }
            Min++;
        }

        return Min - 1;
    }
};

// Qs.3-> (2099) Find Subsequence of Length K With the Largest Sum

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> ans;
        if (k >= n)
            return nums;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        vector<pair<int, int>> selected;
        while (k--)
        {
            auto ele = pq.top();
            pq.pop();

            selected.push_back(ele);
        }

        sort(selected.begin(), selected.end(), [&](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });

        for (auto c : selected)
        {
            ans.push_back(c.first);
        }

        return ans;
    }
};