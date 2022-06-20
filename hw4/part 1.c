
#include <sstream>
#include <string>

Complex & operator=(string str){
if(str =="")
{r= 0; i =0; return *this;}
else{
stringstream ss(str);
stringstream  is;
char o;
string real,image,tem;
for(int j = 0;j<str.size();j++){
ss>> o;
is.clear();
if (o =='+'){
is<< tem;
is >> r;
tem = "";
continue;
}
else if (o == 'i'){
is << tem;
is >> i;
}
tem.push_back(o);
}
return *this;}

}