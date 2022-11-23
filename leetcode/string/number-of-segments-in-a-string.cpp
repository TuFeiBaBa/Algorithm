#include <string>

using namespace std;
/*
* �ַ����еĵ����� https://leetcode.cn/problems/number-of-segments-in-a-string/description/
*/
class Solution {
//public:
//    int countSegments(string s) {
//        int segmentCount = 0;
//
//        for (int i = 0; i < s.size(); i++) {
//            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
//                segmentCount++;
//            }
//        }
//
//        return segmentCount;
//    }
//};

/*
* ��������������
*/
public:
    int countSegments(string s) {
        int l = 0;
        int ans = 0;
        for (auto& c : s) {
            if (isspace(c)) {
                if (l) ans++, l = 0;
            }
            else {
                l++;
            }
        }
        //���ܺ������һ�����ܲ��ǿո�����
        return l > 0 ? ans + 1 : ans;
    }
};

int main() {

}