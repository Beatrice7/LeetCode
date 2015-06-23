class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        int result = 0;
        height.push_back(0);
        for(int i = 0; i < height.size(); ){
            if(s.empty() || height[s.top()] < height[i]){
                s.push(i++);
            }
            else{
                int tmp = s.top();
                s.pop();
                result = max(result, height[tmp]*(s.empty() ? i : i - s.top() - 1));
            }
        }
        return result;
    }
};
