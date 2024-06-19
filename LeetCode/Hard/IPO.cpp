#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
    
class ComparisonClass {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) 
    {
        if(a.first > b.first)
            return true;
        else if(a.first < b.first)
            return false;
        else
        {
            if(a.second > b.second)
                return true;
            else
                return false;
        }
    }
};


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        if(k == 0)
            return 0;
        if(profits.size() == 0)
            return w;

        int profit = 0;
        vector<pair<int, int>> pq;

        for(int i = 0; i < capital.size(); i++)
            pq.push_back({capital[i], profits[i]});

        make_heap(pq.begin(), pq.end(), ComparisonClass());
        pair<int, int> selectedProject;
        int n = capital.size();
        while((k > 0) && (n > 0)) 
        {
            k--;
            n--;
            pop_heap(pq.begin(), pq.end());
            selectedProject = pq[pq.size()-1];
            pq.pop_back();
            push_heap(pq.begin(), pq.end(), ComparisonClass());
            // cout<<selectedProject.first<<' '<<selectedProject.second<<endl;
            if(selectedProject.first <= w)
            {
                w = w - selectedProject.first + selectedProject.second;// budget 
                profit += selectedProject.second;//profit
            }
            // else if(selectedProject.first < w)
            // {

            // }
            else
                break;
        }
        return profit;

    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2, 3};
    vector<int> b = {0, 1, 2};
    cout<<s.findMaximizedCapital(3, 0, a, b);
}