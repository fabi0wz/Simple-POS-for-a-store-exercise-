#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//so para testar
void printstocks();

//so para testar
void Stock ();
void CriarArtigo();
void EliminarArtigo();

void AdicionarStock();
void Relatorios();
void Clientes();

double produtos [50][3] = { {125, 5, 19.99},
                            {126, 12, 4.99},
                            {127, 26, 12.50},
                            {128, 2, 10},
                            {129, 50, 2.22}};
string nomeProdutos [50] = {"Mesa", "Cadeira", "Candeeiro", "Janela", "Tartaruga"};

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
    case 99: printstocks();
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
    cout << "0.Menu Principal \n";
    cin >> escolha;

    switch (escolha){
    case 0: MainMenu(); break;
    case 1: CriarArtigo(); break;
    case 2: AdicionarStock(); break;
    case 3: EliminarArtigo(); break;
    }
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
    cin >> produtos[i][1];
    cout << "Insira o preco custo do produto" << endl;
    cin >> produtos[i][2];
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
        Stock();
    }
}

void AdicionarStock(){

    system ("CLS");

    int resposta=0;

    cout << "A que produto pretende adicionar Stock?" << endl;
    cout << "\n\n0. Voltar ao menu anterior\n";
    cin >> resposta;

    for (int i=0; i< 50; i++){
        if (produtos[0][i] == resposta){
            cout << "Pretende adicionar stock a " << nomeProdutos[i] << " ?\n";
            cout << "1. Sim\n2.Nao\n";
            cin >> resposta;
            if (resposta==1) {
                cout << "Quanto pretende adicionar ao stock? \n";
                cin >> resposta;
                produtos[1][i] = produtos[2][i]+resposta;
                cout << "pretende adicionar mais stock? \n";
                cout << "1.Sim\n2.Nao\n";
                cin >> resposta;
                    if (resposta==1){
                        AdicionarStock();
                    }
                    else if(resposta==2){
                        Stock();
                    }
                    else if (resposta >2 || resposta < 0) {
                        AdicionarStock();
                    }
            }
            else if (resposta==2){
                AdicionarStock();
            }
            else if (resposta == 0){
                Stock();
            }
            else if (resposta > 2 || resposta < 0){
                cout << "insira uma opcao valida \n" ;
                AdicionarStock();
            }
        }
    }
}

void EliminarArtigo(){

    int resposta;
    cout << "Insira o codigo do artigo que pretende eliminar \n";
    cout << "Ou insira 0 para voltar ao menu anterior\n";
    cin >> resposta;

        for (int i=0; i< 50; i++){
            if (produtos[i][0] == resposta){
                if (produtos[i][0] != 0){
                    cout << "Deseja Eliminar " << nomeProdutos[i] << " ?\n";
                    cout << "1. Sim \n2. Nao \n";
                    cin >> resposta;
                        if (resposta==1) {
                            produtos[i][0] = 0;
                            produtos[i][1] = 0;
                            produtos[i][2] = 0;
                        }
                        else if (resposta==2){
                            EliminarArtigo();
                        }
                        else if (resposta == 0){
                            Stock();
                        }   
                        else if (resposta > 2 || resposta < 0){
                            cout << "insira uma opcao valida \n" ;
                            EliminarArtigo();
                        }
                }
                else{
                    cout << "O Produto nao existe \n";
                    EliminarArtigo();
                }
         }
    }
}

int main(){

MainMenu();

return 0;
}



void printstocks(){
    int a;
    for (int i=0; i< 50; i++){
        if (produtos[i][0] != 0){
            cout << "Nome: " << nomeProdutos[i] << " | ";;
            cout << "Codigo Produto: " << produtos[i][0] << " | ";
            cout << "Stock: " << produtos[i][1] << " | ";
            cout << "Preco: " << produtos[i][2] << " | ";
            cout << endl;
        }     
     }
    cin >> a;
}



/*
-----------------------------2D ARRAYS --------------------------------
        COLUMN 0    COLUMN 1    COLUMN 2
ROW 0   x[0][0]     x[0][1]     x[0][2]
ROW 1   x[1][0]     x[1][1]     x[1][2]
ROW 2   x[2][0]     x[2][1]     x[2][2]

[y][x]
*/