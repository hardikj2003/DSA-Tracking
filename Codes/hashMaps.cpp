#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;



int main(){
    //creation
    map<string, int> m;

    //insertion

    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    //2
    pair<string, int> p2("love", 2);
    m.insert(p2);

    //3
    m["mera"] = 1;
    m["mera"] = 2;

    // searching
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    
    cout<<m["hardik"]<<endl;  // this will create a new key with value = 0;
    cout<<m.at("hardik")<<endl;  // this will throw an error

    // size
    cout<<m.size()<<endl;

    // presence
    cout<<m.count("hardik")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;


    for(auto i: m){
        cout<<i.first << " " << i.second <<endl;
    }
    
    return 0;
}