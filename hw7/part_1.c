#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class T>
class CArray3D{
        public:
        class y_array{
            public:
            class z_array{
                    public:
                    T* z_ray;
                    z_array(int c){
                        z_ray = new T[c];
                    }
                    z_array(){};

                    T& operator[](int k){

                        return z_ray[k];
                    }
            };
            z_array* y_ray;
            y_array(int b, int c){
                y_ray = new z_array [b];
                for(int i = 0; i < b; i++){
                    z_array z(c);
                    y_ray[i] = z;
                    //y_ray++;
                }
            }
            y_array(){};

            z_array& operator[](int j){

                return y_ray[j];
            }
        };
        y_array * ray;
        CArray3D(int a, int b, int c){

            ray = new y_array[a];
            for (int i =0; i < a;i++){

                y_array y(b,c);
                ray[i] = y;
                //ray++;

            }
        }
        y_array& operator[](int i){

            return ray[i];
        }

};
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k ){
                a[i][j][k] = No ++;
            }



    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}