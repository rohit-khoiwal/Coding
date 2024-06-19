#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2*t;
    }
};


int main()
{
    Solution s;
    cout<<s.theMaximumAchievableX(4, 1);
}