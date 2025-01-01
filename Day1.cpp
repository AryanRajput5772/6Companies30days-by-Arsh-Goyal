#include <bits/stdc++.h>
using namespace std;
// Qs.1-> (299) Bulls and Cows

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> mpsec;
        unordered_map<int, char> mpsec1;

        unordered_map<char, int> mpges;
        unordered_map<int, char> mpges1;

        string ans = "";

        int bull = 0;
        int cow = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            mpsec[secret[i]]++;
            mpges[guess[i]]++;

            mpsec1[i] = secret[i];
            mpges1[i] = guess[i];
        }

        for (auto c : mpsec1)
        {
            if (mpges1[c.first] == c.second)
            {
                bull++;
                mpges[c.second]--;
                mpsec[c.second]--;
            }
        }

        for (auto c : mpsec)
        {

            if (mpges[c.first] != 0)
            {

                if (mpges[c.first] != 0 && mpges[c.first] < c.second)
                {
                    cow += mpges[c.first];
                }
                else
                {
                    cow += c.second;
                }
            }
        }

        ans += to_string(bull) + "A";
        ans += to_string(cow) + "B";

        return ans;
    }
};

// Qs.2-> (187) Repeated DNA Sequences

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

// Qs.3-> (1401) Circle and Rectangle Overlapping

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2)
    {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return sqrt(dx * dx + dy * dy) <= radius;
    }
};