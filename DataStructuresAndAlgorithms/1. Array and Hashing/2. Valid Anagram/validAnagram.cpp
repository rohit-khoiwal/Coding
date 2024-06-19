#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t){
    if (s.length() != t.length()) return false;
    unordered_map<char, int> counts;
    for(int i = 0; i < s.length(); i++){
        counts[s[i]]++;
    }
    for(int i = 0; i < t.length(); i++){
        if(counts[t[i]] != 0){
            counts[t[i]]--;
        }
        else return false;
    }
    return true;
}

int main(int argc, char **argv){
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;
    return 0;
}