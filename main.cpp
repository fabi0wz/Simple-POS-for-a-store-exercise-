#include <iostream> //cout cin etc
#include <string> //usar strings
#include <time.h> // para poder ter time to system para imprimir na fatura
#include <math.h> // para poder usar ceil(a * 100.0) / 100.0 --> arrendonda o valor de a para 2 decimais 

//?Libraria para editar posicao do cursor
#include "conmanip.h"
using namespace conmanip;
//cria um objeto contexto consola, usado para repor as settings
console_out_context ctxout;
//cria um objeto consola
console_out conout(ctxout);
int middleX = conout.getsize().X/2; //! cria o middle do ecra 
int middleY = conout.getsize().Y/2;
//?fim

using namespace std;

//! so para testar
void printstocks(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int aux2);
void printVendas(int **StoreVendas);
int Verificador(int aux);
void printTime();

void printFatura(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int aux2);

//?imprimir menus
void welcome();
void PrintLojinha();
void printMainMenu();
void printMenuCompras(double **produtos, string *nomeProdutos, int size[]);


void WelcomeMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas);
void MainMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas);

//void MainMenuFuncionario (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);
//? Zona Vendas
void MenuVendas (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas);
double Vendas(double **produtos, string *nomeProdutos, int **StoreVendas, int numeroVenda);
void InserirNumeroCliente(int **ClienteInt, string **ClienteString, double **InfoVendas, int numeroVenda);
void Checkout (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda, double total);
void printFatura (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda);

//? Zona Stocks/Produtos
void Stock(double **produtos, string *nomeProdutos);
void CriarArtigo(double **produtos, string *nomeProdutos);
void AdicionarStock(double **produtos, string *nomeProdutos);
void EliminarArtigo(double **produtos, string *nomeProdutos);

//? Zona Relatorios
void Relatorios(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);

//? Zona Clientes
void Clientes(int **ClienteInt, string **ClienteString);
void CriarCliente(int **ClienteInt, string **ClienteString);
void EliminarCliente(int **ClienteInt, string **ClienteString);
void AlterarNome(int **ClienteInt, string **ClienteString);

//!Preencher o os stocks/clientes para testes
void PreencherParaTeste (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);

//! M A I N  M A I N  M A I N  M A I N 
//! M A I N  M A I N  M A I N  M A I N  
int main(){

    //!Declarar matriz produtos
    double ** produtos = new double *[50];
    for(int i = 0; i < 50; i++){
        produtos[i] = new double[4];
    }

    //!Declarar vetor nomeProdutos (string -> nome dos produtos)
    string * nomeProdutos = new string[50]; 

    //!Declarar matriz ClienteInt (numero cliente, contacto e nif)
    int ** ClienteInt = new int *[50];
    for(int i = 0; i < 50; i++){
        ClienteInt[i] = new int[2];
    }

    //!Declarar vetor ClienteString (nome do cliente)
    string ** ClienteString = new string *[50];
    for (int i = 0; i < 50; i++){
        ClienteString[i] = new string[2];
    }

    //!declarar matriz StoreVendas (guarda numero da venda e a quantidade de produto)
    int ** StoreVendas = new int *[100];
    for(int i = 0; i < 100; i++)
    {
    StoreVendas[i] = new int[51];
    }

    //!Declarar matriz InfoVendas (Guarda o numero de cliente, o preco total, quantidade entregue, e troco dado ao cliente)
    double **InfoVendas = new double *[100];
    for (int i = 0; i < 100; i++){
        InfoVendas[i] = new double [4];
    }

    //!Inicializar ClienteString a ""
    for(int i = 0; i < 50; i++){
    ClienteString[i] = new string[2];
    }

    //!Inicializar produtos a 0
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 4; j++){
            produtos[i][j] = 0;
        }
    }

    //!Inicializar nomeProdutos a ""
    for(int i = 0; i < 50; i++){
        nomeProdutos[i] = "";
    }
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 2; j++){
            ClienteInt[i][j] = 0;
            ClienteString[i][j] = "";
        }
    }

    //!Inicilizar matriz StoreVendas a 0 (Guarda as quantidades das vendas da matriz Vendas)
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 51; j++)
        {
            StoreVendas[i][j] = 0;
        }
    }

    //!Inicilizar matriz InfoVendas a 0 (Guarda as quantidades das vendas da matriz Vendas)
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            InfoVendas[i][j] = 0;
        }
    }

    //Preenche os produtos e clientes com valores default //!falta adicionar o das vendas para tambem preencher com alguns valores default
    PreencherParaTeste(produtos, nomeProdutos, ClienteInt, ClienteString);
    welcome();
    MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);

    return 0;
}

