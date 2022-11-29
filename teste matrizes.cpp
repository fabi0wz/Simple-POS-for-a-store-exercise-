#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
using namespace std;
void MainMenu (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);
void CriarArtigo (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);


void printstocks(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString)
{
    int a;
    for (int i = 0; i < 50; i++)
    {
        if (produtos[i][0] != 0)
        {
            cout << "Nome: " << nomeProdutos[i] << " | ";
            ;
            cout << "Codigo Produto: " << produtos[i][0] << " | ";
            cout << "Stock: " << produtos[i][1] << " | ";
            cout << "Preco: " << produtos[i][2] << " | ";
            cout << endl;
        }
    }
    for (int i = 0; i < 30; i++)
    {
        if (ClienteInt[i][0] != 0)
        {
            cout << "Codigo Cliente: " << ClienteInt[i][0] << " | ";
            ;
            cout << "Nome Cliente: " << ClienteString[i][0] << " | ";
            cout << "Contacto: " << ClienteInt[i][1] << " | ";
            cout << "Morada: " << ClienteString[i][1] << " | ";
            cout << endl;
        }
    }
    cin >> a;
}

void Stock(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString){
    system("cls");
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Artigo \n";
    cout << "2.Adicionar Stock \n";
    cout << "3.Eliminar Produto \n";
    cout << "0.Menu Principal \n";
    cin >> escolha;

    switch (escolha)
    {
    case 0:
        system("cls");
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString);
        break;
    case 1:
        system("cls");
        CriarArtigo(produtos, nomeProdutos, ClienteInt, ClienteString);
        break;
}
}

// Criar Artigos dentro do Stock
void CriarArtigo(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString)
{
    int resposta;
    system("cls");

    for (int i = 0; i < 50; i++)
    {
        if (produtos[i][0] == 0)
        {
            cout << "Insira o codigo do Produto" << endl;
            cin >> produtos[i][0];
            cout << "Insira o Nome do Produto" << endl;
            cin.ignore();
            getline(cin, nomeProdutos[i]);
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
    if (resposta == 1)
    {
        system("cls");
        CriarArtigo(produtos, nomeProdutos, ClienteInt, ClienteString);
    }
    else
    {
        system("cls");
        Stock(produtos, nomeProdutos, ClienteInt, ClienteString);
    }
}

void PreencherParaTeste (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString) {
    produtos[0][0] = 125;
    produtos[0][1] = 5;
    produtos[0][2] = 19.99;
    produtos[1][0] = 126;
    produtos[1][1] = 12;
    produtos[1][2] = 4.99;
    produtos[2][0] = 127;
    produtos[2][1] = 26;
    produtos[2][2] = 12.50;
    produtos[3][0] = 128;
    produtos[3][1] = 2;
    produtos[3][2] = 1.99;
    produtos[4][0] = 129;
    produtos[4][1] = 50;
    produtos[4][2] = 3.99;
    nomeProdutos[0] = "Mesa";
    nomeProdutos[1] = "Cadeira";
    nomeProdutos[2] = "Candeeiro";
    nomeProdutos[3] = "Janela";
    nomeProdutos[4] = "Tartaruga";

    ClienteInt[0][0] = 0001;
    ClienteInt[0][1] = 932885712;
    ClienteInt[1][0] = 0002;
    ClienteInt[1][1] = 978264019;
    ClienteInt[2][0] = 0003;
    ClienteInt[2][1] = 915274921;
    ClienteInt[3][0] = 0004;
    ClienteInt[3][1] = 927162542;

    ClienteString[0][0] = "Alberto";
    ClienteString[0][1] = "Rua dos Peregrinos n219";
    ClienteString[1][0] = "Claudete";
    ClienteString[1][1] = "Rua das Tangerinas n221";
    ClienteString[2][0] = "Filomena";
    ClienteString[2][1] = "Travessa das Travessas";
    ClienteString[3][0] = "Marca";
    ClienteString[3][1] = "Viela ao contrario";

}

void MainMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString){
     int escolha;
    cout << "===================================================== \n";
    cout << " \t\tMENU \t \n ";
    cout << "===================================================== \n";
    cout << " 1.Vendas\n";
    cout << " 2.Stock\n";
    cout << " 3.Relatorios \n";
    cout << " 4.Clientes \n";
    cout << endl;
    cin >> escolha;

    switch (escolha)
    {
    // case 1: Vendas(); break;
    case 2:
        system("cls");
        Stock(produtos, nomeProdutos, ClienteInt, ClienteString);
        break;
    case 99:
        system("cls");
        printstocks(produtos, nomeProdutos, ClienteInt, ClienteString);
    }
}


int main(){

    double ** produtos = new double *[50];
    for(int i = 0; i < 50; i++){
    produtos[i] = new double[3];
    }
    string * nomeProdutos = new string[50]; 

    int ** ClienteInt = new int *[30];
    for(int i = 0; i < 30; i++){
    ClienteInt[i] = new int[2];
    }

    string ** ClienteString = new string *[30];
    for(int i = 0; i < 30; i++){
    ClienteString[i] = new string[2];
    }

for(int i = 0; i < 50; i++){
    for(int j = 0; j < 3; j++){
        produtos[i][j] = 0;
    }
}
for(int i = 0; i < 50; i++){
nomeProdutos[i] = "";
}
for(int i = 0; i < 30; i++){
    for(int j = 0; j < 2; j++){
        ClienteInt[i][j] = 0;
        ClienteString[i][j] = "";
    }
}




    PreencherParaTeste(produtos, nomeProdutos, ClienteInt, ClienteString);


    MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString);

    return 0;
}




int Verificador(int aux){
    int escolha;
    if (aux == 1){
        if (!(cin >> escolha) || escolha < 1 || escolha > 4 || escolha != 99){
            do{
                if (!cin || escolha < 1 || escolha > 4 || escolha != 99){
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Insira uma Opcao Valida";
                    cout << "\x1b[2A\r";
                    cout << endl;
                }
            } 
            while (!(cin >> escolha) || escolha < 1 || escolha > 4 || escolha != 99);
        }
    }