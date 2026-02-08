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
        while (j <=2*i-1) {
            cout << "*";
            j++;
        }
        cout <<endl;
        i++;
    }
    return 0;
}
/*
Output for n=4:
   *
  ***
 *****
*******
*/