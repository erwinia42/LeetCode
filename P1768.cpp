#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1, l2, c1, c2;
        string ans;

        l1 = word1.length();
        l2 = word2.length();
        c1 = c2 = 0;

        while(c1 < l1 and c2 < l2){
            ans.push_back(word1[c1++]);
            ans.push_back(word2[c2++]);
        }
        while(c1 < l1){
            ans.push_back(word1[c1++]);
        }
        while(c2 < l2){
            ans.push_back(word2[c2++]);
        }
        return ans;
    }
};