#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        
    }
};

int main()
{
    vector<int> nums = {4,1,4,2,1,5};
    vector<vector<int>> queries = {{2,2,4},{1,0,2},{1,0,4}};
    Solution s;
    vector<int> ans = s.countOfPeaks(nums, queries);
    for(int i : ans)
        cout<<i<<',';
    return 0;
}