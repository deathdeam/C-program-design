#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
string to_string(int a){
    string res;
    stringstream ss;
    ss << a;
    ss >> res;
    return res;
}
class largeint {
        public:
        string str;
        int length;
        largeint(string m) {
            str = m;
            length = str.length();
        }
        int compare(largeint& b);
        largeint& operator+(largeint& b);
        largeint& operator-(largeint& b);
        largeint& operator*(largeint& b);
        largeint& operator/(largeint& b);
};
int largeint::compare(largeint& b){
cout << "Compare"<< endl;
if(length > b.length){
return 1; // positive
}
else if (length < b.length){
return 0;
}
else{ // when the length is equal
for(int i = 0; i < length ; i++){
cout << str[i] << "  "<<b.str[i] <<endl;
if( str[i] >= b.str[i]){
return 1;
}
else{
return 0;
}
}
}
}
largeint& largeint::operator+(largeint& b) {
stringstream as, bs;
vector<string> r;
int ai, bi, res;
string temp;
for (int i = 0; i < length; i++) {
as << str[length-1-i]<<" ";
}
for (int j = 0; j < b.length; j++) {
bs << b.str[b.length-1-j]<<" ";
}
int max_len = max(length, b.length);
for (int k = 0; k < max_len; k++) {
as >> ai;
bs >> bi;
if (ai + bi +res >= 10) {
int reminder = (ai+bi+res)%10;
temp = to_string(reminder);
r.push_back(temp);
res = 1;
}
else{
int reminder = (ai+bi+res);
temp = to_string(reminder);
r.push_back(temp);
res = 0;}
ai = 0;bi=0;
}
if (res != 0){
temp = to_string(res);
r.push_back(temp);
}
str="";
for(vector<string>::reverse_iterator i = r.rbegin();i!= r.rend();++i){
str += *i;
}
cout << str<<endl;
return *this;
}
largeint& largeint::operator-(largeint& b){
stringstream as, bs;
vector<string> r;
int ai, bi, res,max_len = max(length, b.length);
string temp;
int state = compare(b);
for (int i = 0; i < length; i++) {
as << str[length - 1- i]<<" ";
}
for (int j = 0; j < b.length; j++) {
bs << b.str[b.length -1-j]<<" ";
}

for (int k = 0; k < max_len; k++) {
as >> ai;
bs >> bi;

if (state ==1) { //a > b
if (ai - bi + res < 0) {
int reminder = 10 + (ai - bi + res);
temp = to_string(reminder);
r.push_back(temp);
res = -1;
} else {
int reminder = (ai - bi + res);
temp = to_string(reminder);
r.push_back(temp);
res = 0;
}
}
else{ //a < b

if (bi - ai + res < 0) {
int reminder = 10+(bi - ai + res);
temp = to_string(reminder);
r.push_back(temp);
res = -1;
} else {
int reminder = bi - ai + res;
temp = to_string(reminder);
r.push_back(temp);
res = 0;
}

}

ai = 0;
bi = 0;

}
if (*(r.end()-1 )== "0"){
r.pop_back();
}
cout << r[0] << " " << r[1]  << endl;
if (state != 1){
string nga = "-";
r.push_back(nga);
}
str="";
for(vector<string>::reverse_iterator i = r.rbegin();i!= r.rend();++i){
str += *i;
}
cout << str<<endl;
return *this;
}
largeint& largeint::operator*(largeint& b){
stringstream as, bs;
cout << "multiply begin"<<endl;
vector<int> r(length+b.length,0),av,bv;
int ai, bi, res,reminder;
string temp;
for (int i = 0; i < length; i++) {
as << str[length - 1- i]<<" ";
as >> ai;
av.push_back(ai);
}
for (int j = 0; j < b.length; j++) {
bs << b.str[b.length -1-j]<<" ";
bs >> bi;
bv.push_back(bi);
}
for (int k = 0; k < b.length; k++) {
bi = bv[k];
for(int z = 0; z < length; z++){
ai = av[z];
reminder = (bi*ai+res+ r[k+z] )% 10;
res = (bi*ai+res) / 10;
r[k+z] = reminder;
cout << k+z<< " "<<bi<< " "<<ai<<" "<< reminder <<" "<<res<< endl;
}
}
if (res !=0){
r[b.length +length -1]=res;
}
str = "";
int state = 0;
for (vector<int>::reverse_iterator i=r.rbegin();i!= r.rend();i++ ){
if(*i!=0 || state == 1){
state = 1;
as << *i;
}
//as << *i;
}
as >> str;
cout << str<<endl;
return *this;
}
largeint& largeint::operator/(largeint& b){
int state = compare(b);
stringstream as, bs;
cout << "division begin"<<endl;
vector<int> r(length+b.length,0),av,bv;
int ai, bi, res,reminder;
int factor;
string temp;
if(state != 1){ // a < b;
str = "0";
}
else{
for (int i = 0; i < length; i++) {
as << str[i]<<" ";
as >> ai;
av.push_back(ai);
}
for (int j = 0; j < b.length; j++) {
bs << b.str[j]<<" ";
bs >> bi;
factor += bi*pow(10,j);
bv.push_back(bi);
}
int index=0;
int num = str[index] - '0';
cout<<"  "<<num<<endl;
while(factor > num){
num = num*10 + (str[++index] - '0');
}
cout << factor << " "<<num<<endl;
while(str.size() > index){
cout << "division p"<<endl;
temp +=(num /factor) +'0';
cout << temp<<endl;
num = (num%factor)*10+str[++index]-'0';
}
cout << "finished "<< temp<<endl;
str = temp;
if(str.length() == 0){
str="0";
}
cout << str<<endl;
return *this;

}
}
int main() {
    char* a = new char;
    char* b = new char;
    char symbol;

    cin >> a;
    cin >> symbol;
    cin >> b;
    largeint la(a),lb(b);
    if (symbol =='+'){
        largeint result = la+lb;cout<< result.str<<endl;
    }
    else if (symbol =='-'){
        largeint result = la-lb;cout<< result.str<<endl;
    }
    else if (symbol =='*'){
        largeint result = la*lb;cout<< result.str<<endl;
    }
    else if (symbol =='/'){
        largeint result = la/lb;cout<< result.str<<endl;
    }



    return 0;

}