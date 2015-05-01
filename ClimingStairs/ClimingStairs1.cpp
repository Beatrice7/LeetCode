/*实际是个斐波那契：f(n)=f(n-1)+f(n-2)
* 斐波那契的数学公式为
* F(n)=(1/√5)*{[(1+√5)/2]^n - [(1-√5)/2]^n}【√5表示根号5】
*/
class Solution {
public:
    int climbStairs(int n) {
        const double s = sqrt(5);
        // return floor( (pow((1+s)/2, n) - pow((1-s)/2, n)) * (1/s) ) + 0.5;
        return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
    }
};
