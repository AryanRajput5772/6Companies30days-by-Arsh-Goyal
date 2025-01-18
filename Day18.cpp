#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (1095) Find in Mountain Array

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        int peak = l;

        l = 0;
        r = peak;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        l = peak + 1;
        r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (1334) Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto c : edges)
        {
            dist[c[0]][c[1]] = c[2];
            dist[c[1]][c[0]] = c[2];
        }

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntcity = n;
        int cityno = -1;

        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int adjcity = 0; adjcity < n; adjcity++)
            {
                if (dist[city][adjcity] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if (cnt <= cntcity)
            {
                cntcity = cnt;
                cityno = city;
            }
        }

        return cityno;
    }
};

// Qs.3-> (187) Repeated DNA Sequences

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        unordered_map<string, int> mp;
        int e = 9;
        vector<string> ans;
        string str = "";

        for (int i = 0; i <= e; i++)
        {
            str += s[i];
        }

        while (e < n)
        {
            mp[str]++;

            str.erase(0, 1);
            e++;
            if (e < n)
                str += s[e];
        }

        for (auto c : mp)
        {
            if (c.second > 1)
            {
                ans.push_back(c.first);
            }
        }

        return ans;
    }
};