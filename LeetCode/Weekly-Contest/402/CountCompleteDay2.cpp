#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> count(24);
        for(int i = 0; i < hours.size(); i++) {
            ans += count[(24 - (hours[i]%24))%24];
            count[hours[i] % 24]++;
        }
        return ans;
    }
};
int main()
{
    vector hours = {11,11,24};
    Solution s;
    cout<<s.countCompleteDayPairs(hours);
}