#include <set>
#include <iostream>
#include <string>
using namespace std;
class set_op{
public:
    multiset<int> a;
    set<int> pre;
    void add(int b){
       a.insert(b);
       pre.insert(b);
       cout << a.count(b)<<endl;
    };//# after add
    void del(int b){
        cout << a.count(b)<<endl;
        a.erase(b);
    };//# before del
    void ask(int b ){
        if(a.count(b)!=0 ){
            cout << pre.count(b) <<" " << a.count (b) <<endl;
        }
        else{
            cout << pre.count(b) <<" "<<0<<endl;
        }

    };// 0 or 1 for if it is there.


};
int main() {
    int num,number;
    string com;
    cin >> num;
    set_op a;
    for (int i = 0; i < num ; ++i){
        cin >> com >> number;
        if(com == "add"){
            a.add(number);
        }
        else if(com == "ask"){
            a.ask(number);
        }
        else if (com == "del"){
            a.del(number);
        }
    }
    return 0;
}