//? Zona Menu Principal
void MainMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas)
{
    const int VENDAS = 1, STOCK = 2, RELATORIOS = 3, CLIENTES = 4;
    int escolha;
    system("cls");
    printMainMenu();

    // verificar se o CIN é o datatype definido
    escolha = Verificador(1);

    switch (escolha)
    {
    case VENDAS:
        MenuVendas(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        break;
    case STOCK:
        system("cls");
        Stock(produtos, nomeProdutos);
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        break;
    case RELATORIOS:
        system("cls");
        Relatorios(produtos, nomeProdutos, ClienteInt, ClienteString);
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        break;
    case CLIENTES:
        system("cls");
        Clientes(ClienteInt, ClienteString);
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        break;
    case 99:
        system("cls");
        printstocks(produtos, nomeProdutos, ClienteInt, ClienteString, 2);
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        break;
    case 98:
        system("cls");
        printstocks(produtos, nomeProdutos, ClienteInt, ClienteString, 1);
        printVendas(StoreVendas);
        MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
        break;
    }
}

//!Opcao Vendas no Menu
void MenuVendas (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas){

    int numeroVenda;
    double subtotal = 0;
    double total = 0;
    if (subtotal == 0){ //se o subtotal for 0, quer dizer que é uma nova venda, logo procura por um valor livre no numero da venda;
        //!procura por uma posicao livre (a 0) na primeira coluna da matriz, e define a index dessa linha como o numero da venda
        for (int i =0; i<100; i++){
            if (StoreVendas[i][0] == 0){
                numeroVenda = i;
                StoreVendas[i][0] = numeroVenda + 1;
            }
            break;
        }
    }
    subtotal = Vendas (produtos, nomeProdutos, StoreVendas, numeroVenda); //Entra logo na funcao de Vendas, onde escolhe os produtos para adicionar ao cart
    InfoVendas[numeroVenda][1] = subtotal; // guarda o valor do subtotal na matriz de info sobre a venda
    total = (subtotal + (subtotal * 0.3)) + (subtotal * 0.23);
    
    if (subtotal != 0) {

        InserirNumeroCliente(ClienteInt, ClienteString, InfoVendas, numeroVenda); //adicionar numero cliente na fatura
        
        system ("cls");
        int escolha;
        cout << "1. Checkout" << endl
            << "2. Cancelar Venda" << endl;
        cin >> escolha;

        switch (escolha){
        case 1:

            Checkout (produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas, numeroVenda, total);
            break;
        
        case 2:
            for (int i = 0; i< 51; i++){
                produtos[i][1] = produtos[i][1] + StoreVendas[numeroVenda][i+1]; //volta a adicionar as quantidades retiradas ao stock
                StoreVendas[numeroVenda][i] = 0; //poe a linha da coluna a 0
                InfoVendas[numeroVenda][i] = 0;
            }
            break;
        }
    }
}

double Vendas (double **produtos, string *nomeProdutos, int **StoreVendas, int numeroVenda){

    double subtotal = 0;
    int choice = 99, quantidade, tamanho = 0;

    int size [50] = { 0 }; //vetor para determinar tamanho da matriz de produtos para print
    
    //determina tamanho da matriz de produtos
    for (int i = 0; i<50; i++){
        if (produtos[i][0] != 0){
            size[i] = 1;
            tamanho++; //tamanho das escolhas 1 a x
        }
    }

    while (choice != 0){
        printMenuCompras(produtos, nomeProdutos, size);
        cout << "0. Exit" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        while (cin.fail()){
            cout << "Selecione uma opcao valida" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
        if (choice == 0){
            break;
        }

        if (choice <= tamanho && choice > 0){
            cout << "Introduza a Quantidade " << endl;
            cin >> quantidade;
                if (quantidade > produtos[choice - 1][1]){
                    cout << "Quantidade indisponivel" << endl;
                    quantidade = 0;
                }
            subtotal = subtotal + (quantidade * produtos[choice-1][2]);// calcula o valor subtotal (sem iva e sem lucro)
            StoreVendas[numeroVenda][choice] = StoreVendas[numeroVenda][choice] + quantidade; // guarda o index no index do produto a quantidade vendida
            produtos[choice-1][1] = (produtos[choice -1][1] - quantidade); //remove a quantidade escolhida do stock
        }
        cout << "total c/Iva: " << ceil(((subtotal + (subtotal * 0.3)) + (subtotal * 0.23))*100.0) / 100.0 << endl; //arrendondar a 2 decimais ceil(valor * 100.0) / 100.0
    }
    return subtotal;
}

void InserirNumeroCliente(int **ClienteInt, string **ClienteString, double **InfoVendas, int numeroVenda){

    int escolha;

    cout << "Pretende Adicionar Numero de Cliente?" << endl
         << "1. Sim" << endl
         << "2. Nao, Prosseguir com checkout" << endl;
    cin >> escolha;

    if (escolha == 1){

        int numCliente;
        cout << "Insira numero do cliente" << endl;
        cin >> numCliente;

        for (int i = 0; i < 50; i++){
            if (numCliente == ClienteInt[i][0]){
                cout << "entrou aqui";
                InfoVendas[numeroVenda][0] = numCliente;
            }
        }
        int escolha = 99;

        if(InfoVendas[numeroVenda][0] == 0 ){
            cout << "entrou aqui 2";
            while(InfoVendas[numeroVenda][0] == 0 || escolha != 0){
                cout << "Numero de Cliente Invalido" << endl
                    << "Pretende adicionar novo cliente?" << endl
                    << "1. Criar novo Cliente" << endl
                    << "2. Tentar novamente" << endl
                    << "0. Seguir sem NumeroCliente" << endl;
                cin >> escolha;

                if (escolha == 0){
                    InfoVendas[numeroVenda][0] = 999; //999 vai ser o numero definido para faturas sem numero de Cliente
                    break;
                }
                else if (escolha == 1) {
                    CriarCliente(ClienteInt, ClienteString);
                    InserirNumeroCliente(ClienteInt, ClienteString, InfoVendas, numeroVenda);
                    break;
                }
                else if (escolha == 2){
                    InserirNumeroCliente(ClienteInt, ClienteString, InfoVendas, numeroVenda);
                    break;
                }
            }
        }
    }

    else {
    InfoVendas[numeroVenda][0] = 999;
    }
}

void Checkout (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda, double total){

    if (total > 0){
        double pagamento;
        double totalpago;
        while (total >= 0){
            cout << "Falta Pagar " << ceil(total * 100.0) / 100.0  << endl;
            cout << "Insira valor: " << endl;
            cin >> pagamento;
            while (cin.fail()){
                cout << "Por favor introduza um valor valido" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> pagamento;
            }
        total = total - pagamento;
        totalpago = totalpago + pagamento;
        }
        InfoVendas[numeroVenda][2] = totalpago; //guarda o valor entregue pelo cliente
        InfoVendas[numeroVenda][3] = 0; // guarda o valor dado de troco
        cout << "Obrigado pela Compra" << endl;
        if (total < 0) {
            InfoVendas[numeroVenda][3] = ceil((total * -1)*100.0) / 100.0; // guarda o valor entregue de troco
            cout << "Troco: " << InfoVendas[numeroVenda][3] << endl;
            total = 0;
        }
    }
    printFatura(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas, numeroVenda);
}

void printFatura(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda){

       cout <<"Numero da Fatura"<< StoreVendas[numeroVenda][0] << endl
            <<"Numero do cliente"<< InfoVendas[numeroVenda][0] << endl;

            for (int i = 1; i < 51; i++){
                if (StoreVendas[numeroVenda][i] != 0){
                    cout << i  << "....... " << nomeProdutos [i-1] << "..........Quantidade: " << StoreVendas[numeroVenda][i];
                    cout << " Preco unitario: " << (produtos[i-1][2] + (produtos[i-1][2] * 0.3)) << "  Iva: " << (produtos[i-1][2] + (produtos[i-1][2] * 0.3)) * 0.23 << endl;
                }
            }
            cout << "total: " << ceil((InfoVendas[numeroVenda][1] + (InfoVendas[numeroVenda][1] * 0.3) + (InfoVendas[numeroVenda][1] * 0.23)) * 100.0) / 100.0 << endl;
            cout << "Valor pago " << InfoVendas[numeroVenda][2] << endl;
            cout << "Troco: " << InfoVendas[numeroVenda][3] << endl;
            printTime();
    system("pause");
}

//! Opcao Stock no Menu
void Stock(double **produtos, string *nomeProdutos)
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
        break;
    case 1:
        system("cls");
        CriarArtigo(produtos, nomeProdutos);
        break;
    case 2:
        system("cls");
        AdicionarStock(produtos, nomeProdutos);
        break;
    case 3:
        system("cls");
        EliminarArtigo(produtos, nomeProdutos);
        break;
    }
}

