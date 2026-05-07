#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

int main(){

    // unordered_map<string, int> m;
    map<string, int> m;

    pair<string, int> p = make_pair("Suraj", 1);

    m.insert(p);

    pair<string, int> pair2("Dhanya",2);
    m.insert(pair2);

    m["SD"] = 3;

    m["SD"] = 4;

    cout<<m["SD"]<<endl;

    cout<<m["DS"]<<endl;

    cout<<m.at("DS")<<endl;

    for(auto& i:m){
        cout<<i.first<<": "<<i.second<<endl;
    }

    return 0;
}