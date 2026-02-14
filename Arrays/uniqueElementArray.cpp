#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //using bits
    int arr[6]={1,2,3,2,1,4};
    // int ans=0;
    // for(int i =0 ;i<5;i++){
    //     ans = ans^ arr[i];
    // }
    // cout<<ans<<endl;

    //using map
    unordered_map<int,int> freq;

    for(int i=0;i<6;i++){
        freq[arr[i]]++;
    }
    for(auto &it : freq){
        if(it.second == 1){
            cout<<it.first<<endl;
        }
    }


    return 0;
}