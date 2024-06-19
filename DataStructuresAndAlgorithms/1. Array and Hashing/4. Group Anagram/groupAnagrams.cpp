#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs){
    vector<string> sortStrs;
    copy(strs.begin(), strs.end(), back_inserter(sortStrs));
    for(int i = 0; i < sortStrs.size(); i++){
        sort(sortStrs[i].begin(), sortStrs[i].end());
    }
    unordered_map<string, vector<string>> groups;
    for(int i = 0; i < strs.size(); i++){
        groups[sortStrs[i]].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    int j = 0;
    for(auto x: groups){
        vector<string> ans2;
        for(int i = 0; i < x.second.size(); i++){
            ans2.push_back(x.second[i]);
        }
        ans.push_back(ans2);
        j++;
    }   
    return ans;
}


int main(int argc, char **argv) {
    
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> groups;
    groups = groupAnagrams(strs);
    for(int i=0; i < groups.size(); i++) {
        for(int j=0; j < groups[i].size(); j++) {
            cout<< groups[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}