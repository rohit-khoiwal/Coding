#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    string convert(string s, int numRows) 
    {
        vector<vector<char>> zigZagPattern(numRows);
        char ch;
        int idx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ch = s[i];
            zigZagPattern[idx%numRows].push_back(ch);
            idx++;
        }
        string newPattern;
        for(auto it:zigZagPattern)
        {
            
        }
    }
};

int main()
{
    string str = "";
    Solution s;
    cout<<s.convert(str, 3);
}