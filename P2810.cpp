#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string finalString(string s) {
        string ret;
        for(char c:s){
            if(c != 'i') {
                ret += c;
            }else{
                reverse(ret.begin(), ret.end());
            }
        }
        return ret;
    }
};
