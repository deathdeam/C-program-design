
#include <iostream>
#include <string>
using namespace std;
template<class T>
class CMyistream_iterator{
    T* is = new T[32];
public:
    CMyistream_iterator(istream& a){

        T s;
        a.clear();
        int t = 0;
        //cout << "while loop ?" <<endl;
        while (a >> s){

            //cout<< s<<" "<<t <<endl;
            is[t] = s;
            //cout << is[t] <<endl;
            t++;
        }
        //cout << "end ?" <<endl;

         }
    CMyistream_iterator& operator++(){//front
        is++;
        return *is;
    }
    CMyistream_iterator operator++(int){ //behind
        CMyistream_iterator<T> temp(*this);
        is++;
        return temp;
    }
    T& operator*(){
        return is[0];}

};
int main() {
    //cout << "start" <<endl;
    CMyistream_iterator<int> inputInt(cin);
    //cout <<"initialization finished" <<endl;
    int n1,n2,n3;
    n1 = * inputInt; //读入 n1
    //cout << "successfully input "<<endl;
    int tmp = * inputInt;
    cout << tmp << endl;
    //cout << "increment started "<<endl;
    inputInt ++;
    n2 = * inputInt; //读入 n2
    inputInt ++;
    n3 = * inputInt; //读入 n3
    cout << n1 << "," << n2<< "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1,s2;
    //cout << "first element "<<endl;
    s1 = * inputStr;
    //cout << "increment started "<<endl;
    inputStr ++;
    s2 = * inputStr;
    cout << s1 << "," << s2 << endl;
    return 0;
}