#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums){
    set<int> uniVals;
    for(int i = 0; i < nums.size(); i++){
        if(uniVals.find(nums[i]) != uniVals.end()){
            return true;
        }
        uniVals.insert(nums[i]);
    }
    return false;
}

/*
[1,2,3,1]
[1,2,3,4]
[1,1,1,3,3,4,3,2,4,2]
*/

int main(){
    // cout << "hello" << endl;
    set<int> uniVals;
    vector<int> nums = {1,2,3,1};

    cout <<containsDuplicate(nums)<<endl;
    return 0;
}