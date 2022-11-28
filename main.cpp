#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

// header para editar o terminal
#include "conmanip.h"
using namespace conmanip;
// create a console context object, used for restoring console settings
console_out_context ctxout;
// create a console object
console_out conout(ctxout);

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

//! so para testar
void printstocks();
void MainMenu();

//! Verificar se as opcoes que estao ser introduzidas pelo user sao validas
int Verificador(int aux){
    int escolha;
    if (aux == 1){
        if (!(cin >> escolha) || escolha < 1 || escolha > 4 || escolha == 99){
            do{
                if (!cin || escolha < 1 || escolha > 4){
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Insira uma Opcao Valida";
                    cout << "\x1b[2A\r";
                    cout << endl;
                }
            } 
            while (!(cin >> escolha) || escolha < 1 || escolha > 4 || escolha == 99);
        }
    }
    if (aux == 2){
        if (!(cin >> escolha) || escolha < 0 || escolha > 3){
            do{
                if (!cin || escolha < 0 || escolha > 3){
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Insira uma Opcao Valida";
                    cout << "\x1b[2A\r";
                    cout << endl;
                }
            } 
            while (!(cin >> escolha) || escolha < 0 || escolha > 3);
        } 
    }
        if (aux == 3){
        if (!(cin >> escolha)){
            do{
                if (!cin){
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Insira um Codigo de Produto Valido";
                    cout << "\x1b[2A\r";
                    cout << endl;
                }
            } 
            while (!(cin >> escolha));
        } 
    }
    return escolha;
}

//? Zona Stocks/Produtos
void Stock();
void CriarArtigo();
void AdicionarStock();
void EliminarArtigo();

//? Zona Relatorios
void Relatorios();

//? Zona Clientes
void Clientes();
void CriarCliente();
void EliminarCliente();
void AlterarNome();

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
/*
//! Variaveis Globais que depois precisam ser passadas para dinamicas no main *
//*Variaveis para produtos
double produtos[50][3] = {{125, 5, 19.99},
                          {126, 12, 4.99},
                          {127, 26, 12.50},
                          {128, 2, 10},
                          {129, 50, 2.22}};
string nomeProdutos[50] = {"Mesa", "Cadeira", "Candeeiro", "Janela", "Tartaruga"};

//*Variaveis para Clientes
long int ClienteInt[30][2] = {{0001, 932885712},
                              {0002, 978264019},
                              {0003, 915274921},
                              {0004, 927162542}};
string ClienteString[30][2] = {{"Alberto", "Rua dos Peregrinos n219"},
                               {"Claudete", "Rua das Tangerinas n221"},
                               {"Filomena", "Travessa das Travessas"},
                               {"Marca", "Viela ao contrario"}};
                               */

//? Zona Menu Principal
void MainMenu()
{
    int escolha;
    cout << "===================================================== \n";
    cout << " \t\tMENU \t \n ";
    cout << "===================================================== \n";
    cout << " 1.Vendas\n";
    cout << " 2.Stock\n";
    cout << " 3.Relatorios \n";
    cout << " 4.Clientes \n";
    cout << endl;
    // verificar se o CIN é o datatype definido
    escolha = Verificador(1);

    switch (escolha)
    {
    // case 1: Vendas(); break;
    case 2:
        system("cls");
        Stock();
        break;
    case 3:
        system("cls");
        Relatorios();
        break;
    case 4:
        system("cls");
        Clientes();
        break;
    case 99:
        system("cls");
        printstocks();
    }
}
// Opcao Stock no Menu
void Stock()
{
    system("cls");
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Artigo \n";
    cout << "2.Adicionar Stock \n";
    cout << "3.Eliminar Produto \n";
    cout << "0.Menu Principal \n";

    escolha = Verificador(2);

    switch (escolha)
    {
    case 0:
        system("cls");
        MainMenu();
        break;
    case 1:
        system("cls");
        CriarArtigo();
        break;
    case 2:
        system("cls");
        AdicionarStock();
        break;
    case 3:
        system("cls");
        EliminarArtigo();
        break;
    }
}

// Criar Artigos dentro do Stock
void CriarArtigo()
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
        CriarArtigo();
    }
    else
    {
        system("cls");
        Stock();
    }
}

// adicionar stock ao array Produtos
void AdicionarStock()
{
    int resposta;
    cout << "A que produto pretende adicionar Stock?" << endl;
    cout << "\n\n0. Voltar ao menu anterior\n";
    resposta == Verificador(3);

    for (int i = 0; i < 50; i++)
    {
        if (produtos[0][i] == resposta)
        {
            cout << "Pretende adicionar stock a " << nomeProdutos[i] << " ?\n";
            cout << "1. Sim\n2.Nao\n";
            cin >> resposta;
            if (resposta == 1)
            {
                cout << "Quanto pretende adicionar ao stock? \n";
                cin >> resposta;
                produtos[1][i] = produtos[2][i] + resposta;
                cout << "pretende adicionar mais stock? \n";
                cout << "1.Sim\n2.Nao\n";
                cin >> resposta;
                if (resposta == 1)
                {
                    AdicionarStock();
                }
                else if (resposta == 2)
                {
                    Stock();
                }
                else if (resposta > 2 || resposta < 0)
                {
                    AdicionarStock();
                }
            }
            else if (resposta == 2)
            {
                AdicionarStock();
            }
            else if (resposta == 0)
            {
                Stock();
            }
            else if (resposta > 2 || resposta < 0)
            {
                cout << "insira uma opcao valida \n";
                AdicionarStock();
            }
        }

    }
}

