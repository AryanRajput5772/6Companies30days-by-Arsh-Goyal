#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (216) Combination Sum III

class Solution
{
public:
    void solve(int idx, int sum, int n, vector<int> &temp, vector<vector<int>> &ans, int k)
    {
        if (sum == n && k == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (sum > n)
            return;

        for (int i = idx; i <= 9; i++)
        {
            if (i > n)
                break;

            temp.push_back(i);
            solve(i + 1, sum + i, n, temp, ans, k - 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, 0, n, temp, ans, k);

        return ans;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (519) Random Flip Matrix

class Solution
{
    int M, N;
    vector<vector<int>> mat;

    unordered_set<string> st;

public:
    Solution(int m, int n)
    {
        M = m;
        N = n;
        mat = vector<vector<int>>(M, vector<int>(N, 0));
    }

    vector<int> flip()
    {
        int i = rand() % M;
        int j = rand() % N;

        string str = to_string(i) + "_" + to_string(j);
        while (st.count(str))
        {
            i = rand() % M;
            j = rand() % N;
            str = to_string(i) + "_" + to_string(j);
        }

        st.insert(str);

        return {i, j};
    }

    void reset() { st.clear(); }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

// Qs.3-> (17) Letter Combinations of a Phone Number

class Solution
{
public:
    void solve(int idx, int n, string digits, vector<string> &ans, string &str,
               unordered_map<char, string> mp)
    {
        if (idx >= n)
        {
            if (str != "")
                ans.push_back(str);
            return;
        }

        string strg = mp[digits[idx]];
        for (int i = 0; i < strg.size(); i++)
        {
            str += strg[i];

            solve(idx + 1, n, digits, ans, str, mp);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> ans;
        string str = "";
        int n = digits.size();
        solve(0, n, digits, ans, str, mp);

        return ans;
    }
};