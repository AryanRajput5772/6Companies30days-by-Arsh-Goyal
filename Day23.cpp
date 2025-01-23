#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (146) LRU Cache

class LRUCache
{
    unordered_map<int, int> keyToVal;
    unordered_map<int, list<int>::iterator> keyToNode;
    list<int> keyInOrder;
    int cap;

    void evectAppropriately()
    {
        int culpritKey = keyInOrder.front();
        keyInOrder.pop_front();
        keyToNode.erase(culpritKey);
        keyToVal.erase(culpritKey);
    }

    void updateTimeToNow(int key)
    {
        if (keyToNode.count(key))
        {
            list<int>::iterator ref = keyToNode[key];
            keyInOrder.erase(ref);
        }

        keyInOrder.push_back(key);
        keyToNode[key] = --keyInOrder.end();
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (!keyToVal.count(key))
        {
            return -1;
        }
        updateTimeToNow(key);
        return keyToVal[key];
    }

    void put(int key, int value)
    {
        keyToVal[key] = value;
        updateTimeToNow(key);

        if (keyToVal.size() > cap)
        {
            evectAppropriately();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (3006) Find Beautiful Indices in the Given Array I

class Solution
{
public:
    void zArray(string s, vector<long long> &z)
    {

        long long l = 0, r = 0;
        int n = s.size();
        for (long long i = 1; i < n; i++)
        {
            if (i < r)
            {
                z[i] = z[i - l];

                if (i + z[i] > r)
                {
                    z[i] = r - i;
                }
            }

            while (i + z[i] < n && s[z[i]] == s[z[i] + i])
                z[i]++;

            if (i + z[i] > r)
            {
                l = i;
                r = i + z[i];
            }
        }
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> ans;
        string s1 = a + "$" + s;
        int n1 = s1.size();
        vector<long long> z1(n1, 0);

        string s2 = b + "$" + s;
        int n2 = s2.size();
        vector<long long> z2(n2, 0);
        zArray(s1, z1);
        zArray(s2, z2);

        unordered_set<int> st1;
        unordered_set<int> st2;

        for (int i = 0; i < n1; i++)
        {
            if (z1[i] == a.size())
            {
                st1.insert(i - a.size() - 1);
            }
        }
        for (int i = 0; i < n2; i++)
        {
            if (z2[i] == b.size())
            {
                st2.insert(i - b.size() - 1);
            }
        }

        for (auto i : st1)
        {
            for (auto j : st2)
            {
                if (abs(j - i) <= k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// Qs.3-> (1969) Minimum Non-Zero Product of the Array Elements

class Solution
{
    int mod = 1e9 + 7;

public:
    long long Pow(long long x, long long n)
    {
        x %= mod;
        long long bform = n;
        long long ans = 1;
        while (bform > 0)
        {
            if (bform % 2 == 1)
            {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            bform /= 2;
        }

        return ans;
    }

    int minNonZeroProduct(int p)
    {
        if (p == 1)
            return 1;
        long long x = (1L << p) - 1;

        return ((x % mod) * (Pow(x - 1, x / 2) % mod)) % mod;
    }
};