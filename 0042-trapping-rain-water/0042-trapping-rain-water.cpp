#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Handle empty edge case
        
        vector<int> left(n, 0), right(n, 0);
        
        // 1. Fill left max array
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(height[i], left[i - 1]);
        }
        
        // 2. Fill right max array
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(height[i], right[i + 1]);
        }
        
        // 3. Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(left[i], right[i]) - height[i];
        }
        
        return water;
    }
};