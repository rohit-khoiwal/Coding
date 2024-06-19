#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> powerCountMap;
        for(int pow : power)
            powerCountMap[pow]++;

        vector<int> uniquePowers(powerCountMap.size(), 0);
        auto itr = powerCountMap.begin();
        for(int i = 0; i < powerCountMap.size(); i++, itr++)
            uniquePowers[i] = itr->first;

        long long currDamagePow = 0;
        long long currDamageValue=0;
        vector<long long> storedPower(powerCountMap.size(), 0);
        currDamagePow = uniquePowers[0];    
        currDamageValue = currDamagePow * powerCountMap[currDamagePow];
        storedPower[0] = currDamageValue;
        int j = 0;
        for(int i = 1; i < uniquePowers.size(); i++)
        {
            currDamagePow = uniquePowers[i];
            currDamageValue = currDamagePow * powerCountMap[currDamagePow];
            j = i - 1;
            storedPower[i] = storedPower[j];
            while(j >= 0)
            {
                if((currDamagePow - 2) > uniquePowers[j])
                {
                    currDamageValue += storedPower[j];
                    break;
                }
                j--;
            }
            storedPower[i] = max(currDamageValue, storedPower[i]);
        }
        return storedPower[storedPower.size()-1];
    }
};

int main()
{
    vector hours = {2,2,3,5,7,8,9,9,10,10};
    Solution s;
    cout<<s.maximumTotalDamage(hours);
}