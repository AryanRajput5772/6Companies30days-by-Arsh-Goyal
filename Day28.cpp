#include <bits/stdc++.h>
using namespace std;

// Qs.1-> Number following a pattern (gfg)
class Solution
{

public:
    string printMinNumberForPattern(string s)
    {
        string ans = "";
        stack<int> st;
        int n = 1;
        for (auto c : s)
        {
            st.push(n++);
            if (c == 'I')
            {
                while (!st.empty())
                {
                    int ele = st.top();
                    st.pop();
                    ans += to_string(ele);
                }
            }
        }

        st.push(n++);
        while (!st.empty())
        {
            int ele = st.top();
            st.pop();
            ans += to_string(ele);
        }

        return ans;
    }
};
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (2526) Find Consecutive Integers from a Data Stream

class DataStream
{
    int cnt = 0;
    int val;
    int K;

public:
    DataStream(int value, int k)
    {
        val = value;
        K = k;
    }

    bool consec(int num)
    {
        if (num == val)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        return cnt >= K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

// Qs.3-> Missing And Repeating (gfg)

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int a;
        int b;
        for (auto c : arr)
        {
            if (mp[c] > 0)
            {
                a = c;
            }
            mp[c]++;
        }

        for (int i = 1; i <= arr.size(); i++)
        {
            if (mp[i] == 0)
            {
                b = i;
                break;
            }
        }

        return {a, b};
    }
};