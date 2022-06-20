#include <iostream>
#include <ostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class Base{
        private:

        map<string,vector<int> > minions; //[minion name, {id, strength}]
        public:
        int health;
        const char * r_order[5];
        const char * b_order[5];
        vector<string> order;
        string color;
        int stop;
        int tot_num;
        Base(int n,int D, int N, int I, int L, int ,string c);  //initializations
        void notification(int time, string name,int stop,string color){
            if (stop ==0) {
                printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n", time, color.c_str(), name.c_str(),
                       tot_num, minions[name][1], minions[name][0], name.c_str(), color.c_str());
            }
        }
        int creation(string name,int time){
            if (health >= minions[name][1]){
                health = health - minions[name][1];
                ++minions[name][0];
                ++tot_num;
                stop = 0;
            }
            else{
                stop = 1;}
            notification(time,name,stop,color);
            return stop;
        }

};
vector<string> a_v(const char* a[]){
    vector<string> result;
    for(char i = 0; i < 5;i++ ){
        result.push_back(a[i]);
    }
    return result;
}
Base::Base(int n,int D, int N, int I, int L, int W,string c){
    const char* r_order[5] ={ "iceman","lion","wolf","ninja","dragon"};
    const char* b_order[5] = { "lion","dragon","ninja","iceman","wolf"};
    stop = 0;
    tot_num = 0;
    health = 0;
    color = c;
    health = n;
    minions["dragon"] = {0,D};
    minions["ninja"] = {0,N};
    minions["iceman"] = {0,I};
    minions["lion"] = {0,L};
    minions["wolf"] = {0,W};
    if(c== "red"){order =a_v( r_order);}
        //convert array to vector
    else{order = a_v(b_order);}
}


int main()  {
    int case_id,M,c_dragon,c_ninja,c_iceman,c_lion,c_wolf;
    cin >> case_id;
    for(int z = 0; z != case_id;++z) {
        cin >> M;
        cin >> c_dragon >> c_ninja >> c_iceman >> c_lion >> c_wolf;
        Base red(M, c_dragon, c_ninja, c_iceman, c_lion, c_wolf, "red");
        Base blue(M, c_dragon, c_ninja, c_iceman, c_lion, c_wolf, "blue");
        int time = 0, j = 0, k = 0;
        cout << "Case:" << z+1 << endl;
        int state = 0;
        while (state != 1) {
            if (red.stop != 1) {
                for (int i = 0; i < 5; i++) {
                    //cout<< red.health<<" "<<j <<" "<< i<<" "<<red.order[j % 5]<<endl;
                    if (red.creation(red.order[j % 5], time) == 0) {
                        break;
                    } else if (i == 4) {
                        j +=1;
                        printf("%03d %s headquarter stops making warriors\n", time, red.color.c_str());
                    } else {
                        j += 1;
                        continue;
                    }
                }
            }
            if (blue.stop != 1) {
                for (int i = 0; i < 5; i++) {
                    //cout<< blue.health<<" "<<k <<" "<< i <<" "<<blue.order[k % 5]<<endl;
                    if (blue.creation(blue.order[k % 5], time) == 0) {break; }
                    else if (i == 4) {
                        k+=1;
                        printf("%03d %s headquarter stops making warriors\n", time, blue.color.c_str());
                    } else { k+=1;
                        continue; }
                }
            }
            if(blue.stop == 1 && red.stop ==1) {state = 1; }
            time++;
            j++;
            k++;
        }

    }
    return 0;
}