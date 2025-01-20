#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (1530) Number of Good Leaf Nodes Pairs

//  * Definition for a binary tree node.
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
    void makeGraph(TreeNode *root, TreeNode *prev, unordered_map<TreeNode *, vector<TreeNode *>> &adj, unordered_set<TreeNode *> &st)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            st.insert(root);
        }

        if (prev != NULL)
        {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }

    int countPairs(TreeNode *root, int distance)
    {
        unordered_map<TreeNode *, vector<TreeNode *>> adj;
        unordered_set<TreeNode *> st;

        makeGraph(root, NULL, adj, st);

        int cnt = 0;
        for (auto &leaf : st)
        {
            unordered_set<TreeNode *> vis;
            queue<TreeNode *> que;
            que.push(leaf);
            vis.insert(leaf);

            for (int level = 0; level <= distance; level++)
            {
                int size = que.size();
                while (size--)
                {
                    TreeNode *curr = que.front();
                    que.pop();

                    if (curr != leaf && st.count(curr))
                    {
                        cnt++;
                    }

                    for (auto &ngbr : adj[curr])
                    {
                        if (!vis.count(ngbr))
                        {
                            que.push(ngbr);
                            vis.insert(ngbr);
                        }
                    }
                }
            }
        }

        return cnt / 2;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (211) Design Add and Search Words Data Structure

class WordDictionary
{
public:
    struct Node
    {
        unordered_map<char, Node *> children;
        bool endofword;

        Node() { endofword = false; }
    };

    Node *root;

    WordDictionary() { root = new Node(); }

    void addWord(string key)
    {

        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }

            temp = temp->children[key[i]];
        }
        temp->endofword = true;
    }

    bool searchHelper(Node *root, string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {

            char ch = key[i];

            if (ch == '.')
            {
                for (int j = 0; j < 26; j++)
                {

                    if (temp->children.count('a' + j))
                    {
                        if (searchHelper(temp->children['a' + j],
                                         key.substr(i + 1)))
                        {
                            return true;
                        }
                    }
                }

                return false;
            }

            else if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->endofword;
    }

    bool search(string key) { return searchHelper(root, key); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// Qs.3-> (1617) Count Subtrees With Max Distance Between Cities

class Solution
{
public:
    int solve(int subtree, vector<vector<int>> &dist, int n)
    {
        int cntN = 0, cntE = 0, mxD = 0;
        for (int i = 0; i < n; i++)
        {
            if (((subtree >> i) & 1) == 0)
                continue;

            cntN++;

            for (int j = i + 1; j < n; j++)
            {
                if (((subtree >> j) & 1) == 0)
                    continue;

                if (dist[i][j] == 1)
                {
                    cntE++;
                }
                mxD = max(mxD, dist[i][j]);
            }
        }

        if (cntN == cntE + 1)
        {
            return mxD;
        }

        return -1;
    }

    vector<int> countSubgraphsForEachDiameter(int n,
                                              vector<vector<int>> &edges)
    {
        vector<int> v(n - 1, 0);

        vector<vector<int>> dist(15, vector<int>(15, INT_MAX));

        for (auto temp : edges)
        {
            dist[temp[0] - 1][temp[1] - 1] = 1;
            dist[temp[1] - 1][temp[0] - 1] = 1;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[j][k] == INT_MAX)
                        continue;
                    dist[i][j] = dist[j][i] =
                        min({dist[i][j], dist[j][i], dist[i][k] + dist[k][j]});
                }
            }
        }

        for (int i = 0; i < (1 << n); i++)
        {
            int ans = solve(i, dist, n);
            if (ans > 0)
            {
                v[ans - 1]++;
            }
        }

        return v;
    }
};