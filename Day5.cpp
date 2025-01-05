#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (638) Shopping Offers

class Solution
{
public:
    map<vector<int>, int> mp;

    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        if (mp.count(needs) != 0)
        {
            return mp[needs];
        }
        int ans = 0;

        for (int i = 0; i < price.size(); i++)
        {
            ans += (price[i] * needs[i]);
        }

        for (int i = 0; i < special.size(); i++)
        {
            bool isvalid = true;
            for (int j = 0; j < needs.size(); j++)
            {
                if (needs[j] < special[i][j])
                {
                    isvalid = false;
                }
            }

            if (isvalid)
            {
                for (int j = 0; j < needs.size(); j++)
                {
                    needs[j] -= special[i][j];
                }
                int prices = special[i].back() + shoppingOffers(price, special, needs);
                ans = min(ans, prices);

                for (int j = 0; j < needs.size(); j++)
                {
                    needs[j] += special[i][j];
                }
            }
        }

        return mp[needs] = ans;
    }
};

// Qs.2-> (2002) Maximum Product of the Length of Two Palindromic Subsequences

class Solution
{

public:
    bool isPal(string &s)
    {
        string temp = s;
        reverse(temp.begin(), temp.end());
        if (temp != s)
        {
            return false;
        }

        return true;
    }

    void helper(string &s, int idx, string &s1, string &s2, long long &ans)
    {
        if (isPal(s1) && isPal(s2))
        {
            long long prod = (int)s1.size() * s2.size();
            ans = max(ans, prod);
        }

        for (int i = idx; i < s.size(); i++)
        {
            s1.push_back(s[i]);
            helper(s, i + 1, s1, s2, ans);
            s1.pop_back();

            s2.push_back(s[i]);
            helper(s, i + 1, s1, s2, ans);
            s2.pop_back();
        }

        return;
    }

    int maxProduct(string s)
    {
        long long ans = 0;
        string s1 = "";
        string s2 = "";
        helper(s, 0, s1, s2, ans);
        return ans;
    }
};

// Qs.3-> (497) Random Point in Non-overlapping Rectangles

class Solution
{
    int sum;
    vector<int> ptsSum;
    vector<vector<int>> rects;

public:
    Solution(vector<vector<int>> &rects)
    {
        sum = 0;
        this->rects = rects;
        for (auto rect : rects)
        {
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            ptsSum.push_back(sum);
        }
    }

    vector<int> pick()
    {
        int randIdx = rand() % sum;
        int idx = upper_bound(ptsSum.begin(), ptsSum.end(), randIdx) - ptsSum.begin();

        vector<int> rect = rects[idx];

        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */