#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int n){
        int s = 0,e = n;

        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;
            long long sq = 1LL* mid*mid;
            
            if(sq == n) return mid;

            if(sq < n){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return ans;
    }

    double moreprecise(int n,int precise,int tempSol){
        double factor = 1;
        double ans = tempSol;
        
        for(int i=0;i<precise;i++){
            factor = factor/10;
            for(double j=0;j*j<n;j+=factor){
                ans = j;
            }
        }
        return ans;
    }
    int main() {
        int n;
        cout<<"enter number"<<endl;
        cin>> n;

        int tempSol = binarySearch(n);
        cout<<"answer is: "<<moreprecise(n,3,tempSol)<<endl;

        return 0;
    }