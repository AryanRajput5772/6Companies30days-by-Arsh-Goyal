#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (297) Serialize and Deserialize Binary Tree

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#";

        string leftSerialize = serialize(root->left);
        string rightSerialize = serialize(root->right);

        return to_string(root->val) + "," + leftSerialize + "," + rightSerialize;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream s(data);
        return solve(s);
    }

    TreeNode *solve(stringstream &s)
    {
        string curr;
        getline(s, curr, ',');
        if (curr == "#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(curr));
        root->left = solve(s);
        root->right = solve(s);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Qs.2-> (2385) Amount of Time for Binary Tree to Be Infected

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

// Qs.3-> Delete N nodes after M nodes of a linked list(gfg)

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        int cnt = 0;
        Node *curr = head;

        while (curr != NULL && curr->next != NULL)
        {
            cnt++;
            int x = n;
            if (cnt == m)
            {
                while (x--)
                {

                    curr->next = curr->next->next;
                    if (curr->next == NULL)
                        return head;
                    cnt = 0;
                }
            }
            x = n;
            curr = curr->next;
        }
        return head;
    }
};