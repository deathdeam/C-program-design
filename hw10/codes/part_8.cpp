#include <iostream>
#include <string>
#include <list>
#include <cmath>
using namespace std;
int product(int n , int i , int j){
    int result;
    int ith = (n>> i)&1; // ith num
    int jth = (n>> j)&1; // jth num

    if (ith != 0){ // &
        result += pow(2,i);
    }
    if (jth == 0){ // ~
        result += pow(2,j);
    }
    for (int k = i+1; k != j; k++){
        result += pow(2,k); // (i,j) are all 1s
    }
    return result;
}
int main()
{
    int num,n,i,j;
    cin >> num;
    for(int k = 0; k < num ; k++){
        cin >> n >> i >> j;
        cout <<hex<<product(n,i,j)<<endl;
    }
    return 0;
}


