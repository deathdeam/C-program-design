#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int a;
    cin >> a;
    cout << hex<< a<<endl;
    printf("%010d",a);
    return 0;
}