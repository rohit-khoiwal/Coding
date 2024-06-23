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
    int minimumOperations(vector<int>& nums) {
        int minOp = 0;
        int minReqVal = 0;
        for(int num : nums)
        {
            if(num%3 != 0)
                minOp+=1;
        }
        return minOp;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    Solution s;
    cout<<s.minimumOperations(nums);
    return 0;
}