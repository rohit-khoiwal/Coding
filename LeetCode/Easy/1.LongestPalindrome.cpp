#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, int> count;
public:
    int longestPalindrome(string s) 
    {
        int lnSize = s.size();
        count.reserve(lnSize);
        char alpha = ' ';
        int longestSize = 0;
        for(int lnCounter = 0; lnCounter < lnSize; lnCounter++)
        {
            alpha = s[lnCounter];
            count[alpha] += 1;
            if(count[alpha]%2 == 0)
            {
                longestSize += 2;
            }
        }

        if((lnSize - longestSize) > 0)
            return longestSize + 1;
        else
            return longestSize;
    }
};

int main()
{
    string str;
    Solution s;
    cin>>str;
    cout<<s.longestPalindrome(str);
}