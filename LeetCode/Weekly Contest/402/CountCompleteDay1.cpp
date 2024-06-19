#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) 
    {
        if(hours.size() == 1)
            return 0;
        
        unordered_map<int, short> hoursCountMap;
        int totalCount = 0;
        int key = 0;
        short count = 0;
        int leftSide = 0;
        int rightSide = 0;
        for(int i = 0; i < hours.size(); i++)
        {
            key = hours[i];
            // if(key%24 != 0)
            // {
            //     leftSide = key%24 + key;
            //     rightSide = leftSide - 24;
            // }
            // else
            // {
            //     leftSide = key - 24;
            //     rightSide = key + 24;
            // }
            leftSide = key%24;
            rightSide = 24 - leftSide;
            if(leftSide != rightSide)
            {
                if(hoursCountMap[leftSide] > 0  && (leftSide + (key%24))%24 ==0)
                    totalCount += hoursCountMap[leftSide];
                else if(hoursCountMap[rightSide] > 0 && (rightSide + (key%24))%24 ==0)
                    totalCount += hoursCountMap[rightSide];
            }
            else
            {
                if(hoursCountMap[leftSide] > 0)
                    totalCount += hoursCountMap[leftSide];
            }
            hoursCountMap[(key%24)]++;
        }
        return totalCount;
    }
};

int main()
{
    vector hours = {11,11,24};
    Solution s;
    cout<<s.countCompleteDayPairs(hours);
}