//? Criar Artigos dentro do Stock
void CriarArtigo(double **produtos, string *nomeProdutos)
{
    int resposta;

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
        CriarArtigo(produtos, nomeProdutos);
    }
    else
    {
        system("cls");
        Stock(produtos, nomeProdutos);
    }
}

//? adicionar stock ao array Produtos
void AdicionarStock(double **produtos, string *nomeProdutos)
{
    int resposta;
    cout << "A que produto pretende adicionar Stock?" << endl;
    cout << "\n\n0. Voltar ao menu anterior\n";
    resposta = Verificador(3);

    for (int i = 0; i < 50; i++)
    {
        if (produtos[i][1] == resposta)
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
                    AdicionarStock(produtos, nomeProdutos);
                }
                else if (resposta == 2)
                {
                    system ("cls");
                    Stock(produtos, nomeProdutos);
                }
            }
            else if (resposta == 2)
            {
                AdicionarStock(produtos, nomeProdutos);
            }
            else if (resposta == 0)
            {
                Stock(produtos, nomeProdutos);
            }
            else if (resposta > 2 || resposta < 0)
            {
                cout << "insira uma opcao valida \n";
                AdicionarStock(produtos, nomeProdutos);
            }
        }

    }
}

//? Eliminar produto do array Produtos
void EliminarArtigo(double **produtos, string *nomeProdutos)
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
                    EliminarArtigo(produtos, nomeProdutos);
                }
                else if (resposta == 0)
                {
                    Stock(produtos, nomeProdutos);
                }
                else if (resposta > 2 || resposta < 0)
                {
                    cout << "insira uma opcao valida \n";
                    EliminarArtigo(produtos, nomeProdutos);
                }
            }
            else
            {
                cout << "O Produto nao existe \n";
                EliminarArtigo(produtos, nomeProdutos);
            }
        }
    }
}

