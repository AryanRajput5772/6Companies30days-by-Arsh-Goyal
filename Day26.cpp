#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (2513) Minimize the Maximum of Two Arrays

class Solution
{
public:
    int __gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return __gcd(b, a % b);
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2)
    {
        long long lcm =
            ((long)divisor1 * (long)divisor2) / __gcd(divisor1, divisor2);

        long long h = pow(10, 10);
        long long l = 1;
        long long ans = pow(10, 10);

        while (l <= h)
        {
            long long mid = l + (h - l) / 2;

            long long a = mid - (mid / divisor1);
            long long b = mid - (mid / divisor2);
            long long c = mid - (mid / divisor1) - (mid / divisor2) + (mid / lcm);

            if (a >= uniqueCnt1 && b >= uniqueCnt2 &&
                a + b - c >= uniqueCnt1 + uniqueCnt2)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

// Qs.2-> (2933) High-Access Employees

class Solution
{
public:
    vector<string>
    findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        vector<string> ans;
        unordered_map<string, vector<string>> mp;

        for (auto c : access_times)
        {
            mp[c[0]].push_back(c[1]);
        }

        for (auto it = mp.begin(); it != mp.end();)
        {
            vector<string> &temp =
                it->second;
            if (temp.size() < 3)
            {
                it = mp.erase(it);
            }
            else
            {
                sort(temp.begin(), temp.end());
                string name = it->first;

                vector<int> timeMinutes;

                for (auto time : temp)
                {
                    int hour = stoi(time.substr(0, 2));
                    int minute = stoi(time.substr(2, 2));
                    timeMinutes.push_back(hour * 60 + minute);
                }

                bool highAccess = false;
                for (int i = 0; i < timeMinutes.size(); i++)
                {
                    int cnt = 1;
                    for (int j = i + 1; j < timeMinutes.size(); j++)
                    {
                        if (timeMinutes[j] - timeMinutes[i] < 60)
                        {
                            cnt++;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (cnt >= 3)
                    {
                        highAccess = true;
                        break;
                    }
                }

                if (highAccess)
                {
                    ans.push_back(name);
                }

                it++;
            }
        }

        return ans;
    }
};

// Qs.3-> (2343) Query Kth Smallest Trimmed Number

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums,
                                       vector<vector<int>> &queries)
    {
        int n = queries.size();
        int t = nums[0].size();
        vector<int> ans;

        vector<string> Nums = nums;

        for (int i = 0; i < n; i++)
        {
            auto query = queries[i];

            vector<pair<string, int>> trimEle;
            for (int j = 0; j < Nums.size(); j++)
            {
                string trim = Nums[j].erase(0, t - query[1]);
                trimEle.push_back({trim, j});
            }
            sort(trimEle.begin(), trimEle.end());

            int kth = trimEle[query[0] - 1].second;
            ans.push_back(kth);
            Nums.clear();
            Nums = nums;
        }

        return ans;
    }
};