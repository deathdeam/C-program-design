#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

class A{
public:
    string name;
    int age;
    A(int k){setInfo(k); name = "A";};
    A (int k, string na):age(k),name(na){};
    void setInfo(int k){age = k;}
    bool operator<(const A& a) const{
        return age < a.age;
    }
    friend ostream & operator << (ostream & o,A& a){
        o << a.name << " " << a.age;
        return o;
    }
};
class B :public A{
public:
    B(int k):A(k,"B"){}
};

class Comp{
public:
    bool operator()(const A* a,const A *b) const{
        return a->age < b->age;
    }
};

struct print{
    void operator()(A& a){ cout << a <<endl;}
}Print;


int main()
{

    int t;
    cin >> t;
    set<A*,Comp> ct;
    while( t -- ) {
        int n;
        cin >> n;
        ct.clear();
        for( int i = 0;i < n; ++i)	{
            char c; int k;
            cin >> c >> k;

            if( c == 'A')
                ct.insert(new A(k));
            else
                ct.insert(new B(k));
        }
        cout << "done?" <<endl;
        for_each(ct.begin(),ct.end(),Print);
        cout << "****" << endl;
    }
}