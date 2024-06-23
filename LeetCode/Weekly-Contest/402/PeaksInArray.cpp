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
        vector<int> peaks(nums.size(), 0);
        for(int i = 1; i < nums.size() - 1; i++)
        {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
                peaks[i] = 1;
        }   
        
        int numsSize = nums.size();
        int x = (int)(ceil(log2(nums.size()))); 
        int max_size = 2*(int)pow(2, x) - 1; 
        vector<int> segmentTreeForPeaks(max_size, 0);
        buildSegmentTree(segmentTreeForPeaks, peaks, 0, 0, numsSize-1);
        vector<int> countOfPeaksVec;
        int updateIdx = 0;
        int getsumVal = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            if(queries[i][0] == 2) // update
            {
                updateIdx = queries[i][1];
                nums[updateIdx] = queries[i][2];
                updatePeaks(segmentTreeForPeaks, peaks, nums, updateIdx);
            }
            else // GetSum
            {
                getsumVal = 0;
                if(queries[i][1] == queries[i][2])
                {
                    getsumVal = 0;
                }
                else
                {
                    getsumVal = getTotalSum(segmentTreeForPeaks, 0, numsSize-1, queries[i][1], queries[i][2], 0);
                    if(peaks[queries[i][1]] == 1)
                        getsumVal--;

                    if(peaks[queries[i][2]] == 1)
                        getsumVal--;
                }
                countOfPeaksVec.push_back(getsumVal);
            }
        }

        return countOfPeaksVec;
    }

    void updatePeaks(vector<int> &segmentTree, vector<int> &peaks, vector<int> &nums, int currIndex)
    { 
        bool updateSt = false;
        for(int i = currIndex-1; i < currIndex+2; i++)
        {
            if((i-1) < 0 || (i+1) >= nums.size()) continue;
            updateSt = false;
            if(nums[(i-1)] < nums[i] && nums[i] > nums[(i+1)])
            {
                if(peaks[i] == 0)
                    updateSegmentTree(segmentTree, 0, peaks.size()-1, i, 1, 0);
                peaks[i] = 1;
            }    
            else
            {
                if(peaks[i] != 0)
                    updateSegmentTree(segmentTree, 0, peaks.size()-1, i, -1, 0);
                peaks[i] = 0;
            }
        }
    }

    void buildSegmentTree(vector<int> &segmentTree, vector<int> &peaks, int currIndex, int leftIndex, int rightIndex)
    {
        if(leftIndex == rightIndex)
        {
            segmentTree[currIndex] = peaks[leftIndex];
            return;
        }

        int mid = (leftIndex + rightIndex)/2;
        buildSegmentTree(segmentTree, peaks, 2*currIndex + 1, leftIndex, mid);
        buildSegmentTree(segmentTree, peaks, 2*currIndex + 2, mid+1, rightIndex);    
        segmentTree[currIndex] = segmentTree[2*currIndex + 1] + segmentTree[2*currIndex + 2]; 
    }

    void updateSegmentTree(vector<int> &segmentTree, int stLeftIndex, int stRightIndex, int updateIdx, int diff, int stCurrIndex) // diff means add peak or remove peak
    {
        // Base Case: If the input index lies outside the range of 
        // this segment 
        if (updateIdx < stLeftIndex || updateIdx > stRightIndex) 
            return; 
        
        segmentTree[stCurrIndex] += diff;
        if(stLeftIndex != stRightIndex)
        {
            int mid = (stLeftIndex + stRightIndex)/2;
            updateSegmentTree(segmentTree, stLeftIndex, mid, updateIdx, diff, 2*stCurrIndex + 1);
            updateSegmentTree(segmentTree, mid+1, stRightIndex, updateIdx, diff, 2*stCurrIndex + 2);
        }
    }

    int getTotalSum(vector<int> &segmentTree, int stLeftIndex, int stRightIndex, int qleftIndex, int qrightIndex, int stCurrIndex)
    {
        if(qleftIndex <= stLeftIndex && stRightIndex <= qrightIndex)
            return segmentTree[stCurrIndex];

        if(stRightIndex < qleftIndex || qrightIndex < stLeftIndex)
            return 0;
        
        int mid = (stLeftIndex + stRightIndex)/2;
        return getTotalSum(segmentTree, stLeftIndex, mid, qleftIndex, qrightIndex, 2*stCurrIndex + 1) + 
                getTotalSum(segmentTree, mid+1, stRightIndex, qleftIndex, qrightIndex, 2*stCurrIndex + 2);
    }
};

int main()
{
    vector<int> nums = {5,9,6,10,8,4};
    vector<vector<int>> queries = {{1,0,0},{1,1,3},{2,5,8}, {2,4,3}};
    Solution s;
    vector<int> ans = s.countOfPeaks(nums, queries);
    for(int i : ans)
        cout<<i<<',';
    return 0;
}