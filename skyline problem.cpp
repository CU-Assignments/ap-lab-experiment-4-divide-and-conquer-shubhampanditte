#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        for (auto& b : buildings) {
            points.emplace_back(b[0], -b[2]); // Start of building (negative height for sorting)
            points.emplace_back(b[1], b[2]);  // End of building
        }
        sort(points.begin(), points.end());
        
        multiset<int> heights = {0};
        vector<vector<int>> skyline;
        int prevHeight = 0;
        
        for (auto& [x, h] : points) {
            if (h < 0) {
                heights.insert(-h); // Insert height when building starts
            } else {
                heights.erase(heights.find(h)); // Remove height when building ends
            }
            
            int currHeight = *heights.rbegin();
            if (currHeight != prevHeight) {
                skyline.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        
        return skyline;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skyline = solution.getSkyline(buildings);
    
    for (auto& point : skyline) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    
    return 0;
}