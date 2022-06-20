#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
class id_op{
public:
    map<int,list<int>> id;
    id_op():id(){};
    void new_id(int N){
        id[N];
    };
    void add(int N,int b ){
        id[N].push_back(b);
    };
    void merge(int N, int M){
        id[N].merge(id[M]);
        id[M].clear();
    };
    void out(int N){
        id[N].sort();
        for(auto i = id[N].begin();i != id[N].end();i++){
            if (i == --id[N].end()){
                cout << *i;
            }
            else{cout <<  *i << " ";}
        }
        cout <<endl;
    };
    void unique(int N){
        id[N].sort();
        id[N].unique();
    };

};
int to_int(string a ){
    int b;
    stringstream ss(a);
    ss >> b;
    return b;
}
int main() {
    int num;
    string str,com,temp;
    stringstream ss;
    vector <string> command;
    id_op od;
    cin >> num;
    cin.ignore();
    for(int i = 0; i < num; ++i){
        getline(cin,str);
        command.clear();
        ss.clear();
        ss << str;
        while (ss>> com){
            command.push_back(com);
        }
        temp= command.front();
        if (temp == "new"){
            od.new_id(to_int(command[1]));
        }
        else if (temp == "add"){
            od.add(to_int(command[1]),to_int(command[2]));
        }
        else if (temp == "merge"){
            od.merge(to_int(command[1]),to_int(command[2]));
        }
        else if (temp == "unique"){
            od.unique(to_int(command[1]));
        }
        else if (temp == "out"){
            od.out(to_int(command[1]));
        }
    }
    return 0;
}