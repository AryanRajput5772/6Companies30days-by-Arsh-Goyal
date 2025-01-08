#include <bits/stdc++.h>
using namespace std;

// Qs.1-> Phone directory(gfg)

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endofword;

    Node()
    {
        endofword = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
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

    void printSuggestions(Node *curr, vector<string> &strs, string prefix)
    {
        if (curr->endofword)
        {
            strs.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            Node *next = curr->children[ch];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, strs, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestions(string s)
    {
        Node *temp = root;
        vector<vector<string>> ans;
        string prefix = "";

        for (int i = 0; i < s.size(); i++)
        {
            char lastch = s[i];
            prefix.push_back(lastch);

            Node *curr = temp->children[lastch];

            if (curr == NULL)
            {
                while (i < s.size())
                {
                    ans.push_back({"0"});
                    i++;
                }
                break;
            }

            vector<string> strs;
            printSuggestions(curr, strs, prefix);

            ans.push_back(strs);
            temp = curr;
        }

        return ans;
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie trie;

        for (int i = 0; i < n; i++)
        {
            trie.insert(contact[i]);
        }

        return trie.getsuggestions(s);
    }
};

// Qs.2-> (188) Best Time to Buy and Sell Stock IV

class Solution
{
public:
    int solve(int idx, int oprtns, int k, vector<int> &prices,
              vector<vector<int>> &dp)
    {
        if (idx == prices.size())
        {
            return 0;
        }
        if (oprtns == 2 * k)
        {
            return 0;
        }
        if (dp[idx][oprtns] != -1)
        {
            return dp[idx][oprtns];
        }
        int profit = 0;
        if (oprtns % 2 == 0)
        {
            int buy = -prices[idx] + solve(idx + 1, oprtns + 1, k, prices, dp);
            int skip = 0 + solve(idx + 1, oprtns, k, prices, dp);
            profit = max(buy, skip);
        }
        else
        {
            int sell = prices[idx] + solve(idx + 1, oprtns + 1, k, prices, dp);
            int skip = 0 + solve(idx + 1, oprtns, k, prices, dp);
            profit = max(sell, skip);
        }

        return dp[idx][oprtns] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return solve(0, 0, k, prices, dp);
    }
};

// Qs.3-> (845) Longest Mountain in Array

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;

        for (int i = 1; i < n - 1;)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int cnt = 1;
                int j = i;

                while (j > 0 && arr[j] > arr[j - 1])
                {
                    cnt++;
                    j--;
                }
                while (i < n - 1 && arr[i] > arr[i + 1])
                {
                    cnt++;
                    i++;
                }

                ans = max(cnt, ans);
            }
            else
            {
                i++;
            }
        }

        return ans;
    }
};