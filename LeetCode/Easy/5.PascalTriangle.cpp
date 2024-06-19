#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTraingle(numRows);
        pascalTraingle[0].push_back(1);
        for(int outerLoopCounter = 1; outerLoopCounter < numRows; outerLoopCounter++)
        {
            pascalTraingle[outerLoopCounter].push_back(1);
            for(int innerLoopCounter = 1; innerLoopCounter < outerLoopCounter; innerLoopCounter++)
            {
                pascalTraingle[outerLoopCounter].push_back((pascalTraingle[outerLoopCounter - 1][innerLoopCounter - 1] + pascalTraingle[outerLoopCounter - 1][innerLoopCounter]));
            }
            pascalTraingle[outerLoopCounter].push_back(1);
        }
        return pascalTraingle;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> relativeSortedArr = s.generate(5);
    for(vector<int> nums : relativeSortedArr)
    {
        for(int num : nums)
            cout<<num<<',';
        cout<<endl;
    }
}