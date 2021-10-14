#include <iostream>
#include "functions.h"
#include <fstream>
using namespace std;

int main(){
// ifstream invoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstin.txt", ios::binary);
ifstream invoer ("U:\\Semester1\\ProgrammeerMethoden\\CppOpdracht1\\main.cpp", ios::binary);
ofstream uitvoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstuit.txt", ios::out);
    bool print_mode=1,num_mode=0, reset; // Mode 1 is aan mode 0 is uit
    char kar, pre_kar,cnum;
    int raarnum=0, num,rest;
    int aantal_tabs=0, tab_diepte=2;
    int spaties,i;
    // cout << "Kies een tab diepte"<< endl;
    // cin >> tab_diepte;



    kar = invoer.get();
    
    while ( ! invoer.eof ( ) ) {
    
    // if (pre_kar==32 && kar==32){
    //     print_mode=0;
    // }

    if (pre_kar=='/' && kar=='/'){
        print_mode=0;
    }
    if (kar=='\n'){
        print_mode=1;
    }
    if (pre_kar=='{'){
        aantal_tabs+=1;
    }
    if (pre_kar=='}'){
        aantal_tabs-=1;
    }

    if (aantal_tabs>0 && pre_kar=='\n'){
        spaties=aantal_tabs*tab_diepte;
        for(i = spaties; i > 0; i--){
            uitvoer.put('.');
            cout << i << endl;
        }
    }
    
    
    // cout << aantal_tabs << endl;
    // cout << kar;

    if (kar!='/' && pre_kar!='/' && print_mode==1 && kar!='\n'){
        uitvoer.put (kar);
    }

    if (pre_kar=='/' && kar!='/' && print_mode==1){
        uitvoer.put(pre_kar);
        uitvoer.put(kar);
    }

    pre_kar=kar;
    kar=invoer.get();
    }

    invoer.close();
    uitvoer.close();
    
    return 1;
}
