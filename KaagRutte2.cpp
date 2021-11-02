#include <iostream>
#include <fstream>
using namespace std;

// Maker: Teun Vooijs
// Studiejaar: 2021-2022
// Studierichting & student nummer: Informatica     3405389
// Opdracht: Programmeeropdracht 2 "Netjes"
// Datum gemaakt: 17-10-2021
// Compiler: g++ 8.1.0 visual studio code

// De gebruiker moet een invoer file en uitvoer file in het programma zetten
// Dan als je het programma start, wordt er gevraagd naar de hoeveelheid spaties
// die het programma per tab moet doen
// Dan worden er 3 letters gevraagd 1 voor 1. Het programma gaat dan kijken
// hoe vaak deze letters voorkomen in de opgegeven volgorde
// en het programma zal per getal kijken hoeveel iteraties het kost van het
// collatz vermoeden om bij 1 uit te komen en dit per getal printen

void infoblokje(){
    cout << "Maker: Teun Vooijs" << endl <<
            "Studiejaar: 2021-2022"
            "Studierichting & student nummer: Informatica     3405389" << endl <<
            "Opdracht: Programmeeropdracht 2 \"Netjes\""<< endl <<
            "Datum gemaakt: 17-10-2021"<< endl << endl <<
            
            "De gebruiker moet een invoer file en uitvoer file in het programma zetten"<< endl <<
            "Dan als je het programma start, wordt er gevraagd naar de hoeveelheid spaties"<< endl <<
            "die het programma per tab moet doen"<< endl <<
            "Dan worden er 3 letters gevraagd 1 voor 1. Het programma gaat dan kijken"<< endl <<
            "hoe vaak deze letters voorkomen in de opgegeven volgorde"<< endl <<
            "en het programma zal per getal kijken hoeveel iteraties het kost van het"<< endl <<
            "collatz vermoeden om bij 1 uit te komen en dit per getal printen" << endl << endl;
}

// Deze functie test of de charakters die binnenkomen overeenkomen
// met de opgegeven controle letters, wannneer dat zo is returned de functie dit
// en hoevaak dat gebeurt wordt in main opgeteld.
int char_test(char Cchar, char pre_char, char pre_pre_char, char t1, char t2, char t3){
    int match=1;
    if (Cchar>=65 && Cchar<=90){
            Cchar+=32;
        }
    if (pre_char>=65 && pre_char<=90){
            pre_char+=32;
        }
    if (pre_pre_char>=65 && pre_pre_char<=90){
            pre_pre_char+=32;
        }
    if (Cchar==t3 && pre_char==t2 && pre_pre_char==t1){
        return match;       
    }
    return 0;
}

// Wanneer het programma een nummer tegenkomt zal hij hier het gehele nummer vormen
// en dit naar de main returnen
int number_adder(int getal ,int num){
        getal=(getal*10)+num;
        return getal;
}

// Hier word het het vermoeden van collatz gecontroleerd
// wanneer het getal over de intmax heengaat, word de hoeveelheid iteraties geprint
// en aangegen dat het over de intmax heengaat. Anders word de hoeveelheid iteraties
// aangegeven om bij 1 te komen
void collatz(int getal){
    int itteration=0;
    cout << getal << "  .....  ";
    while (getal!=1){
        if (getal % 2 == 0){
            getal/=2;
            itteration+=1;
        } 
        else if (getal<=(INT_MAX-1)/3){
                getal= (getal *3) + 1;
                itteration+=1;
        }
        else{
            cout << "Te groot bij itteratie: ";
            break;
        }
        }
    cout << itteration << endl;
}

// Deze functie controleerd of de letters die worden ingevoerd verschillend zijn
// en of ze kleine letters zijn, anders word aangegeven dat het fout is
// en moet de gebruiker een nieuwe, niet grote of zelfde letter invullen
char letter_invoer(char t1 = '-', char t2 = '-'){
    char letter;
    while(true){
        cout << ": ";
        cin >> letter;
        if (letter>='a' && letter <='z'){
            if(letter != t1 && letter != t2){
                return letter;
            }
            else{
                cout << "Deze letter is al een keer gebruikt" << endl;
            }
        }
        cout << "Graag een kleine letter geven " << endl;   
    }

}

