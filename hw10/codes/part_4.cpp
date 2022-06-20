#include <iostream>
using namespace std;
class CType{
public:
    int result[2];
    CType& setvalue(int & n){
        this->result[0] = n*n;
        this->result[1] = n;
        return *this;
    }
    int & operator++(){//front
        return *(result+1);
    }
    int& operator++(int a){
        return *(result +1);
    }
    friend ostream & operator<< (ostream & os, const CType& data);
};
ostream & operator<< (ostream & os, const CType& data){
    os<< data.result[0];
    return os;
}
int main(int argc, char* argv[]) {
    CType obj;
    int n;
    cin>>n;
    while ( n ) {
        obj.setvalue(n);
        cout<<obj++<<" "<<obj<<endl;
        cin>>n;
    }
    return 0;
}