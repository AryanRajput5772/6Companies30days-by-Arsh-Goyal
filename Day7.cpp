#include <bits/stdc++.h>
using namespace std;

// Qs.1-> (36) Valid Sudoku

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> st;
            int cnt = 0;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != 46)
                {
                    cnt++;
                    st.insert(board[i][j]);
                }
            }
            if (st.size() != cnt)
            {
                return false;
            }

            unordered_set<char> st2;
            int cnt2 = 0;
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != 46)
                {
                    cnt2++;
                    st2.insert(board[j][i]);
                }
            }
            if (st2.size() != cnt2)
            {
                return false;
            }
        }

        int srow = 0;
        int scol = 0;
        int k = 9;
        while (k--)
        {

            unordered_set<char> st;
            int cnt = 0;
            for (int i = srow; i <= srow + 2; i++)
            {
                for (int j = scol; j <= scol + 2; j++)
                {
                    if (board[i][j] != 46)
                    {
                        cnt++;
                        st.insert(board[i][j]);
                    }
                }
                if (st.size() != cnt)
                {
                    return false;
                }
            }
            scol += 3;
            if (scol > 6)
            {
                scol = 0;
                srow += 3;
            }
        }

        return true;
    }
};

// Qs.2-> (387) First Unique Character in a String

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> freq(26, 0);

        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

// Qs.3-> (168) Excel Sheet Column Title

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string str = "";

        while (columnNumber > 0)
        {
            columnNumber -= 1;
            char ch = (columnNumber % 26) + 'A';
            str += ch;
            columnNumber /= 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};