//! Opcao Relatorios no Menu
void Relatorios(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString)
{
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Relatorio \n";
    cout << "2.Relatorio por Produto \n";
    cout << "3.Relatorio Total \n";
    cin >> escolha;
}


//! Opcao clientes no Menu
void Clientes(int **ClienteInt, string **ClienteString)
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
        break;
    case 1:
        system("cls");
        CriarCliente(ClienteInt, ClienteString);
        Clientes(ClienteInt, ClienteString);
        break;
    case 2:
        system("cls");
        EliminarCliente(ClienteInt, ClienteString);
        Clientes(ClienteInt, ClienteString);
        break;
    case 3:
        system("cls");
        AlterarNome(ClienteInt, ClienteString);
        Clientes(ClienteInt, ClienteString);
        break;
    }
}

//? Criar Cliente
void CriarCliente(int **ClienteInt, string **ClienteString)
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
        CriarCliente(ClienteInt, ClienteString);
    }
    else
    {
        Clientes(ClienteInt, ClienteString);
    }
}

//? Eliminar Cliente 
void EliminarCliente(int **ClienteInt, string **ClienteString)
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
                    ClienteInt[i][0] = 0;
                    ClienteInt[i][1] = 0;
                    ClienteString[i][0] = "";
                    ClienteString[i][0] = "";
                }
                else if (resposta == 2)
                {
                    EliminarCliente(ClienteInt, ClienteString);
                }
                else if (resposta == 0)
                {
                    Clientes(ClienteInt, ClienteString);
                }
                else if (resposta > 2 || resposta < 0)
                {
                    cout << "insira uma opcao valida \n";
                    EliminarCliente(ClienteInt, ClienteString);
                }
            }
            else
            {
                cout << "O Cliente nao existe \n";
                EliminarCliente(ClienteInt, ClienteString);
            }
        }
    }
}

