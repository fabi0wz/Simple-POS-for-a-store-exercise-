#include <iostream>
#include <stdlib.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void ClrScr()
    {
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n" );
      //visto system cls ser uma ma pratica esta é a minha invencao para apagar o ecra xD
    }

void Stock ();
void CriarArtigo();

void AdicionarStock();
void Relatorios();
void Clientes();

void MainMenu(){

int escolha;

cout<<"===================================================== \n";
cout<<" \t\tMENU \t \n ";
cout<<"===================================================== \n";
cout<<" 1.Vendas\n";
cout<<" 2.Stock\n";
cout<<" 3.Relatorios \n";
cout<<" 4.Clientes \n";
cin >> escolha;

switch (escolha){
//case 1: Vendas(); break;
case 2: Stock();break;
case 3: Relatorios(); break;
case 4: Clientes(); break;
}
}

void Stock(){
    ClrScr();
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Artigo \n";
    cout << "2.Adicionar Stock \n";
    cout << "3.Eliminar Produto \n";
    cin >> escolha;

    switch (escolha){
    case 1: CriarArtigo(); break;
}
}
void Relatorios(){
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Relatorio \n";
    cout << "2.Relatorio por Produto \n";
    cout << "3.Relatorio Total \n";
    cin >> escolha;

}

void Clientes(){
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Clientes \n";
    cout << "2.Eliminar Clientes \n";
    cout << "3.Alterar Dados de Cliente \n";
    cin >> escolha;

}


void CriarArtigo(){

ClrScr();


double produtos [50][4] = { {125, 0, 5, 19.99},
                            {126, 1, 12, 4.99},
                            {127, 2, 26, 12.50},
                            {128, 3, 2, 10},
                            {129, 4, 50, 2.22}};
string nomeProdutos [50] = {"Mesa", "Cadeira", "Candeeiro", "Janela", "Banheira de Hidromagem"};

for (int i=0; i< 50; i++){

    if (produtos[i][0] == 0)
    cout << "Insira codigo do Produto" << endl;
    cin >> produtos[i][0];
    cout << "Insira o Nome do Produto" <<endl;
    cin >> nomeProdutos[i];
    cout << "Insira o Stock do Produto" << endl;
    cin >> produtos[i][2];
    cout << "Insira o preco custo do produto" << endl;
    cin >> produtos[i][3];
    break;
}

ClrScr();   
cout << "tem estes artigos em stock" << endl;

for (int i = 0; i<6; i++){
    cout << nomeProdutos[i];
}
}



int main(){

MainMenu();

}