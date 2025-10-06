#include <iostream>

using namespace std;

void put(double *p_array, int size,int index_insert,int number_insert,int del_index){

    for (int i = size; i > index_insert; i--)
    {
        p_array[i] = p_array[i-1];
    }
        p_array[index_insert] = number_insert;       

        for (int i = del_index; i <size  ; i++)
        {
            p_array[i] = p_array[i+1];
        }
    }
int main(){

    double array[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "input element of array:" << endl;
        cin >> array[i];
    }
    double *p_array = array;
    int insert;
    int del;
    int number;
    cout << " input index of insert array:" << endl;
    cin >> insert;
    cout <<"input number you want to insert:"<<endl;
    cin >> number;
    cout << "input index of delete element:" << endl;
    cin >> del;
    put(array,5,insert,number,del);
    for(int i = 0; i < 5; i++){
            cout<<"Value: "<<*(p_array+i)<<endl;
    }
    return 0;
}