class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> result;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());

        auto last = num.end();
        for (auto a = num.begin(); a < num.end()-2; ++a) {//a < prev(last, 2)
            auto b = next(a);
            auto c = prev(last);
            while (b < c) {
                if (*a + *b + *c < 0) {
                    ++b;
                    while(b<c && *b == *(b-1)) ++b;
                } else if (*a + *b + *c > 0) {
                    --c;
                    while(b<c && *c == *(c+1)) --c;
                } else {
                    result.push_back({ *a, *b, *c });
                    ++b;
                    --c;
                    while(b<c && *b == *(b-1)) ++b;
                    while(b<c && *c == *(c+1)) --c;
                }
                
            }
            while(a < prev(last,2) && *a == *(a+1)) ++a;
        }
        //sort(result.begin(), result.end());
        //result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};