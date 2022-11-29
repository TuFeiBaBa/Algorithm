#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
* ����ĵ��� https://leetcode.cn/problems/most-common-word/description/
*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> set;
        for (auto& s : banned) set.insert(s);
        unordered_map<string, int> map;
        string s;
        //�����������ĸ�����
        paragraph += ' ';
        for (char& c : paragraph) {
            if (isalpha(c)) {
                s += tolower(c);
            }
            else {
                if (!s.empty() && set.find(s) == set.end()) {
                    map[s]++;
                }
                s = "";
            }
        }
        //�����������ĸ�����
        // if(!s.empty() && set.find(s) == set.end()){
        //     map[s]++;
        // }
        unordered_map<string, int>::iterator iter = map.begin();
        string ans;
        int maxNum = 0;
        while (iter != map.end()) {
            if (iter->second > maxNum) {
                ans = iter->first;
                maxNum = iter->second;
            }
            iter++;
        }
        return ans;
    }
};

int main() {

}