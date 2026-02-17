#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // void reverse(vector<vector<int>>& matrix){
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     for(int i=0;i<n;i++){
    //         int s = 0;
    //         int e = n-1;
    //         while(s<e){
    //             swap(matrix[s][i],matrix[i][e]);
    //         s++;
    //         e--;
    //     }
    // }
    void rotate(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
};