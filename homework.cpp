#include <iostream>

using namespace std;

void put(double *p_array, int inx, double value, int &n, int size){
    if(inx > n || inx > size){
        cout<<"Out of bound!"<<endl;
        return;
    }
    p_array[inx] = value;
    n = (inx < n)? n+1: n;
}

int main(){

    double array[100] = {4,3,5,1};
    int n = 4;
    double *p_array = array;
    
    put(array, 4, 10, n, 100);
    put(array, 2, 100, n, 100);

    for(int i = 0; i < n; i++){
        cout<<"Value: "<<*(p_array+i)<<endl;
    }

    return 0;
}
