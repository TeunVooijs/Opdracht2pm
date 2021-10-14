#include <iostream>
#include "functions.h"
#include <fstream>
using namespace std;


int main(){
// ifstream invoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstin.txt", ios::binary);
// ifstream invoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstin2.txt", ios::binary);
ifstream invoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstin3.txt", ios::binary);
ofstream uitvoer ("U:\\Semester1\\ProgrammeerMethoden\\Opdracht2\\tekstuit.txt", ios::out);
    bool print_mode=1,num_mode=0, newline_mode=0, comment_mode=0, space_mode=0; // Mode 1 is aan mode 0 is uit
    bool end;
    char kar, pre_kar,pre_pre_kar, cnum;
    int num, getal;
    int aantal_tabs=0, tab_diepte=4, spaties;
    int i,n,s;
    int match, matches;
    
    char t1=letter_invoer();
    char t2=letter_invoer(t1);
    char t3=letter_invoer(t1,t2);

    kar = invoer.get();
    
    while ( ! invoer.eof ( ) ) {
        if (pre_kar=='/' && kar=='/'){
            print_mode=0;
            comment_mode=1;
        }
        if (pre_kar=='\n'){
            print_mode=1;
            comment_mode=0;
        }
      
        if (kar==' ' && comment_mode==0){
            if ( pre_kar==32 || pre_kar=='\n'){
                space_mode=1;
            }
        }
        else if (kar!=' ' || comment_mode==1){
            space_mode=0;
        }        
        

        if (kar=='\n'){
            print_mode=0;
            if (comment_mode==1){
                uitvoer.put('\n');
                newline_mode=1;
                comment_mode=0;
            }
        }
        
        if (kar>='0' && kar<='9' && comment_mode==0){
            num=kar-48;
            end=0;
            getal=number_adder(getal, num, end);
        }
        else if(pre_kar>='0' && pre_kar<='9' && comment_mode==0){
            end=1;
            num=0;
            getal=number_adder(getal, num,end);
        }
        
        

        if (pre_kar=='{' && pre_pre_kar!=39){
            aantal_tabs+=1;
        }
        
        if (kar=='}' && pre_kar!= 39){
            aantal_tabs-=1;
        }
        // cout << aantal_tabs;
        if (aantal_tabs>0 && pre_kar=='\n'){
            spaties=aantal_tabs*tab_diepte;
            for(i = spaties; i > 0; i--){
                uitvoer.put('.');
            }
        }

        if (kar!='/' && pre_kar!='/' && print_mode==1 && space_mode==0){
        uitvoer.put (kar);
        }

        if (pre_kar=='/' && kar!='/' && print_mode==1){
            uitvoer.put(pre_kar);
            uitvoer.put(kar);
        }

        match=kar_test(kar, pre_kar, pre_pre_kar, t1, t2, t3);
        if (match==1){
            matches+=1;
        }

        n=kar;
        // cout << n << kar << space_mode << comment_mode <<  endl; 
        pre_pre_kar=pre_kar;
        pre_kar=kar;
        kar=invoer.get();
    }

    invoer.close();
    uitvoer.close();
    // cout << matches;
    return 1;
}

int kar_test(char kar, char pre_kar, char pre_pre_kar, char t1, char t2, char t3){
    int match=1;
    if (kar>=65 && kar<=90){
            kar+=32;
        }
    if (pre_kar>=65 && pre_kar<=90){
            pre_kar+=32;
        }
    if (pre_pre_kar>=65 && pre_pre_kar<=90){
            pre_pre_kar+=32;
        }
    if (kar==t3 && pre_kar==t2 && pre_pre_kar==t1){
        return match;       
    }
    return 0;
}

int number_adder(int getal ,int num, bool end){
    if (end==0){
        getal=(getal*10)+num;
        // cout << getal << endl;
        return getal;
    }
    else if (end==1){
        cout << getal << endl;
        // collatz(getal);
        getal=0;
        return getal;
    }
    return 0;
}

// void collatz(double getal){

// }

char letter_invoer(char t1 = '-', char t2 = '-'){
    char letter;
    while(true){
        cout << "Letter: " << endl;
        cin >> letter;
        if (letter>='a' && letter <='z'){
            if(letter != t1 && letter != t2){
                return letter;
            }
            else{
                cout << "is dubbel bruv" << endl;
            }
        }
        cout << "is grote letter a mattie" << endl;   
    }

}