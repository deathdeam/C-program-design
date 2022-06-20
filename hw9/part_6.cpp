#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
struct mycomp{
    int prime_factor(int a ){
        set<int> prime_set;
        int num =1,reminder =a;
        while(reminder != 1){
            for(int i = 2; i <= reminder;i++){//started from 2
                if (i == a){
                    return 0;
                }
                else if(reminder % i == 0 ){
                    reminder = reminder/i;
                    //cout << i << " ";
                    prime_set.insert(i);
                    break;
                }
            }
        }
        //cout << a <<" | "<<prime_set.size()<<endl;
        return prime_set.size();

    }
    bool operator()(const int & a, const int& b){
        int n1 =prime_factor(a);
        int n2 =prime_factor(b);
        if (n1 > n2){
            return false;
        }
        else if (n1 < n2){
            return true;
        }
        else{
            return a < b;
        }

    }
};

int main() {
    int num,input;
    mycomp compare;
    priority_queue< int,vector<int>, mycomp > pq,rq;
    cin >> num;
    for(int i =0; i< num*10;i++){
        cin >> input;
        pq.push( input );
        if(i%10 == 9){
            int len = pq.size();
            rq.empty();
            for(int i = 0; i < len; i++){
                //cout<<pq.top()<<endl;
                if (i == 0 ){
                    cout << pq.top() <<" ";
                    pq.pop();
                    continue;
                }
                else if (i == len-1){
                    cout << pq.top()<<endl;
                    pq.pop();
                    break;
                }
                rq.push(pq.top());
                pq.pop();
            }
            pq = rq;
        }

    }
    return 0;
}