//? Alterar nome de Cliente
void AlterarNome(int **ClienteInt, string **ClienteString){

    int resposta = 0;
    string NovoNome;

    cout << "Insira o Codigo do Cliente que pretende alterar o nome" << endl;
    cout << "\n\n0. Voltar ao menu anterior\n";
    cin >> resposta;

    if (resposta == 0) {
        Clientes(ClienteInt, ClienteString);
    }
    
    for (int i = 0; i < 50; i++)
    {
        if (ClienteInt[i][0] == resposta && ClienteInt[0][i] != 0){
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
                    system("cls");
                    AlterarNome(ClienteInt, ClienteString);
                }
                else if (resposta == 2)
                {
                    Clientes(ClienteInt, ClienteString);
                }
                else if (resposta > 2 || resposta < 0)
                {
                    AlterarNome(ClienteInt, ClienteString);
                }
            }
            else if (resposta == 2)
            {
                AlterarNome(ClienteInt, ClienteString);
            }
            else if (resposta > 2 || resposta < 0)
            {
                cout << "insira uma opcao valida \n";
                AlterarNome(ClienteInt, ClienteString);
            }
        }
    }
    cout << "Cliente nao existe, pretende criar novo cliente? " << endl;
    cout << "1. Sim \n" << "2. Nao, Tentar novamente \n" << "3. Cancelar \n";
    cin >> resposta;
    switch (resposta)
    {
    case 1:
        CriarCliente(ClienteInt, ClienteString);
        break;
    
    case 2:
        AlterarNome(ClienteInt, ClienteString);
        break;
    case 3:
        Clientes(ClienteInt, ClienteString);
    }
}

