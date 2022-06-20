#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class membership{
public:
    typedef multimap <int, int> m;
    m pairs;
    membership(int id, int strength){
        pairs.insert(m::value_type(strength,id));
    }
    void insert(int id, int strength){
        battle(id, strength);
        pairs.insert(m::value_type(strength,id));
        //printall();
    }
    void battle(int id , int strength){
        int l_dif,u_dif,state = 0;
        pair <multimap<int,int>::iterator , multimap<int,int>::iterator > ret = pairs.equal_range(strength);
        if(ret.first == ret.second){ //no same strength exist
            l_dif = strength - (ret.first--)->first;
            u_dif = (ret.second)->first-strength;
            //cout << l_dif << u_dif<<endl;
            if (l_dif <= u_dif){
                cout << id << " "<< (ret.first--)->second <<endl;
            }
            else{
                cout << id << " "<< (ret.second)->second<<endl;
            }
        }
        else{  // same strength exist ; dif ==0
            cout << id << " " << (ret.first)->second<<endl;
        }


    }
    void printall(){
        for (auto i = pairs.begin(); i != pairs.end();i++ ){
            cout << i->first << " " << i->second<<endl;
        }
    }
};
int main() {
    membership memb_lst(1,1000000000);//facer！
    //multimap<int ,int> membership; // <strength, id>
    int num,strength, id;
    cin >> num;// number of new member
    for (int i = 0; i <num; ++i){
        cin >>id >> strength;
        memb_lst.insert(id,strength);
    }

    return 0;
}