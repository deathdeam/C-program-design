#include <iostream>
#include <string>
#include <list>
using namespace std;

class A{
private:
    string name;
public:
    A(string n) :name(n){}
    friend bool operator < (const class A& a1, const class A &a2);
    friend bool operator == (const class A &a1, const class A &a2){
        if (a1.name.size() == a2.name.size())
            return true;
        else
            return false;
    }
    friend ostream & operator << (ostream &o, const A &a){
        o << a.name;
        return o;
    }
    string get_name() const{
        return name;
    }
    int get_size() const{
        return name.size();
    }
};
// 在此处补充你的代码
bool operator < (const class A& a1, const class A &a2){
    return a1.get_size() < a2.get_size();
}
template <class T>
class MyLarge{
public:
    //MyLarge(){T ; };
    bool operator()(T a, T b){
        string ame = a.get_name();
        string bme = b.get_name();
        return ame[0] <bme[0];
    }
};
class Print{
public:
    Print(){};
    void operator()(A a){
        cout << a <<" ";
    }
};
template <class T1,class T2>
void Show(T1 a, T1 b,T2 fn){
    for(;a != b; a++){
        fn(*a);
    }
}


int main(int argc, char* argv[])
{
    list<A> lst;
    int ncase, n, i = 1;
    string s;
    cin >> ncase;
    while (ncase--){
        cout << "Case: "<<i++ << endl;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> s;
            lst.push_back(A(s));
        }
        lst.sort();
        Show(lst.begin(), lst.end(), Print());

        cout << endl;
        lst.sort(MyLarge<A>());
        Show(lst.begin(), lst.end(), Print());
        cout << endl;
        lst.clear();
    }
    return 0;
}


