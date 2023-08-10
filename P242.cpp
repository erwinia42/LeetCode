#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        map <char, int> char_map;
        for(char c:s){
            if(char_map.find(c) == char_map.end()){
                char_map[c] = 0;
            }
            char_map[c]++;
        }
        for(char c:t){
            if(char_map.find(c) == char_map.end()){
                return false; //Found char in t that doesn't exist in s
            }
            char_map[c]--;
        }

        return all_of(char_map.cbegin(), char_map.cend(),
                      [](const auto&p){return p.second == 0;}
                      );
    }
};
