#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (455) Assign Cookies

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0;
        int j = 0;
        int cnt = 0;

        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                cnt++;
                i++;
            }

            j++;
        }

        return cnt;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (1600) Throne Inheritance

class ThroneInheritance
{
    unordered_map<string, vector<string>> mp;
    unordered_set<string> st;
    string root;

public:
    ThroneInheritance(string kingName)
    {
        vector<string> v;
        mp.insert({kingName, v});
        root = kingName;
    }

    void birth(string parentName, string childName)
    {
        mp[parentName].push_back(childName);
    }

    void death(string name)
    {
        st.insert(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> result;
        dfs(root, result);
        return result;
    }

    void dfs(string root, vector<string> &result)
    {
        if (!st.count(root))
        {
            result.push_back(root);
        }

        for (auto child : mp[root])
        {
            dfs(child, result);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

// Qs.3-> (2943) Maximize Area of Square Hole in Grid

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        int n1 = hBars.size();
        int n2 = vBars.size();
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int lcsVbars = 1;
        int currVbars = 1;

        for (int i = 1; i < n2; i++)
        {
            if (vBars[i - 1] + 1 == vBars[i])
                currVbars++;
            else
            {
                currVbars = 1;
            }
            lcsVbars = max(lcsVbars, currVbars);
        }

        int lcsHbars = 1;
        int currHbars = 1;

        for (int i = 1; i < n1; i++)
        {
            if (hBars[i - 1] + 1 == hBars[i])
                currHbars++;
            else
            {
                currHbars = 1;
            }
            lcsHbars = max(lcsHbars, currHbars);
        }

        int x = min(lcsHbars, lcsVbars) + 1;

        return x * x;
    }
};