//? Funcao para imprimir todo o stock no ecra, falta terminar o SETPOS
void printstocks(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int aux2)
{

    if (aux2 == 1){
    int a;
    for (int i = 0; i < 50; i++)
    {
        if (produtos[i][0] != 0)
        {
            cout << "| Nome: " << nomeProdutos[i];
            cout <<" | Codigo Produto: " << produtos[i][0];
            cout <<" | Stock: " << produtos[i][1];
            cout <<" | Preco: " << produtos[i][2];
            cout <<" | ";
            cout << endl;
        }
    }
    cin >> a;
}
 if (aux2 == 2){
    int a;
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
}

//! Verificar se as opcoes que estao ser introduzidas pelo user sao validas, se sao o datatype pedido ou se sao opcoes validas
int Verificador(int aux){
    int escolha;
    const int MAINMENU = 1;

    if (aux == MAINMENU){
        if ((!(cin >> escolha) || escolha < 1 || escolha > 4) && escolha != 99 && escolha != 98){
            do{
                if ((!cin || escolha < 1 || escolha > 4) && escolha != 99){
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << setposx (middleX-12) << setposy (23) << "insira uma opcao valida:" <<  setposx (middleX+9) << setposy (25);
                    printMainMenu();
                }
            } 
            while ((!(cin >> escolha) || escolha < 1 || escolha > 4) && escolha != 99);
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

void printTime(){
    //! imprimir o tempo atual na fatura
    time_t my_time = time(NULL);
    //! ctime converte o time_t para um string
    cout << ctime(&my_time);
}


void WelcomeMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas) {

int i = 0, user, size = 5, optionGeral;

bool repeticao = true;
    while (repeticao)
    {
        system("pause");
        system("cls");
        cout << "**************************" << endl;
        cout << "1.gerente" << endl;
        cout << "2.funcionario" << endl;
        cout << "3.sair" << endl;
        cout << "**************************" << endl;
        cout << "OPTION (munu inicial) : ";
        cin >> optionGeral;

    switch (optionGeral)
        {
        case 1:
            system("cls");
            MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
            break;
        case 2:
            system("cls");
            //criar cliente
            //ja sou cliente: fazer compra
            //showMenu pode ficar dentro da funcao cliente depois do login
            //MainMenuFuncionario(produtos, nomeProdutos, ClienteInt, ClienteString);

            break;
        case 3:
            system("cls");
            repeticao = false;
            // break;
        default:
            break;
        }
}
}

void printVendas(int **StoreVendas){
int a;
    for (int i = 0; i<100; i++){
        for (int j=0; j<51; i++){
            cout << StoreVendas[i][j] << endl;
        }
    }
cin >> a;
}



//!IMPRIMIR O MENU DE WELCOME
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

//print imagem loja mainscreen
void PrintLojinha(){

int middle = conout.getsize().X/2; //! cria o middle do ecra 

cout

<< setposx (middle-12) << setposy (2)
<< setposx (middle-12) <<"     _|=|__________" << endl
<< setposx (middle-12) <<"    /              \\" << endl
<< setposx (middle-12) <<"   /                \\" << endl
<< setposx (middle-12) <<"  /__________________\\" << endl
<< setposx (middle-12) <<"   ||  || /--\\ ||  ||" << endl
<< setposx (middle-12) <<"   ||[]|| | .| ||[]||" << endl
<< setposx (middle-12) <<" ()||__||_|__|_||__||()" << endl
<< setposx (middle-12) <<"( )|-|-|-|====|-|-|-|( ) " << endl;

}

void printMainMenu(){

        cout
         << endl
         <<setposx ((middleX-12)) << setposy (7)  //estava a 12
                                  <<".-----------------." << endl
         <<setposx ((middleX-12)) <<"|                 |" << endl
         <<setposx ((middleX-12)) <<"|                 |" << endl
         <<setposx ((middleX-12)) <<"|                 |" << endl
         <<setposx ((middleX-12)) <<"|                 |"<< endl
         <<setposx ((middleX-12)) <<"'-----------------'"<< endl;

        int escolha;
        const int VENDAS = 1, STOCK = 2, RELATORIOS = 3, CLIENTES = 4;
        cout << setposx (middleX-5) << setposy (6) << "MENU";
        cout << setposx (middleX-9) << setposy (8) << "1. Vendas";
        cout << setposx (middleX-9) << setposy (9) << "2. Stock";
        cout << setposx (middleX-9) << setposy (10) << "3. Relatorios";
        cout << setposx (middleX-9) << setposy (11) << "4. Clientes";



        cout
         << endl
         <<setposx ((middleX-14)) << setposy (24)  //estava a 12
                                  <<".--------------------------." << endl
         <<setposx ((middleX-14)) <<"|                          |" << endl
         <<setposx ((middleX-14)) <<"'--------------------------'";
        cout << setposx (middleX-9) << setposy (25) << "insira uma opcao:" << setposx (middleX+9) << setposy (25);
}

void printMenuCompras(double **produtos, string *nomeProdutos, int size[]){
    
    system ("cls");

        for (int i = 0; i < 50; i++){
            if (size[i] != 0) {
            cout << i + 1 << ". " << nomeProdutos[i] << " stock: " << produtos[i][1] << " preco " << produtos[i][2] + (produtos[i][2] * 0.30) << endl; 
            }
        }   
}