#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>> n;
	
	int i=0;
	while(i<n){
	    int num=1;
	    while(num<n-i+1){
	        cout<<num;
	        num++;
	    }
	    
	    int star = 2*i;
	    while(star){
	        cout<<"*";
	        star--;
	    }
	   
	   int num2=n-i;
	    while(num2){
	        cout<<num2;
	        num2--;
	    }
	    cout<<endl;
	    i++;
	}
	
    return 0;
}
/*
Output for n=5
1234554321
1234**4321
123****321
12******21
1********1
*/