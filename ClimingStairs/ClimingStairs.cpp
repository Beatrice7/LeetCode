/********************************************************************************** 
* 
* You are climbing a stair case. It takes n steps to reach to the top.
* 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
*               
**********************************************************************************/

/*DP: f(n)=f(n-1)+f(n-2)
* 设f(x)=【剩x阶时，迈楼梯的方法总数】。
* 首先迈出第一步，如果一次迈一阶，剩下x-1阶，方法总数为f(x-1)；
* 如果一次迈两阶，剩下x-2阶，方法总数为f(x-2);
* f(x)=f(x-1)+f(x-2)。容易发现，f(1)=1，f(2)=2.
*
*但是递归太慢，所以用迭代
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        if(n == 2) return 2;
        int ppre = 1, pre = 2, cur;
        for(int i = 3; i <= n; ++i){
            cur = ppre + pre;
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
};


class Solution {
public:
    
    int climbStairs(int n) {
       if (n<=3) return n;
       int a[2]={2,3};
       for(int i=4; i<=n; i++){
           int t = a[0] + a[1];
           a[0] = a[1];
           a[1] = t;
       }
       return a[1];
    }

    //Time too long
    int climbStairs2(int n) {
        if (n<=3) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
