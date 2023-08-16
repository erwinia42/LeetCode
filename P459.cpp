#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> allDivisors(int n){
        vector<int> ret;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                ret.insert(ret.begin(), i);
                ret.push_back(n / i);
            }
        }
        ret.push_back(n);
        return ret;
    }

    bool repeatedSubstringPattern(string s) {
        if(s.size() <= 1){
            return false;
        }
        vector<int> divisors = allDivisors(s.size());
        for(int div:divisors){
            string sub = s.substr(0,s.size()/div);
            string test;
            for(int i = 0; i < div; i++){
                test += sub;
            }
            if(test == s){
                return true;
            }
        }
        return false;
    }
};

int main(){
    string s = "abcabcabcabc";
    Solution solver;
    bool temp = solver.repeatedSubstringPattern(s);
}