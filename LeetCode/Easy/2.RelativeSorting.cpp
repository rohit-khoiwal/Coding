#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        map<int, int> numbersCount;
        for(int lnCounter = 0; lnCounter < arr1.size(); lnCounter++)
            numbersCount[arr1[lnCounter]] += 1;

        int num;
        int count = 0;
        vector<int> relativeSortedArr;
        for(int lnCounter = 0; lnCounter < arr2.size(); lnCounter++)
        {
            num = arr2[lnCounter];
            count = numbersCount[num];
            while(count > 0)
            {
                relativeSortedArr.push_back(num);
                count--;
            }
            numbersCount[num] = count;
        }

        for(auto itr : numbersCount)
        {
            num = itr.first;
            count = itr.second;
            while(count > 0)
            {
                relativeSortedArr.push_back(num);
                count--;
            }
        }

        return relativeSortedArr;
    }
};

int main()
{
    vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2{2,1,4,3,9,6};
    Solution s;
    vector<int>relativeSortedArr = s.relativeSortArray(arr1, arr2);
    for(auto num : relativeSortedArr)
        cout<<num<<' ';
}