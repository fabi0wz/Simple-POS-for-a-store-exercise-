#include <iostream>
#include <stdlib.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void Stock ();
void CriarArtigo();

void AdicionarStock();
void Relatorios();
void Clientes();

double produtos [50][4] = { {125, 0, 5, 19.99},
                            {126, 1, 12, 4.99},
                            {127, 2, 26, 12.50},
                            {128, 3, 2, 10},
                            {129, 4, 50, 2.22}};
string nomeProdutos [50] = {"Mesa", "Cadeira", "Candeeiro", "Janela", "Banheira de Hidromagem"};

//Menu Principal
void MainMenu(){

system("CLS");

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
//Opcao Stock no Menu
void Stock(){
    system("cls");
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Artigo \n";
    cout << "2.Adicionar Stock \n";
    cout << "3.Eliminar Produto \n";
    cin >> escolha;

    switch (escolha){
    case 1: CriarArtigo(); break;}
}
//Opcao Relatorios no Menu
void Relatorios(){
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Relatorio \n";
    cout << "2.Relatorio por Produto \n";
    cout << "3.Relatorio Total \n";
    cin >> escolha;

}
//Opcao clientes no Menu
void Clientes(){
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Clientes \n";
    cout << "2.Eliminar Clientes \n";
    cout << "3.Alterar Dados de Cliente \n";
    cin >> escolha;

}

//Criar Artigos dentro do Stock
void CriarArtigo(){
int resposta;
system("CLS");

for (int i=0; i< 50; i++){
    if (produtos[i][0] == 0){
    cout << "Insira o codigo do Produto" << endl;
    cin >> produtos[i][0];
    cout << "Insira o Nome do Produto" <<endl;
    cin >> nomeProdutos[i];
    cout << "Insira o Stock do Produto" << endl;
    cin >> produtos[i][2];
    cout << "Insira o preco custo do produto" << endl;
    cin >> produtos[i][3];
    break;
    }
}
    cout << "Pretende adicionar mais artigos?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    cin >> resposta;
    if (resposta==1) {
        CriarArtigo();
    }
    else {
        MainMenu();
    }
}

void AdicionarStock(){

    system ("CLS");

    int resposta=0;

    cout << "A que produto pretende adicionar Stock?" << endl;
    cin >> resposta;

    for (int i=0; i< 50; i++){
        if (produtos[0][i] == resposta){
        cout << "Quantos produtos pretende adicionar?" << endl;
        cin >> resposta;
        produtos[2][i] = produtos[2][i]+resposta;
        }
    }
}

int main(){

MainMenu();

return 0;
}