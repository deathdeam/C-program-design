#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{   stringstream ss;
    double num;cin >> num;
    string str;
    ss << num;
    ss >> str;
    string non_science=str;
    string science;
    int sdot_index = str.find('.');
    int length = str.length();
    for (int i = 0; i < 5-(length-sdot_index-1); i++){
        non_science.push_back('0');
    }
    cout << non_science<<endl;
    int exp = 0;
    for(int j= 0; j < length; j++){
        if (str[j] == '.' && j != 1){ //for num larger than 1, decimal place means (the index of .) -1
            exp = j-1;
        }
        else if (str[j] == '0' && science.length() == 0) {// for num smaller than 1, decimal place is equal to #(0)before first digit
            exp -= 1;
        }
        else if(str[j] != '0' && str[j] !='.'){// first digit is a number
            science.push_back(str[j]);
            if(science.length() ==1){
                science.push_back('.');
            }
        }
    }
    int s_len = science.length();
    int dot_dex = science.find('.');
    for (int i = 0; i < 7-(s_len-dot_dex-1); i++){  //7 decimal places
        science.push_back('0');
    }
    if (exp <= 0){
        printf("%s",science.c_str());
        printf("e");
        printf("%03d \n",exp);
    }
    else{
        printf("%s",science.c_str());
        printf("e+");
        printf("%02d \n",exp);
    }
    return 0;
}