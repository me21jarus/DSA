#include <iostream>
using namespace std;

int main() {
    int n ;
    cout<<"Enter N"<<endl;
    cin>>n;
    int i = 1;
    while (i <=n) {
        int space=n-i;
        while(space){
            cout<<" ";
            space--;
        }
        int j = 1;
        int x=1;
        while (j <=i) {
            cout << x++;
            j++;
        }
        int next=i-1;
        while(next){
            cout<<next--;
        }
        cout <<endl;
        i++;
    }
    return 0;
}
/*
Output for n=4:
   1
  121
 12321
1234321
*/