int main(){
    // Hier moeten de invoer en uitvoer files worden ingevuld
    // ios::binary moet mogelijk worden veranders naar ios::in
    ifstream input ("invoerfile.txt", ios::binary);
    ofstream output ("uitvoerfile.txt", ios::out);
    
    // Modes voor bepaalde dingen waarbij mode 1 is aan mode 0 is uit
    // Print mode laat printen, comment mode geeft aan of commentaar
    // space mode is na een "\n" zodat alle tabs en spaties niet worden geprint
    bool print_mode=1, comment_mode=0, space_mode=0; 
    // De karakters die uit de tekst worden genomen
    char Cchar, pre_char,pre_pre_char; 
    // Variabelen voor optelen van getallen in het bestand
    // num is nieuwe nummer dat word gelezen, getal is het gevormde getal
    int num, getal;
    // Variabelen voor de diepte van de tabs en hoeveelheid tabs
    // i is variabele voor de for-loop
    int aantal_tabs=0, tab_diepte, spaties, i;
    // Variabelen voor de hoeveelheid keren dat de drie letters overeenkomen
    int match, matches=0;
    
    
    infoblokje();
    
    // Hier wordt het aantal spaties per tab gevraagd
    cout << "Geef de hoeveelheid spaties voor een tab: " << endl;
    cin >> tab_diepte;

    // Hier worden de letters aan de gebruiker gevraagd
    cout << "Geef 3 letters los van elkaar, allemaal klein en verschillend";
    char t1=letter_invoer();
    char t2=letter_invoer(t1);
    char t3=letter_invoer(t1,t2);

    Cchar = input.get();
    
    // De while loop die alle karakters eén voor één langsgaat
    while (!input.eof()){

        // Hier wordt gecontroleerd of er een comment is
        if (pre_char=='/' && Cchar=='/'){
            print_mode=0;
            comment_mode=1;
        }

        // Hier word aan het einde van een regel de comment mode uitgezet
        // zodat er weer geprint kan worden
        if (pre_char=='\n'){
            print_mode=1;
            comment_mode=0;
        }

        // Wanneer er spaties zijn aan het begin van een regel wordt space mode 1
        // dit zorgt ervoor dat de spaties niet worden getypt
        // dit geldt ook voor tabs
        if (Cchar==' ' && comment_mode==0){
            if ( pre_char==32 || pre_char=='\n'){
                space_mode=1;
            }
        }
        else if(Cchar==9){
            space_mode=1;
        }
        else if (Cchar!=' ' || comment_mode==1){
            space_mode=0;
        }        
        
        // Als de tekst naar een nieuwe regel gaat, zal er niet worden geprint
        if (Cchar=='\n'){
            print_mode=0;
            if (comment_mode==1){
                output.put('\n');
                comment_mode=0;
            }
        }
        
        // Wanneer er een getal word gelezen ziet dit deel het en wordt
        // het 1 volledig nummer gemaakt en getest op collatz
        if (Cchar>='0' && Cchar <= '9' && comment_mode==0){
            num = Cchar-48;
            getal=number_adder(getal,num);
        }
        else if(pre_char>='0' && pre_char <= '9' && getal!=0 && comment_mode==0){
            collatz(getal);
            getal=0;
        }

        // Hier wordt de aantal tabs meer en minder gemaakt 
        // wanneer er buiten een comment een accolade wordt gelezen
        if (pre_char=='{' && pre_pre_char!=39 && comment_mode==0){
            aantal_tabs+=1;
        }
        if (Cchar=='}' && pre_char!= 39 && comment_mode==0){
            aantal_tabs-=1;
        }

        // Dit print spaties wanneer het aantal tabs niet 0 is
        if (aantal_tabs>0 && pre_char=='\n'){
            spaties=aantal_tabs*tab_diepte;
            for(i = spaties; i > 0; i--){
                output.put(' ');
            }
        }

        // Typen wanneer er geen commentaar of nieuwe regel is
        if (Cchar!='/' && pre_char!='/' && print_mode==1 && space_mode==0){
            output.put (Cchar);
        }

        // Wanneer er een "/" in de tekst staat als niet commentaar
        // wordt deze hier nog getypt
        if (pre_char=='/' && Cchar!='/' && print_mode==1){
            output.put(pre_char);
            output.put(Cchar);
        }

        // Optellen aantal keren dat de controle letters overeenkomen
        match=char_test(Cchar, pre_char, pre_pre_char, t1, t2, t3);
        if (match==1){
            matches+=1;
        }
        // Karakters worden naar vorig en vorig vorig karakter gezet
        // dit word gedaan voor het controleren van bijvoorbeeld overeen komen
        // van letter met controle letters
        pre_pre_char=pre_char;
        pre_char=Cchar;
        Cchar=input.get();
    }

    // Dit is er zodat als de laatste karakters getallen zijn 
    //het alsnog wordt getest op collatz
    if(getal!=0){
        collatz(getal);
    }

    // Wanneer er teveel open of sluit accolades zijn wordt dat hier geprint
    // en wordt er aangegeven hoeveel en van welke dat is
    if (aantal_tabs!=0){
        cout << "Het aantal accolades klopt niet"
        ", er zijn " << aantal_tabs << " accolades" << endl << 
        "(Bij een negatief getal zijn er teveel sluit-accolades"
        " bij een positief getal teveel openings-accolades)" << endl;
    }

    // Hier wordt het aantal keren dat de letters voorkomen geprint
    cout << "De letter volgorde \"" << t1 << t2 << t3 << "\" komt: "
    << matches << " keer voor" << endl;
    
    input.close();
    output.close();
    return 1;
}

