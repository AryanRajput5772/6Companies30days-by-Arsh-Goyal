#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (703) Kth Largest Element in a Stream

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

public:
    KthLargest(int k, vector<int> &nums)
    {
        vector<int> stream = nums;
        sort(stream.begin(), stream.end());
        K = k;

        while (stream.size() != 0 && k--)
        {
            pq.push(stream.back());
            stream.pop_back();
        }
    }

    int add(int val)
    {

        pq.push(val);

        if (pq.size() > K)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
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

// Qs.3-> (2135) Count Words Obtained After Adding a Letter

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<string> swords;

        for (auto &c : startWords)
        {
            sort(c.begin(), c.end());
            swords.insert(c);
        }

        int cnt = 0;

        for (auto &wrd : targetWords)
        {
            sort(wrd.begin(), wrd.end());

            for (int i = 0; i < wrd.size(); i++)
            {
                string temp = wrd.substr(0, i) + wrd.substr(i + 1);

                if (swords.count(temp))
                {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};