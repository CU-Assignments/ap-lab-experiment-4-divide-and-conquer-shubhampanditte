#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isNice(const string &sub) {
        unordered_set<char> chars(sub.begin(), sub.end());
        for (char c : sub) {
            if (chars.count(tolower(c)) == 0 || chars.count(toupper(c)) == 0)
                return false;
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.length();
        string longest = "";
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                string sub = s.substr(i, j - i);
                if (isNice(sub) && sub.length() > longest.length()) {
                    longest = sub;
                }
            }
        }
        
        return longest;
    }
};

int main() {
    Solution solution;
    cout << solution.longestNiceSubstring("YazaAay") << endl; // Output: "aAa"
    return 0;
}
