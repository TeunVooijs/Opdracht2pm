#include <iostream>
#include "functions.h"
#include <fstream>
using namespace std;



int main(){
ifstream invoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstin.txt", ios::binary);
ofstream uitvoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstuit.txt", ios::out);
bool print_mode,num_mode;
char kar, pre_kar;
int num;

kar = invoer.get ( ); // eerst een maal get-ten!!!

while ( ! invoer.eof ( ) ) {
// Check 
if (kar>='0' && kar<='9'){
    print_mode=1;
    num_mode=1;
    num=kar-'0';
    number_adder(num);

}
else{
    num_mode=0;
}
if (num_mode==0){
    print_mode=0;
}




if (pre_kar=='/' && kar=='/'){
    print_mode=1;
}
else if (kar=='\n'){
    print_mode=0;
    // uitvoer.put(kar);
}   //controlle op nummer
else if (kar!='/' && pre_kar!='/' && print_mode==0){
    uitvoer.put (kar);
}
else if(pre_kar=='/' && kar!='/'&& print_mode==0){
    uitvoer.put (pre_kar);
    uitvoer.put (kar);
}



pre_kar=kar;
kar=invoer.get( );
}

invoer.close ( );
uitvoer.close ( );
    
    return 1;
}

int number_adder(int & num){
    int new_num;
    new_num=new_num*10;
    new_num+=num;
    

    return 0;
}

// int save_num (int & num){
//     return num;
// }



void swap(int & a, int & b){
    int c=a;
    a=b;
    b=c;
}

