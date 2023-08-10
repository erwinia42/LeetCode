#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(char c; c>= 'a'; c<= 'z'){
            if(count(s.begin(), s.end(), c) < count(t.begin(), t.end(), c)){
                return c;
            }
        }
        return NULL
    }
};
