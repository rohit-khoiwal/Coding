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
    int minOperations(vector<int>& nums) 
    {
        int minZeros = INT_MAX;
        int minZeroIdx = -1;
        int countZero = 0;
        int minFlips = 0;
        vector<int> counts(nums.size(), 0);
        while(true)
        {
            countZero = 0;
            minZeroIdx = -1;
            minZeros = INT_MAX;
            for(int i = 0; i < nums.size() - 2; i++)
            {
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                countZero = countZeros(nums);
                if(countZero == 0)
                    return minFlips+1;
                if(countZero < minZeros)
                {
                    minZeros = countZero;
                    minZeroIdx = i;
                    
                }
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
            }
            nums[minZeroIdx] = 1 - nums[minZeroIdx];
            nums[minZeroIdx+1] = 1 - nums[minZeroIdx+1];
            nums[minZeroIdx+2] = 1 - nums[minZeroIdx+2];
            minFlips+=1;
        }
        return minFlips;
    }
    
    int countZeros(vector<int>& tempVec)
    {
        int minZeros = 0;
        for(int i = 0; i < tempVec.size(); i++)
        {
            if(tempVec[i] == 0)
                minZeros++;
        }
        return minZeros;
    }
};

int main()
{
    vector<int> nums = {0,1,1,1,0,0};
    Solution s;
    cout<<s.minOperations(nums);
    return 0;
}