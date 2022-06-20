
class Array2{
        public:
        int r,c;
        int** arr;
        Array2();
        Array2(int m,int n);
        int* operator[](int a);
        int operator()(int a,int b);
        //ostream operator<<(int a);
        ~Array2(){
            for(int i = 0; i<r;i++){
                delete []arr[i];
            }
            delete []arr;
        };

};
Array2::Array2() {
    //cout<<"initialization start"<<endl;
    r =1;
    c =1;
    arr = new int*[1];
    //cout<<"row assigned"<<endl;
    for(int i =0;i <r;i++){
        //cout<<"column constructing"<<endl;
        arr[i]=new int[1];
    }
    //cout<<"initialization done"<<endl;
}
Array2::Array2(int m, int n) {
    //cout<<"initialization start"<<endl;
    r =m;
    c =n;
    //cout<<"value assigned"<<endl;
    arr = new int*[m];
    //cout<<"row assigned"<<endl;
    for(int i =0;i <r;i++){
        //cout<<"column constructing"<<endl;
        arr[i]=new int[n];
    }
    //cout<<"initialization done"<<endl;
}
int* Array2::operator[](int a){
    //cout<<"Arry2 [] done"<<endl;
    return arr[a];
}
int Array2::operator()(int a,int b){
    //cout<<"Arry2 () done"<<endl;
    return arr[a][b];
}
