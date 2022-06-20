#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
class str_op{
        int len;
        vector<string> strings;
        public:
        str_op(int a, vector<string> b){len = a; strings = b;};
        string copy(int N,int X, int L);
        string add(string s1,string s2);
        string find(string s, int N);
        string rfind(string s, int N);
        void reset(string s ,int N);
        void insert(string s, int N, int X);
        void printN(int N);
        void printAll();
};
bool is_number (string s){
    if (s.length()>5){ // >99999
        return false;
    }
    for (auto i = s.begin(); i!= s.end();++i){
        if (!isdigit(*i)){
            return false;
        }
    }
    return true;
}
string str_op::copy (int N,int X, int L){
    // N X L: GET Nth string whose length is L started from Xth char.
    string result = strings[N-1].substr(X,L);
    return result;
}
string str_op::add (string s1, string s2){
    // S1 S2: check if S1 and S2 are integer between 0-99999, yes then do iteger adding
    //no then do string addition
    int a, b;
    stringstream ss1(s1), ss2(s2);
    if (is_number(s1) && is_number(s2)){
        ss1>> a;
        ss2>> b;
        return to_string(a+b);
    }
    else{
        return s1+s2;
    }
}
string str_op::find (string s, int N){
    //S N:
    if(strings[N-1].find(s)== string::npos){
        return to_string(strings[N-1].length());
    }
    return to_string(strings[N-1].find(s));
}
string str_op::rfind (string s, int N){
    if(!strings[N-1].rfind(s)){
        return to_string(strings[N-1].length());
    }
    return to_string(strings[N-1].rfind(s));
}
void str_op::insert (string s, int N, int X){
    strings[N-1].insert(X,s);
}
void str_op::reset (string s, int N){
    strings[N-1] = s;
}
void str_op::printN (int N){
    cout << strings[N-1]<<endl;
}
void str_op::printAll(){
    for(int i =0;i < len; ++i){
        cout << strings[i]<<endl;
    }
}

int main()
{
    int a;
    string com;
    string temp;
    int num=1;
    stringstream ss;
    vector<string> strings,command;
    vector<string> work_flow;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> temp; // create string vector
        strings.push_back(temp);
    }
    str_op op(num,strings);
    int w_len;
    cin.ignore();
    while(getline(cin,com)){
        command.clear();
        ss <<com;
        while (ss>> temp){
            command.push_back(temp);
        }
        if (com == "over"){
            break;
        }
        for(auto i = command.rbegin(); i != command.rend(); ++i){
            com = *i;
            if(com =="copy"){
                temp = op.copy(stoi(work_flow[w_len]),stoi(work_flow[w_len-1]),stoi(work_flow[w_len-2]));
                for (int j = 0; j < 3; j++){
                    work_flow.pop_back();
                }
                work_flow.push_back(temp);
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com=="add"){
                temp = op.add(work_flow[w_len],work_flow[w_len-1]); //s1 s2
                for (int j = 0; j < 2;j++){
                    work_flow.pop_back();
                }
                work_flow.push_back(temp);
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com == "find"){
                temp = op.find(work_flow[w_len],stoi(work_flow[w_len-1]));
                for (int j = 0; j < 2;j++){
                    work_flow.pop_back();
                }
                work_flow.push_back(temp);
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com == "rfind"){
                temp = op.rfind(work_flow[w_len],stoi(work_flow[w_len-1]));
                for (int j = 0; j < 2;j++){
                    work_flow.pop_back();
                }
                work_flow.push_back(temp);
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com =="insert"){
                op.insert(work_flow[w_len],stoi(work_flow[w_len-1]),stoi(work_flow[w_len-2]));
                for (int j = 0; j < 3;j++){
                    work_flow.pop_back();
                }
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com =="reset"){
                op.reset(work_flow[w_len],stoi(work_flow[w_len-1]));
                for (int j = 0; j < 2;j++){
                    work_flow.pop_back();
                }
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com =="print"){
                op.printN(stoi(work_flow[w_len]));
                work_flow.pop_back();
                w_len = work_flow.size() -1;
                continue;
            }
            else if(com =="printall"){
                op.printAll();
                continue;
            }
            work_flow.push_back(com);
            w_len = work_flow.size() -1; //only number is approved to be in work_flow
        }
        ss.clear();
    }
    return 0;
}