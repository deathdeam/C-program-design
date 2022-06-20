#include <iostream>
#include <map>
using namespace std;
class A{
public:
    static int count;
    A(){count ++;}
    A(int a ){count ++;}
    A(A& a){count ++; }
    virtual ~A(){count--;cout << "A::deconstruct"<<endl;}
};
class B: public A{
public:
    B(){count++;}
    B(int a): A::A(a){}
    ~B(){
        cout<< "B::deconstruct" <<endl;}
};
int A::count = 0;
void func(B b) { }
int main()
{
    A a1(5),a2;// initialization
    cout << A::count << endl; //2
    B b1(4);
    cout << A::count << endl; // 3
    func(b1); //B::deconstruct \n A::deconstruct
    cout << A::count << endl;//3
    A * pa = new B(4);
    cout << A::count << endl; //4
    delete pa; //B A :: deconstruct
    cout << A::count << endl; //3
    return 0; // auto delete BAAA:deconstruct
}