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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        unordered_map<int, int> profitAgainstDifficulty;
        for(int i = 0; i < difficulty.size(); i++)
            profitAgainstDifficulty[difficulty[i]] = profit[i];
        
        sort(difficulty.begin(), difficulty.end());

        int totalProfit = 0;
        int workerDifficultyLevel = 0;
        for(int i = 0; i < worker.size(); i++)
        {
            workerDifficultyLevel = nearOrEqualbinarySearch(0, difficulty.size(), worker[i], difficulty);
            totalProfit += profitAgainstDifficulty[workerDifficultyLevel];
        }
        return totalProfit;
    }

    int nearOrEqualbinarySearch(int left, int right, int searchValue, vector<int>&array)
    {
        int mid = 0;
        while(left < right)
        {
            mid = (left + right)/2;
            if(array[mid] <= searchValue)
                left = mid + 1;
            else
                right = mid;
        }
        if((left - 1) > array.size())
            return 0;
        return array[left - 1];
    }
};

int main()
{
    vector<int> difficulty = {68,35,52,47,86};
    vector<int> profit = {67,17,1,81,3};
    vector<int> worker = {92,10,85,84,82};
    Solution s;
    cout<<s.maxProfitAssignment(difficulty, profit, worker);
    return 0;
}