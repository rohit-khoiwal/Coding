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
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int totalSize = nums.size();
        double smallAverage = INT_MAX;
        double specificAvg = 0;
        for(int i = 0; i < totalSize/2; i++)
        {
            specificAvg = (double)((nums[i] + nums[totalSize - i - 1]))/2;
            if(specificAvg < smallAverage)
                smallAverage = specificAvg;
        }
        return smallAverage;
    }
};

int main()
{
    vector<int> nums = {7,8,3,4,15,13,4,1};
    Solution s;
    cout<<s.minimumAverage(nums);
    return 0;
}