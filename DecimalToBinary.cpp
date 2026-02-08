#include <bits/stdc++.h>
using namespace std;

int main() {
	int n ;
	cin>> n ;
	
	int ans = 0;
	int i = 0;
	
	//division method
	while(n){
	    int bits = n%2;
	    n=n/2;
	    ans = (bits*pow(10,i))+ans;
	    i++;
	}
	
	
	//bit and method
    while(n){
        int bit = n&1;
        ans = (bit*pow(10 , i)) + ans;
        n = n>>1;
        i++;
    }
    cout<<ans;
    return 0;
}