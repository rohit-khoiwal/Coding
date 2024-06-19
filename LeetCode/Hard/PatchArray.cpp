#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int result = 0;
        size_t i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                result++;
            }
        }

        return result;
    }
};

int main()
{
    vector nums = {1,5,10};
    Solution s;
    cout<<s.minPatches(nums, 20);
}