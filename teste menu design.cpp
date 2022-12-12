#include <iostream>
#include "conmanip.h"
using namespace std;
using namespace conmanip;
// create a console context object, used for restoring console settings
console_out_context ctxout;
// create a console object
console_out conout(ctxout);


void welcome();
void mainmenu();
void PrintLojinha();
void printcomputer ();

void PrintLojinha(){

int middle = conout.getsize().X/2; //! cria o middle do ecra 

cout

<< setposx (middle-12) << setposy (2)
<< setposx (middle-12) <<"     _|=|__________" << endl
<< setposx (middle-12) <<"    /              \\" << endl
<< setposx (middle-12) <<"   /                \\" << endl
<< setposx (middle-12) <<"  /__________________\\" << endl
<< setposx (middle-12) <<"   ||  || /--\ ||  ||" << endl
<< setposx (middle-12) <<"   ||[]|| | .| ||[]||" << endl
<< setposx (middle-12) <<" ()||__||_|__|_||__||()" << endl
<< setposx (middle-12) <<"( )|-|-|-|====|-|-|-|( ) " << endl;

}

void printcomputer (){
int middle = conout.getsize().X/2; //! cria o middle do ecra 

cout
<< setposx (middle - (53/2)) <<"        ,------------------------------------," << endl
<< setposx (middle - (53/2)) <<"   ,-----------------------------------------------,"<< endl
<< setposx (middle - (53/2)) <<" ,/                                              ,/|"<< endl
<< setposx (middle - (53/2)) <<"+-----------------------------------------------+  |"<< endl
<< setposx (middle - (53/2)) <<"|  .-----------------------------------------.  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  |                                         |  |  |"<< endl
<< setposx (middle - (53/2)) <<"|  `-----------------------------------------'  |,/"<< endl
<< setposx (middle - (53/2)) <<" +-----------------------------------------------+  "<< endl
<< setposx (middle - (53/2)) <<"   /_)_____________________________________(_/ "<< endl
<< setposx (middle - (53/2)) <<"         ___________________________/___ " << endl
<< setposx (middle - (53/2)) <<"        /  oooooooooooooooo  .o.  oooo /, " << endl
<< setposx (middle - (53/2)) <<"       / ==ooooooooooooooo==.o.  ooo= / " << endl
<< setposx (middle - (53/2)) <<"      /_==__==========__==_ooo__ooo=_/' " << endl
<< setposx (middle - (53/2)) <<"      `-----------------------------'" << endl;
}

void welcome() {

int middle = conout.getsize().X/2; //! cria o middle do ecra 
// cout << setposx(middle-40)

PrintLojinha();

cout
<< endl
<<setposx ((middle-18))
                        <<".-----------------------------------." << endl
<<setposx ((middle-18)) <<"|                                   |" << endl
<<setposx ((middle-18)) <<"'-----------------------------------'"<< endl;
cout << setposx (middle-16) << setposy (12) << "bem vindo a melhor loja de sempre";

cout << setposx (middle -18) << setposy (29);

system("pause");
}



void mainmenu() {
system("cls");
conout.settitle("Melhor Loja de Sempre");
    cout
        << settextcolor(console_text_colors::light_yellow)
        << setbgcolor(console_bg_colors::cyan);
    
int a;

int middle = conout.getsize().X/2; //! cria o middle do ecra 
// cout << setposx(middle-40)

//printcomputer();

cout
<< endl
<<setposx ((middle-12)) << setposy (7)  //estava a 12
                        <<".-----------------." << endl
<<setposx ((middle-12)) <<"|                 |" << endl
<<setposx ((middle-12)) <<"|                 |" << endl
<<setposx ((middle-12)) <<"|                 |" << endl
<<setposx ((middle-12)) <<"|                 |"<< endl
<<setposx ((middle-12)) <<"'-----------------'"<< endl;


cout << setposx (middle-5) << setposy (6) << "MENU";
cout << setposx (middle-9) << setposy (8) << "1. Vendas";
cout << setposx (middle-9) << setposy (9) << "2. Stock";
cout << setposx (middle-9) << setposy (10) << "3. Relatorios";
cout << setposx (middle-9) << setposy (11) << "4. Clientes";
cout << setposx (middle -18) << setposy (15) << "insira uma opcao";

cout << setposx (middle-8) << setposy (14) << "inserir aqui";

cin >> a;
 }


int main () {

welcome();
mainmenu();

}