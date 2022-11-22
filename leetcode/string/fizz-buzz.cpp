#include <string>
#include <vector>

using namespace std;
/*
* Fizz Buzz https://leetcode.cn/problems/fizz-buzz/description/
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            /*if (i % 5 == 0 && i % 3 == 0) {
                ans.push_back("FizzBuzz");
            }
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            else {
                ans.push_back(to_string(i));
            }*/
            string curr;
            if (i % 3 == 0) {
                curr += "Fizz";
            }
            if (i % 5 == 0) {
                curr += "Buzz";
            }
            if (curr.size() == 0) {
                curr += to_string(i);
            }
            ans.emplace_back(curr);
        }
        return ans;
    }
};

int main() {

}