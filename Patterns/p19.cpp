#include <iostream>
using namespace std;

int main() {
    int n ;
    cin>>n;
    int i = n;
    while (i > 0) {
        int space=i-1;
        while(space!=n-1){
            cout<<" ";
            space++;
        }
        int j = 0;
        while (j < i) {
            cout << '*';
            j++;
        }
        cout <<endl;
        i--;
    }
    return 0;
}

/*
Output for n=4:
****
 ***
  **
   *
*/