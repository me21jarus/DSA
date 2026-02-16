#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = 0;
        for(int i=1;i<=n;i++){
            totalSum += i;
        }
        int leftSum = 0;
        for(int i=1;i<=n;i++){
            int rightSum = totalSum - leftSum - i;
            if(leftSum == rightSum) return i;

            leftSum += i;
        }
        return -1;
    }
};