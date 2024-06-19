#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

void twoSum(vector<int> &nums, int target){
    unordered_map<char,int> counts;
    for(int i=0;i<nums.size();i++){
        counts[nums[i]]++;
    }
    for(int i=0;i<nums.size();i++){
        counts[nums[i]]--;
        int anVal = target - nums[i];
        if(counts[anVal] > 0){
            for(int j=i;j<nums.size();j++){
                if(anVal == nums[j]){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
};
int main(int argc, char **argv){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    twoSum(nums,target);
    return 0;
}