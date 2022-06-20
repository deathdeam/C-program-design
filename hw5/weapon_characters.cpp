#include <iostream>
#include <ostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
class weapon{
public:
    friend class dragon;
    string w_name;
    const vector<string> weaponlst ={"sword","bomb","arrow"};
    weapon(int n){
        w_name = weaponlst[n];
    }
};
/*class sword:public weapon{

};
class bomb:public weapon{

};
class arrow:public weapon{

};*/
class hero{
public:
    int strength;
    int num;
    hero(int a ,int b){
        strength = a;
        num = b;
    }
};
class dragon:public hero{
public:
    string w; //n%3
    double morale;
    dragon(int a, int b,int m):hero(a,b){
        cout << m<<" "<<a<< endl;
        morale = (float)m/(float)a;
        weapon w1(num%3);
        w = w1.w_name;
        printf("it has a %s,and its morale is %.2f\n",w.c_str(),morale);
    };
};
class ninja:public hero{
public:
    string w_1; //n%3
    string w_2; //(n+1)%3
    ninja(int a,int b ):hero(a,b){
        weapon w1(num%3);
        weapon w2((num+1)%3);
        w_1 = w1.w_name;
        w_2 = w2.w_name;
        printf("it has a %s and a %s\n",w_1.c_str(),w_2.c_str());
    }
};
class iceman:public hero{
public:
    string w;//n%3
    iceman(int a, int b):hero(a,b){
        weapon w1(num%3);
        w = w1.w_name;
        printf("it has a %s\n",w.c_str());
    }
};
class lion:public hero{
public:
    int loyalty;
    lion(int a, int b, int m):hero(a,b){
        loyalty = m;
        printf("It's loyalty is %d\n",loyalty);
    };
};
class wolf:public hero{
public:
    wolf(int a, int b):hero(a,b){};
};
class Base{
private:
    int health=0;

    map<string,vector<int> > minions; //[minion name, {id, strength}]
public:
    const vector<string> r_order = { "iceman","lion","wolf","ninja","dragon"};
    const vector<string> b_order = { "lion","dragon","ninja","iceman","wolf"};
    vector<string> order;
    string color;
    int stop = 0;
    int tot_num = 0;
    Base(int n,int D, int N, int I, int L, int ,string c);  //initializations
    void notification(int time, string name,int stop,string color){
        if (stop ==0) {
            printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n", time, color.c_str(), name.c_str(),
                   tot_num, minions[name][1], minions[name][0], name.c_str(), color.c_str());
            if (name =="iceman"){
                iceman(minions[name][1],minions[name][0]);
            }
            else if (name == "dragon"){
                dragon(minions[name][1],minions[name][0],health);
            }
            else if (name == "ninja"){
                ninja(minions[name][1],minions[name][0]);
            }
            else if (name =="lion"){
                lion(minions[name][1],minions[name][0],health);
            }
            else{
                wolf(minions[name][1],minions[name][0]);
            }
        }
    }
    int creation(string name,int time){
        if (health >= minions[name][1]){
            health = health - minions[name][1];
            ++minions[name][0];
            ++tot_num;

        }
        else{
            stop = 1;}
        notification(time,name,stop,color);

        return stop;
    }

};

Base::Base(int n,int D, int N, int I, int L, int W,string c){
    color = c;
    health = n;
    minions["dragon"] = {0,D};
    minions["ninja"] = {0,N};
    minions["iceman"] = {0,I};
    minions["lion"] = {0,L};
    minions["wolf"] = {0,W};
    if(c== "red"){order = r_order;}
    else{order = b_order;}
}


int main()  {
    int id,M,c_dragon,c_ninja,c_iceman,c_lion,c_wolf;
    cin >> id;
    cin >> M;
    cin >>c_dragon>>c_ninja>>c_iceman>>c_lion>>c_wolf;
    Base red(M,c_dragon,c_ninja,c_iceman,c_lion,c_wolf,"red");
    Base blue(M,c_dragon,c_ninja,c_iceman,c_lion,c_wolf,"blue");
    int time = 0,j=0,k=0;
    cout << "Case:" <<id<<endl;
    int state = 0;
    while(state !=1 ){
        if (red.stop!= 1){
            for(int i = 0; i < 5;i++ ){
                j = j+i;
                if (red.creation(red.order[j%5],time) == 0){
                    break;
                }
                else if( i == 4){
                    printf( "%03d %s headquarter stops making warriors\n" ,time,red.color.c_str());
                }
                else{
                    continue;}
            }
        }
        if (blue.stop != 1) {
            for (int i = 0; i < 5; i++) {
                k = k + i;
                if (blue.creation(blue.order[k % 5], time) == 0){break;}
                else if (i == 4) {
                    printf("%03d %s headquarter stops making warriors\n", time, blue.color.c_str());
                }
                else { continue; }
            }
        }
        else{state = 1;}
        time++;
        j++;
        k++;

    }


    return 0;
}