#include <iostream>
#include <fstream>
using namespace std;


int collatz(int getal){
    int itterations=0;
    
    while (getal!=1){
        if (getal % 2==0){
            getal/=2;
        }
        else if (getal<=(INT_MAX-1)/3){
            getal= (getal *3) + 1;
            itterations+=1;
        }
        else{
            break;
        }
        itterations+=1;
    }
    cout << itterations << endl;

    return itterations;
}


int main(){
    int getal=3;
    // int test;
    // for (int i = 1; i <=getal ; i++){
    //     test=collatz(i);
    //     if (test>=150){
    //         cout << i << endl;
    //     }
    // }
    collatz(getal);

    return 0;
}


// 97 118
// 171 124