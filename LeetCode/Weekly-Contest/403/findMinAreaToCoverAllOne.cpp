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
    int minimumArea(vector<vector<int>>& grid) 
    {
       int ll = -1, rl = -1;
       int lb = -1, rb = -1;
       bool updateBreath = false;
       for(int breath = 0; breath < grid.size(); breath++)
       {
            updateBreath = false;
            for(int len = 0; len < grid[breath].size(); len++)
            {
                if(grid[breath][len] == 1)
                {
                    updateBreath = true;
                    if(-1 == ll && -1 == rl)
                        ll = rl = len;
                    else if(len < ll)
                        ll = len;
                    else if(len > rl)
                        rl = len;                        
                }
            }
            if(updateBreath)
            {
                if(-1 == lb && -1 == rb)
                    lb = rb = breath;
                else if(breath < lb)
                    lb = breath;
                else if(breath > rb)
                    rb = breath;  
            }
       } 
       int minArea = ((rl - ll)+1)*((rb -lb)+1);
       return minArea;
    }
};

int main()
{
    vector<vector<int>> nums = {{0,0,0},{0,0,0},{1,0,1},{1,0,0}};
    Solution s;
    cout<<s.minimumArea(nums);
    return 0;
}