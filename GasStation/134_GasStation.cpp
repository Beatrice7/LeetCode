/********************************************************************************** 
* 
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
* 
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
* its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
* 
* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
* 
* Note:
* The solution is guaranteed to be unique.
* 
*               
**********************************************************************************/

//方法一：
//设置头尾两个指针，从头开始加，遇到total<0时，就从末尾加入一个，再计算total
//重复此法，直到两个指针重合为止；
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        int total = 0;
        int i, j;
        for(i = 0, j = len-1; i <= j;){
            if(total + gas[i] - cost[i] < 0){
                total += gas[j] - cost[j];
                --j;
            }else{
                total += gas[i] - cost[i];
                ++i;
            }
        }
        
        return total >= 0 ? i % len : -1;
    }
};


//方法二：
//从头到尾遍历一次，total用来测试到底有解否；
//current_total则用来定位是从哪个gas_station开始出现负值的
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        int index = 0, total = 0, current_total = 0;
        for(int i = 0; i < len; ++i){
            total += gas[i] - cost[i];
            current_total += gas[i] - cost[i];
            if(current_total < 0){
                current_total = 0;
                index = (i + 1) % len;
            }
        }
        return total >= 0 ? index : -1;
    }
};