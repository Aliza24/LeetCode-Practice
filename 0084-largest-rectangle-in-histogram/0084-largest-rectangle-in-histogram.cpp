class Solution {
    //stores index
    vector<int> leftmin(vector<int> &arr){
        int n =arr.size();
        vector<int> leftMinIndex(n, -1);
        stack <int> stk;
        for(int i=0; i<n; i++){
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            leftMinIndex[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        return leftMinIndex;
    }
//stores index not value
     vector<int> rightmin(vector<int> &arr){
        int n =arr.size();
        vector<int> rightMinIndex(n, -1);
        stack <int> stk;
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            rightMinIndex[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        return rightMinIndex;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMinIndex = leftmin(heights);
        vector<int> rightMinIndex = rightmin(heights);
        int maxArea = INT_MIN; //can take zero as well
        for(int i=0; i<n; i++){
            int width = rightMinIndex[i] - leftMinIndex[i] -1;
            int area = width*heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};