// Eliminar produto do array Produtos
void EliminarArtigo()
{

    int resposta;
    cout << "Insira o codigo do artigo que pretende eliminar \n";
    cout << "Ou insira 0 para voltar ao menu anterior\n";
    cin >> resposta;

    for (int i = 0; i < 50; i++)
    {
        if (produtos[i][0] == resposta)
        {
            if (produtos[i][0] != 0)
            {
                cout << "Deseja Eliminar " << nomeProdutos[i] << " ?\n";
                cout << "1. Sim \n2. Nao \n";
                cin >> resposta;
                if (resposta == 1)
                {
                    produtos[i][0] = 0;
                    produtos[i][1] = 0;
                    produtos[i][2] = 0;
                }
                else if (resposta == 2)
                {
                    EliminarArtigo();
                }
                else if (resposta == 0)
                {
                    Stock();
                }
                else if (resposta > 2 || resposta < 0)
                {
                    cout << "insira uma opcao valida \n";
                    EliminarArtigo();
                }
            }
            else
            {
                cout << "O Produto nao existe \n";
                EliminarArtigo();
            }
        }
    }
}

// Opcao Relatorios no Menu
void Relatorios()
{
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Relatorio \n";
    cout << "2.Relatorio por Produto \n";
    cout << "3.Relatorio Total \n";
    cin >> escolha;
}
// Opcao clientes no Menu
void Clientes()
{
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Clientes \n";
    cout << "2.Eliminar Clientes \n";
    cout << "3.Alterar Dados de Cliente \n";
    cout << "0.Voltar ao Menu Inicial\n";
    cin >> escolha;

    switch (escolha)
    {
    case 0:
        MainMenu();
        break;
    case 1:
        CriarCliente();
        break;
    case 2:
        EliminarCliente();
        break;
    case 3:
        AlterarNome();
        break;
    }
}

void CriarCliente()
{
    int resposta;
    system("cls");

    for (int i = 0; i < 50; i++)
    {
        if (ClienteInt[i][0] == 0)
        {
            cout << "Insira o ID do Cliente" << endl;
            cin >> ClienteInt[i][0];
            cout << "Insira o Nome do Cliente" << endl;
            cin.ignore();
            getline(cin, ClienteString[i][0]);
            cout << "Insira o Contacto do Cliente" << endl;
            cin >> ClienteInt[i][1];
            cout << "Insira a Morada do Cliente" << endl;
            cin.ignore();
            getline(cin, ClienteString[i][1]);
            break;
        }
    }
    cout << "Pretende adicionar mais Clientes?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    cin >> resposta;
    if (resposta == 1)
    {
        CriarCliente();
    }
    else
    {
        Clientes();
    }
}

void EliminarCliente()
{

    int resposta;
    cout << "Insira o codigo do cliente que pretende eliminar \n";
    cout << "Ou insira 0 para voltar ao menu anterior\n";
    cin >> resposta;

    for (int i = 0; i < 50; i++)
    {
        if (ClienteInt[i][0] == resposta)
        {
            if (ClienteInt[i][0] != 0)
            {
                cout << "Deseja Eliminar " << ClienteInt[i][0] << " | " << ClienteString[i][0] << " ?\n";
                cout << "1. Sim \n2. Nao \n";
                cin >> resposta;
                if (resposta == 1)
                {
                    produtos[i][0] = 0;
                    produtos[i][1] = 0;
                    produtos[i][2] = 0;
                }
                else if (resposta == 2)
                {
                    EliminarCliente();
                }
                else if (resposta == 0)
                {
                    Clientes();
                }
                else if (resposta > 2 || resposta < 0)
                {
                    cout << "insira uma opcao valida \n";
                    EliminarCliente();
                }
            }
            else
            {
                cout << "O Produto nao existe \n";
                EliminarArtigo();
            }
        }
    }
}

void AlterarNome()
{

    system("cls");

    int resposta = 0;
    string NovoNome;

    cout << "Insira o Codigo do Cliente que pretende alterar o nome" << endl;
    cout << "\n\n0. Voltar ao menu anterior\n";
    cin >> resposta;

    for (int i = 0; i < 50; i++)
    {
        if (ClienteInt[0][i] == resposta)
        {
            cout << "Pretende alterar o nome de" << ClienteInt[i][0] << " | " << ClienteString[i][0] << " ?\n";
            cout << "1. Sim\n2.Nao\n";
            cin >> resposta;
            if (resposta == 1)
            {
                cout << "Insira o nome a gravar \n";
                cin >> resposta;
                ClienteString[i][0] = NovoNome;
                cout << "Pretende Editar mais algum cliente? \n";
                cout << "1.Sim\n2.Nao\n";
                cin >> resposta;
                if (resposta == 1)
                {
                    AlterarNome();
                }
                else if (resposta == 2)
                {
                    Clientes();
                }
                else if (resposta > 2 || resposta < 0)
                {
                    AlterarNome();
                }
            }
            else if (resposta == 2)
            {
                AlterarNome();
            }
            else if (resposta == 0)
            {
                Clientes();
            }
            else if (resposta > 2 || resposta < 0)
            {
                cout << "insira uma opcao valida \n";
                AlterarNome();
            }
        }
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

    PreencherParaTeste();



    conout.settitle("Melhor Loja de Sempre");
    cout
        << settextcolor(console_text_colors::light_yellow)
        << setbgcolor(console_bg_colors::cyan)
        << "This text is colored: ";

    MainMenu();

    return 0;
}

void printstocks()
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

/*
-----------------------------2D ARRAYS --------------------------------
        COLUMN 0    COLUMN 1    COLUMN 2
ROW 0   x[0][0]     x[0][1]     x[0][2]
ROW 1   x[1][0]     x[1][1]     x[1][2]
ROW 2   x[2][0]     x[2][1]     x[2][2]

[y][x]
*/