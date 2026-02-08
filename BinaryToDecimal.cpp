#include <bits/stdc++.h>
using namespace std;

int main() {
	int n ;
	cin>> n ;
	
	int ans = 0;
	int i = 0;
	
	while(n){
	    int bit = n%10;
	    if(bit == 1){
	        ans = bit*pow(2,i)+ans;
	    }
	    n = n/10;
	    i++;
	}
	
	cout<<ans;
	return 0;
}
