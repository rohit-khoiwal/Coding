#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int scoreOfString(string s) {
        int num = 0;
        for(int i = 1; i < s.size(); i++)
            num += abs(s[i] - s[i-1]);
        return num;
    }
};

int main()
{
    Solution s;
    cout<<s.scoreOfString("hello");
}