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

int FaturaDaSorte = rand() % 100 +1; //ao executar um programa escolhe um numero entre 1 e 100 para ser a fatura da sorte

int middle = conout.getsize().X/2; //! cria o middle do ecra 
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



void WelcomeMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas);
void printMainMenu();
void MainMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas);

//void MainMenuFuncionario (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);
//? Zona Vendas
void MenuVendas (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas);
double Vendas(double **produtos, string *nomeProdutos, int **StoreVendas, int numeroVenda);
void printMenuCompras(double **produtos, string *nomeProdutos, int tamanho, int size[], double subtotal, int numeroVenda, int **StoreVendas);
void InserirNumeroCliente(int **ClienteInt, string **ClienteString, double **InfoVendas, int numeroVenda);
void Checkout (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda, double total);
void printFatura (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda);

//? Zona Stocks/Produtos
void Stock(double **produtos, string *nomeProdutos);
void CriarArtigo(double **produtos, string *nomeProdutos);
void printCriarArtigo(double **produtos, string *nomeProdutos);
string CompararArtigos(string *nomeProdutos, int i);
void AdicionarStock(double **produtos, string *nomeProdutos);
void printAdicionarStock(double **produtos, string *nomeProdutos, int tamanho, int size[]);
void EliminarArtigo(double **produtos, string *nomeProdutos);
void printEliminarArtigo(double **produtos, string *nomeProdutos, int tamanho, int size[]);

//? Zona Relatorios
void Relatorios(double** produtos, string* nomeProdutos, int** ClienteInt, string** ClienteString, int** StoreVendas, double **InfoVendas);
void RelatorioVendas(double** produtos, string* nomeProdutos, int** ClienteInt, string** ClienteString, int** StoreVendas);
void RelatorioVendasPCliente (double** produtos, string* nomeProdutos, int** ClienteInt, string** ClienteString, int** StoreVendas, double **InfoVendas);
void RelatorioTotalStock(double **produtos, string *nomeProdutos);
void RelatorioVendaPorProduto(double **produtos, string *nomeProdutos, int **StoreVendas);

//? Zona Clientes
void Clientes(int **ClienteInt, string **ClienteString);
void CriarCliente(int **ClienteInt, string **ClienteString);
void printCriarCliente(int **ClienteInt, string **ClienteString);
void EliminarCliente(int **ClienteInt, string **ClienteString);
void printEliminarCliente(int **ClienteInt, string **ClienteString, int tamanho, int size[]);
void AlterarNome(int **ClienteInt, string **ClienteString);
void printAlterarNome(int **ClienteInt, string **ClienteString, int tamanho, int size[]);

//!Preencher o os stocks/clientes para testes
void PreencherDados (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString);

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
    PreencherDados(produtos, nomeProdutos, ClienteInt, ClienteString);
    welcome();
    MainMenu(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);

    return 0;
}

//? Zona Menu Principal
void MainMenu(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas){
    
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
        Relatorios(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas ,InfoVendas);
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
                break;
            }
        }
    }
    
    subtotal = Vendas (produtos, nomeProdutos, StoreVendas, numeroVenda); //Entra logo na funcao de Vendas, onde escolhe os produtos para adicionar ao cart
    InfoVendas[numeroVenda][1] = subtotal; // guarda o valor do subtotal na matriz de info sobre a venda
    total = (subtotal + (subtotal * 0.3)) + (subtotal * 0.23);
    
    if (subtotal == 0) {
        StoreVendas[numeroVenda][0] = 0;
    }

    if (subtotal != 0) {

        InserirNumeroCliente(ClienteInt, ClienteString, InfoVendas, numeroVenda); //adicionar numero cliente na fatura
        
        system ("cls");
        int escolha;

        cout << setposx (middle - 9) << setposy (8) << "**Checkout**" << endl
             << setposx (middle - 9) << "1. Checkout" << endl
             << setposx (middle - 9) << "2. Cancelar Venda" << endl;
        cin >> setposx (middle - 9) >> setposy (13) >> escolha;

        switch (escolha){
        case 1:

            Checkout (produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas, numeroVenda, total);
            break;
        
        case 2:

            cout << setposx (middle - 9 ) << setposy (13) << "Venda Cancelada" << endl;
            for (int i = 0; i < 50; i++){
                produtos[i][1] = produtos[i][1] + StoreVendas[numeroVenda][i+1]; //volta a adicionar as quantidades retiradas ao stock
            }
            for (int i = 0; i < 51; i++){
                StoreVendas[numeroVenda][i] = 0; //poe a linha da coluna a 0
            }
            for (int i=0; i < 4; i++){
                InfoVendas[numeroVenda][i] = 0;
            }
            cout << setposx (middle - 16) << setposy (25);
            system("pause");
            break;
        }
    }
}

double Vendas (double **produtos, string *nomeProdutos, int **StoreVendas, int numeroVenda){

    system("cls");
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
        printMenuCompras(produtos, nomeProdutos, tamanho, size, subtotal, numeroVenda, StoreVendas);
        cin >> choice;

        while (cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            printMenuCompras(produtos, nomeProdutos, tamanho, size, subtotal, numeroVenda, StoreVendas);
            cout << setposx(1) << setposy(tamanho+10 ) << "Selecione uma opcao valida" << endl;
            cin >> choice;
            cout << setposx(0) << setposy(tamanho+11) << "            ";
        }
        if (choice == 0){
            break;
        }

        if (choice <= tamanho && choice > 0){
            system("cls");
            printMenuCompras(produtos, nomeProdutos, tamanho, size, subtotal, numeroVenda, StoreVendas);
            cout << setposx (1) << setposy (tamanho + 10) << "Introduza a Quantidade " << endl;
            cin >> quantidade;
            cout << setposx (1) << setposy (tamanho+ 10) << "                           ";
            cout << setposx (0) << setposy (tamanho+11) << "          ";
                if (quantidade > produtos[choice - 1][1]){
                    cout << setposx (1) << setposy (tamanho+10) << "Quantidade indisponivel" << endl;
                    quantidade = 0;
                }
            subtotal = subtotal + (quantidade * produtos[choice-1][2]);// calcula o valor subtotal (sem iva e sem lucro)
            StoreVendas[numeroVenda][choice] = StoreVendas[numeroVenda][choice] + quantidade; // guarda o index no index do produto a quantidade vendida
            produtos[choice-1][1] = (produtos[choice -1][1] - quantidade); //remove a quantidade escolhida do stock
            produtos[choice-1][3] = produtos[choice-1][3]+quantidade;
        }
    }
    return subtotal;
}

void InserirNumeroCliente(int **ClienteInt, string **ClienteString, double **InfoVendas, int numeroVenda){

    int escolha;

    cout << setposx (middle - 19) << setposy (15) << "Pretende Adicionar Numero de Cliente?" << endl
         << setposx (middle -19) << "1. Sim" << endl
         << setposx (middle - 19) <<"2. Nao, Prosseguir com checkout" << endl;
    cin >> escolha;

    if (escolha == 1){
        
        system("cls");
        int numCliente;
        cout << setposx (middle -12) << "Insira numero do cliente" << endl;
        cin >> setposx(middle-12) >> numCliente;

        for (int i = 0; i < 50; i++){
            if (numCliente == ClienteInt[i][0]){
                InfoVendas[numeroVenda][0] = numCliente;
            }
        }
        int escolha = 99;

        if(InfoVendas[numeroVenda][0] == 0 ){
            while(InfoVendas[numeroVenda][0] == 0 || escolha != 0){
                cout << "\n\n\nNumero de Cliente Invalido" << endl
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
                    system("cls");
                    CriarCliente(ClienteInt, ClienteString);
                    InserirNumeroCliente(ClienteInt, ClienteString, InfoVendas, numeroVenda);
                    break;
                }
                else if (escolha == 2){
                    system("cls");
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
            if (numeroVenda == FaturaDaSorte){ // se o numero da venda for o mesmo da fatura da sorte, o total fica a 0
                total = 0;
                cout << "Parabens, recebeu uma compra gratuira por ser o " << FaturaDaSorte <<" cliente :)" << endl;
            }
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
        if (total < 0) {
            InfoVendas[numeroVenda][3] = ceil((total * -1)*100.0) / 100.0; // guarda o valor entregue de troco
            cout << "Troco: " << InfoVendas[numeroVenda][3] << endl;
            total = 0;
        }
    }
    system("cls");
    printFatura(produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas, numeroVenda);
}

void printFatura(double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString, int **StoreVendas, double **InfoVendas, int numeroVenda){
    
    int numCli;
    for (int i =0; i<50; i++){
        if(ClienteInt[i][0] == InfoVendas[numeroVenda][0]){
            numCli = i;
        }
    }


       cout << "|----------------Obrigado pela Compra--------------------|" << endl
            << "|                                                        |" << endl
            << "|                                                        |" << endl
            << "| Numero da Fatura: "<< StoreVendas[numeroVenda][0] << setposx (57) << "|" << endl
            << "| Numero do cliente: "<< ClienteInt[numCli][0] << ": " << ClienteString[numCli][0] << setposx (57) <<"|" << endl
            << "|" << setposx(57) << "|" << endl
            << "| Artigos:" << setposx(57) << "|" << endl
            << "|" << setposx (57) << "|" << endl;

            for (int i = 1; i < 51; i++){
                if (StoreVendas[numeroVenda][i] != 0){
                    cout << "| " << i  << ". " << nomeProdutos [i-1] << setposx(20) << "Qtd: " << StoreVendas[numeroVenda][i] << setposx(57) << "|" << endl;
                    cout << "| Preco: " << ceil((produtos[i-1][2] + (produtos[i-1][2] * 0.3)) * 100.0)/100.0 << "  Iva: " << ceil(((produtos[i-1][2] + (produtos[i-1][2] * 0.3)) * 0.23)*100.0) /100.0 << setposx(57) << "|" << endl;
                    cout << "|" << setposx(57) << "|" << endl;
                }
            }
            cout << "|" << setposx(57) << "|" << endl
                 << "|" << setposx(57) << "|" << endl
                 << "|" << setposx(57) << "|" << endl;

            cout << "| Total: " << ceil((InfoVendas[numeroVenda][1] + (InfoVendas[numeroVenda][1] * 0.3) + (InfoVendas[numeroVenda][1] * 0.23)) * 100.0) / 100.0 << setposx(57) << "|" << endl;
            cout << "| Valor recebido: " << InfoVendas[numeroVenda][2] << setposx(57) << "|" << endl;
            cout << "| Troco: " << InfoVendas[numeroVenda][3] << setposx(57) << "|" << endl;
            cout << "|" << setposx(57) << "|" << endl
                 << "|" << setposx(57) << "|" << endl;
            cout << "| ";
            printTime();
            cout << setposx(57) << "|" << endl;
            cout << "|--------------------------------------------------------|" << endl;

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
void CriarArtigo(double **produtos, string *nomeProdutos){

    system("cls");
    string novoProd = "";
    int comparar = 0;
    int resposta;

    printCriarArtigo(produtos, nomeProdutos);
    for (int i = 0; i < 50; i++){

        if (produtos[i][0] == 0){

            if (i == 0) {
                produtos[i][0] = 1;
                cout << setposx (middle-2) << setposy (8) << produtos[i][0] << endl; // insere automaticamente o ID do artigo
            }
            else {
                produtos[i][0] = produtos[i-1][0] + 1;
                cout << setposx (middle-2) << setposy (8) << produtos[i][0] << endl; // insere automaticamente o ID do artigo
            }

        cout << setposx (middle) << setposy(9);


        nomeProdutos[i] = CompararArtigos(nomeProdutos, i); 
    
        cin >> setposx (middle - 4) >> setposy(10) >> produtos[i][1]; 
        cin >> setposx (middle -1) >> setposy (11) >> produtos[i][2];            
        break;
    }

    }
    cout << "\n\n\n\n\n" << setposx (middle-16) << "Pretende adicionar mais Produtos?" << endl;
    cout << setposx (middle-16) << "1. Sim" << endl;
    cout << setposx (middle-16) << "2. Nao\n\n";

    cout
    << endl
    <<setposx ((middle-15)) << setposy (24)  //estava a 12
                            <<".--------------------------." << endl
    <<setposx ((middle-15)) <<"|                          |" << endl
    <<setposx ((middle-15)) <<"'--------------------------'";
    cout << setposx (middle-10) << setposy (25) << "insira uma opcao:" << setposx (middle+8) << setposy (25);


    cin >> resposta;
   
    if (resposta == 1){
        CriarArtigo(produtos, nomeProdutos);
    }

    else{
        system("cls");
    }

}

//? adicionar stock ao array Produtos
void AdicionarStock(double **produtos, string *nomeProdutos){

    int tamanho = 0, resposta = 999, quantidade = 0; // determina a quantidade de produtos existente
    int size [50] = { 0 }; //determina posicao onde estao os produtos

    for (int i=0; i<50; i++){
        if (produtos[i][0] != 0){
            size[i] = 1;
            tamanho++;
        }
    }

while (resposta != 0){
        printAdicionarStock(produtos, nomeProdutos, tamanho, size);
        cin >> setposx (41) >> setposy (tamanho+4 ) >>resposta;

        while (cin.fail() || (resposta > tamanho || resposta < 0)){
            cin.clear();
            cin.ignore(256, '\n');
            printAdicionarStock(produtos, nomeProdutos, tamanho, size);
            cout << setposx(1) << setposy(tamanho + 10) << "Selecione uma opcao valida" << endl;
            cin >> resposta;
            cout << setposx(0) << setposy(tamanho + 11) << "            ";
        }
        if (resposta == 0){
            break;
        }

        if (resposta <= tamanho && resposta > 0){
            system("cls");
            printAdicionarStock(produtos, nomeProdutos, tamanho, size);
            cout << setposx (1) << setposy (tamanho + 10) << "Introduza Quanto pretende Adicionar " << endl;
            cin >> quantidade;
            cout << setposx (1) << setposy (tamanho+ 10) << "                                             "; //apaga a linha acima
            cout << setposx (0) << setposy (tamanho+11) << "           "; //apaga a linha do input
                if ((produtos[resposta-1][1] + quantidade) < 0){ //se o user introduzir um valor que deixaria o stock em negativo
                    quantidade = -(produtos[resposta-1][1]); //poe o stock a 0
                }
            produtos[resposta-1][1] = (produtos[resposta -1][1] + quantidade); //adiciona a quantidade escolhida do stock
        }
    }
}

//? Eliminar produto do array Produtos
void EliminarArtigo(double **produtos, string *nomeProdutos)
{

    int tamanho = 0, resposta = 999, choice = 0; // determina a quantidade de produtos existente
    int size [50] = { 0 }; //determina posicao onde estao os produtos

    for (int i=0; i<50; i++){
        if (produtos[i][0] != 0){
            size[i] = 1;
            tamanho++;
        }
    }

while (resposta != 0){
        printEliminarArtigo(produtos, nomeProdutos, tamanho, size);
        cin >> setposx (41) >> setposy (tamanho+4 ) >>resposta;

        while (cin.fail() || (resposta > tamanho || resposta < 0)){
            cin.clear();
            cin.ignore(256, '\n');
            printEliminarArtigo(produtos, nomeProdutos, tamanho, size);
            cout << setposx(1) << setposy(tamanho + 10) << "Selecione uma opcao valida" << endl;
            cin >> resposta;
            cout << setposx(0) << setposy(tamanho + 11) << "            ";
        }
        if (resposta == 0){
            break;
        }

        if (resposta <= tamanho && resposta > 0 && produtos[resposta-1][0] != 0){
            system("cls");
            printEliminarArtigo(produtos, nomeProdutos, tamanho, size);
            cout << setposx (0) << setposy (tamanho + 10) << "Pretende Eliminar " << nomeProdutos[resposta-1] << endl;
            cout << "1. Sim  2. Nao" << endl;
            cin >> choice;
            cout << setposx (0) << setposy (tamanho+10) << "                                                         "; //apaga a linha acima
            cout << setposx (0) << setposy (tamanho+11) << "                            ";
            cout << setposx (0) << setposy (tamanho+12) << "                            "; //apaga a linha do input
                if (choice == 1){ //se o user introduzir um valor que deixaria o stock em negativo
                    produtos[resposta-1][0] = 0;
                    produtos[resposta-1][1] = 0;
                    produtos[resposta-1][2] = 0;
                    produtos[resposta-1][3] = 0;
                    nomeProdutos[resposta-1] = "";
                }
                else {
                    
                }
        }
    }
}

//! Opcao Relatorios no Menu
void Relatorios(double** produtos, string* nomeProdutos, int** ClienteInt, string** ClienteString, int** StoreVendas, double **InfoVendas)
{
    int optionRelatorio, vectorSomaQtdProduto[51];


    cout << "********** Relatorios **********" << endl;
    cout << "1.Relatorio total de venda" << endl;
    cout << "2.Relatorio de venda por produtos" << endl;
    cout << "3.Relatorio total de stock" << endl;
    cout << "4.Relatorio de Venda por Cliente" << endl;
    cout << "********************************" << endl;
    cout << "OPCAO (relatorio) : ";
    cin >> optionRelatorio;

    switch (optionRelatorio){

    case 1:

        system("cls");
        cout << "********** Relatorio total de venda **********" << endl;

        RelatorioVendas(produtos,nomeProdutos,ClienteInt,ClienteString,StoreVendas);
        //produto mais vendido, produto menos vendido, produto com mais lucro, cliente que mais comprou
        cout << "***********************************************" << endl;
        system("pause");
        break;

    case 2:
        /*usei o vectorSomaQtdProduto[51] para somar todas as quantidades de um produto 
        em diversas vendas dentro da matriz StoreVendas*/
        system("cls");
        cout << "********** Relatorio de venda por produtos **********" << endl;
        RelatorioVendaPorProduto(produtos, nomeProdutos, StoreVendas);
        cout << "*************************************************" << endl;
        system("pause");
        break;

    case 3:
        /* usei o 4 por ser o tamanho atual da matriz produtos, no futuro pretendo usar uma variavel "size"
        para tornar dinamico o print da matriz produto*/
        cout << "3.Relatorio total de stock" << endl;
        RelatorioTotalStock(produtos, nomeProdutos);
        break;
    case 4:
        RelatorioVendasPCliente (produtos, nomeProdutos, ClienteInt, ClienteString, StoreVendas, InfoVendas);
    default:
        break;
    }
}


//! Opcao clientes no Menu
void Clientes(int **ClienteInt, string **ClienteString)
{
    int escolha;
    cout << "Que Operacao Pretende Realizar? \n";
    cout << "1.Criar Clientes \n";
    cout << "2.Eliminar Clientes \n";
    cout << "3.Alterar Nome de Cliente \n";
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

    printCriarCliente(ClienteInt,ClienteString);
    for (int i = 0; i < 50; i++)
    {
        if (ClienteInt[i][0] == 0)
        {
            if (i == 0) {
                ClienteInt[i][0] = 1;
                cout << setposx (middle-2) << setposy (8) << ClienteInt[i][0] << endl; // insere automaticamente o ID do user
            }
            else {
                ClienteInt[i][0] = ClienteInt[i-1][0] + 1;
                cout << setposx (middle-2) << setposy (8) << ClienteInt[i][0] << endl; // insere automaticamente o ID do user
            }
            cout << setposx (middle) << setposy(9);
            cin.ignore();
            getline (cin, ClienteString[i][0]); // Escreve nome do cliente a frente do texto "Nome Cliente:"
            cin >> setposx (middle - 4) >> setposy(10) >> ClienteInt[i][1]; //Insere o Contacto do utilizador a frente do texto "contacto:"
            cout << setposx (middle-6) << setposy(11);
            cin.ignore();
            getline(cin, ClienteString[i][1]);
            break;
        }
    }
    cout << "\n\n\n\n\n" << setposx (middle-16) << "Pretende adicionar mais Clientes?" << endl;
    cout << setposx (middle-16) << "1. Sim" << endl;
    cout << setposx (middle-16) << "2. Nao\n\n";

    cout
    << endl
    <<setposx ((middle-15)) << setposy (24)  //estava a 12
                            <<".--------------------------." << endl
    <<setposx ((middle-15)) <<"|                          |" << endl
    <<setposx ((middle-15)) <<"'--------------------------'";
    cout << setposx (middle-10) << setposy (25) << "insira uma opcao:" << setposx (middle+8) << setposy (25);


    cin >> resposta;
   
    if (resposta == 1)
    {
        CriarCliente(ClienteInt, ClienteString);
    }

    else{
        system("cls");
    }
}

//? Eliminar Cliente 
void EliminarCliente(int **ClienteInt, string **ClienteString)
{

    int tamanho = 0, resposta = 999, choice = 0; // determina a quantidade de Clientes existente
    int size [50] = { 0 }; //determina posicao onde estao os Clientes

    for (int i=0; i<50; i++){
        if (ClienteInt[i][0] != 0){
            size[i] = 1;
            tamanho++;
        }
    }

while (resposta != 0){
        printEliminarCliente(ClienteInt, ClienteString, tamanho, size);
        cin >> setposx (41) >> setposy (tamanho+4 ) >>resposta;

        while (cin.fail() || (resposta > tamanho || resposta < 0)){
            cin.clear();
            cin.ignore(256, '\n');
            printEliminarCliente(ClienteInt, ClienteString, tamanho, size);
            cout << setposx(1) << setposy(tamanho + 10) << "Selecione uma opcao valida" << endl;
            cin >> resposta;
            cout << setposx(0) << setposy(tamanho + 11) << "            ";
        }
        if (resposta == 0){
            system("cls");
            break;
        }

        if (resposta <= tamanho && resposta > 0 && ClienteInt[resposta-1][0] != 0){
            system("cls");
            printEliminarCliente(ClienteInt, ClienteString, tamanho, size);
            cout << setposx (0) << setposy (tamanho + 10) << "Pretende Eliminar " << ClienteString[resposta-1][0] << endl;
            cout << "1. Sim  2. Nao" << endl;
            cin >> choice;
            cout << setposx (1) << setposy (tamanho+ 10) << "                                                         "; //apaga a linha acima
            cout << setposx (0) << setposy (tamanho+11) << "                            ";
            cout << setposx (0) << setposy (tamanho+12) << "                             "; //apaga a linha do input
                if (choice == 1){ //se o user introduzir um valor que deixaria o stock em negativo
                    ClienteInt[resposta-1][0] = 0;
                    ClienteInt[resposta-1][1] = 0;
                    ClienteString[resposta-1][0] = "";
                    ClienteString[resposta-1][1] = "";
                }
                else {

                }
        }
    }
}

//? Alterar nome de Cliente
void AlterarNome(int **ClienteInt, string **ClienteString){

    int tamanho = 0, resposta = 999, choice = 0; // determina a quantidade de Clientes existente
    int size [50] = { 0 }; //determina posicao onde estao os Clientes
    string NovoNome;
    for (int i=0; i<50; i++){
        if (ClienteInt[i][0] != 0){
            size[i] = 1;
            tamanho++;
        }
    }

while (resposta != 0){
        printAlterarNome(ClienteInt, ClienteString, tamanho, size);
        cin >> setposx (41) >> setposy (tamanho+4 ) >>resposta;

        while (cin.fail() || (resposta > tamanho || resposta < 0)){
            cin.clear();
            cin.ignore(256, '\n');
            printAlterarNome(ClienteInt, ClienteString, tamanho, size);
            cout << setposx(1) << setposy(tamanho + 10) << "Selecione uma opcao valida" << endl;
            cin >> resposta;
            cout << setposx(0) << setposy(tamanho + 11) << "            ";
        }
        if (resposta == 0){
            system("cls");
            break;
        }

        if (resposta <= tamanho && resposta > 0 && ClienteInt[resposta-1][0] != 0){
            system("cls");
            printAlterarNome(ClienteInt, ClienteString, tamanho, size);
            cout << setposx (0) << setposy (tamanho + 10) << "Insira novo nome para: " << ClienteString[resposta-1][0] << endl;
            cin >> NovoNome;
            cout << setposx (1) << setposy (tamanho+ 10) << "                                                         "; //apaga a linha acima
            cout << setposx (0) << setposy (tamanho+11) << "                            ";
            cout << setposx (0) << setposy (tamanho+12) << "                             "; //apaga a linha do input
            ClienteString[resposta-1][0] = NovoNome;
        }
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
    const int MAINMENU = 1, ADICIONAR_STOCK = 3;

    if (aux == MAINMENU){
        if ((!(cin >> escolha) || escolha < 1 || escolha > 4) && escolha != 99 && escolha != 98){
            do{
                if ((!cin || escolha < 1 || escolha > 4) && escolha != 99){
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << setposx (middle-12) << setposy (23) << "insira uma opcao valida:" <<  setposx (middle+9) << setposy (25);
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
    return escolha;
}

void PreencherDados (double **produtos, string *nomeProdutos, int **ClienteInt, string **ClienteString) {
    produtos[0][0] = 001; //produto 1
    produtos[0][1] = 12; // stock
    produtos[0][2] = 19.99; // preco
    produtos[0][3] = 5;
    produtos[1][0] = 002; //produto 2
    produtos[1][1] = 16; //stock 2
    produtos[1][2] = 4.99; //preco 2
    produtos[1][3] = 2;
    produtos[2][0] = 003; // produto 3
    produtos[2][1] = 26; //stock 3
    produtos[2][2] = 12.50; // preco 3
    produtos[2][3] = 14;
    produtos[3][0] = 004; //produto 4
    produtos[3][1] = 8; //stock 4
    produtos[3][2] = 89.99; //preco 4
    produtos[4][0] = 005; //produto 5
    produtos[4][1] = 50; //stock 5
    produtos[4][2] = 3.99; //preco 5
    nomeProdutos[0] = "Monitor";
    nomeProdutos[1] = "Rato";
    nomeProdutos[2] = "Teclado";
    nomeProdutos[3] = "Cadeira";
    nomeProdutos[4] = "Tartaruga";

    ClienteInt[0][0] = 999;
    ClienteInt[0][1] = 0;
    ClienteInt[1][0] = 2;
    ClienteInt[1][1] = 978264019;
    ClienteInt[2][0] = 3;
    ClienteInt[2][1] = 915274921;
    ClienteInt[3][0] = 4;
    ClienteInt[3][1] = 927162542;

    ClienteString[0][0] = "Cliente Final";
    ClienteString[0][1] = "";
    ClienteString[1][0] = "Renato";
    ClienteString[1][1] = "Rua das Tangerinas n221";
    ClienteString[2][0] = "Filomena";
    ClienteString[2][1] = "Travessa das Travessas";
    ClienteString[3][0] = "Marca";
    ClienteString[3][1] = "Viela ao contrario";

}

void printTime(){

    string meses [12] = {"JANEIRO", "FEVEREIRO", "MARCO", "ABRIL", "MAIO", "JUNHO", "JULHO", "AGOSTO", "SETEMBRO", "OUTUBRO", "NOVEMBRO", "DEZEMBRO"};
    string mes;
    time_t tim = time(0);
    tm* gottime = gmtime(&tim);

    for (int i = 0; i<12; i++){
        if (gottime->tm_mon = i+1){
            mes = meses[i];
        }
    }

    cout << "Data: " << gottime->tm_mday << " de " << mes << " de " << gottime->tm_year+1900 << "  Hora: " << gottime->tm_hour << ":" << gottime->tm_min << ":" << gottime->tm_sec;
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
         <<setposx ((middle-12)) << setposy (7)  //estava a 12
                                  <<".-----------------." << endl
         <<setposx ((middle-12)) <<"|                 |" << endl
         <<setposx ((middle-12)) <<"|                 |" << endl
         <<setposx ((middle-12)) <<"|                 |" << endl
         <<setposx ((middle-12)) <<"|                 |"<< endl
         <<setposx ((middle-12)) <<"'-----------------'"<< endl;

        int escolha;
        const int VENDAS = 1, STOCK = 2, RELATORIOS = 3, CLIENTES = 4;
        cout << setposx (middle-5) << setposy (6) << "MENU";
        cout << setposx (middle-9) << setposy (8) << "1. Vendas";
        cout << setposx (middle-9) << setposy (9) << "2. Stock";
        cout << setposx (middle-9) << setposy (10) << "3. Relatorios";
        cout << setposx (middle-9) << setposy (11) << "4. Clientes";



        cout
         << endl
         <<setposx ((middle-15)) << setposy (24)  //estava a 12
                                  <<".--------------------------." << endl
         <<setposx ((middle-15)) <<"|                          |" << endl
         <<setposx ((middle-15)) <<"'--------------------------'";
        cout << setposx (middle-10) << setposy (25) << "insira uma opcao:" << setposx (middle+8) << setposy (25);
}

void printMenuCompras(double **produtos, string *nomeProdutos, int tamanho, int size[], double subtotal, int numeroVenda, int **StoreVendas){
    cout 
        << setposx (3) << setposy(1) << "Produtos: "
        << setposx (0) << setposy (2)  //estava a 12
        <<".------------------------------------------------------------." << endl;
    for (int i = 0; i <= tamanho + 1; i++){
        cout <<"|                                                            |" << endl;
    }
        cout <<"'------------------------------------------------------------'" << endl;

    for (int i = 0; i < 50; i++){
        if (size[i] != 0) {
        cout << setposx (1) << setposy (i+3) << i + 1 << ". " << setposx (4) << nomeProdutos[i] << setposx (18) <<"| stock: " << produtos[i][1] << setposx (36) <<"| preco " << setposx (46) << ceil((produtos[i][2] + (produtos[i][2] * 0.30))*100.0) / 100.0 << endl; 
        }
        cout << setposx (1) << setposy (tamanho + 4) << "0. Checkout" << endl;
        cout << setposx (1) << setposy (tamanho + 3) << "------------------------------------------------------------" << endl;
        cout << setposx (1) << setposy (tamanho + 6) << "Escolha uma opcao: ";
    }   

        cout
         <<setposx (73) << setposy (1) << "Carrinho: ";

        cout
        <<setposx (70) << setposy (2)  //estava a 12
                                                         <<".------------------------------------------------." << endl;
        for (int i = 0; i <= tamanho + 2; i++){
            cout << setposx (70) << setposy (i+3)       << "|                                                |" << endl;
        }
            cout << setposx (70) << setposy (tamanho+6) << "'------------------------------------------------'" << endl;
            
        for (int i = 1; i<= tamanho; i++){
            if (StoreVendas[numeroVenda][i] != 0){
                cout << setposx (71) << setposy (i+3) << nomeProdutos [i-1] << "..........Quantidade: " << StoreVendas[numeroVenda][i];
            }
        }
        cout << setposx (71) << setposy (tamanho +5) << "total c/Iva: " << ceil(((subtotal + (subtotal * 0.3)) + (subtotal * 0.23))*100.0) / 100.0 << endl; //arrendondar a 2 decimais ceil(valor * 100.0) / 100.0
        cout << setposx (20) << setposy (tamanho +4); 

    }


void printCriarCliente(int **ClienteInt, string **ClienteString){

    cout
    << endl
    <<setposx ((middle-16)) << setposy (7)  //estava a 12
                            <<".--------------------------------." << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"'--------------------------------'" << endl;

    int escolha;
    const int VENDAS = 1, STOCK = 2, RELATORIOS = 3, CLIENTES = 4;
    cout << setposx (middle-14) << setposy (6) << "Novo Cliente";
    cout << setposx (middle-14) << setposy (8) << "ID Cliente:";
    cout << setposx (middle-14) << setposy (9) << "Nome Cliente:";
    cout << setposx (middle-14) << setposy (10) << "Contacto:";
    cout << setposx (middle-14) << setposy (11) << "Morada:";

}

void printEliminarCliente(int **ClienteInt, string **ClienteString, int tamanho, int size[]){

    cout 
        << setposx (3) << setposy(1) << "Clientes: "
        << setposx (0) << setposy (2)  //estava a 12
        <<".-----------------------------------------------------." << endl;
    for (int i = 0; i <= tamanho + 1; i++){
        cout <<"|                                                     |" << endl;
    }
        cout <<"'-----------------------------------------------------'" << endl;

    for (int i = 0; i < 50; i++){
        if (size[i] != 0) {
        cout << setposx (1) << setposy (i+3) << "ID " << i + 1 << " | " << setposx (8) <<"Nome: " << ClienteString[i][0] << endl; 
        }
        cout << setposx (1) << setposy (tamanho + 4) << "Que Cliente pretende Eliminar?" << endl;
        cout << setposx (1) << setposy (tamanho + 3) << "-----------------------------------------------------" << endl;
        cout << setposx (1) << setposy (tamanho + 6) << "0. Voltar ao menu Inicial";
    }   

}

void printAlterarNome(int **ClienteInt, string **ClienteString, int tamanho, int size[]){

    cout 
        << setposx (3) << setposy(1) << "Clientes: "
        << setposx (0) << setposy (2)  //estava a 12
        <<".-----------------------------------------------------." << endl;
    for (int i = 0; i <= tamanho + 1; i++){
        cout <<"|                                                     |" << endl;
    }
        cout <<"'-----------------------------------------------------'" << endl;

    for (int i = 0; i < 50; i++){
        if (size[i] != 0) {
        cout << setposx (1) << setposy (i+3) << "ID " << i + 1 << " | " << setposx (8) <<"Nome: " << ClienteString[i][0] << endl; 
        }
        cout << setposx (1) << setposy (tamanho + 4) << "Que Cliente pretende Alterar o Nome?" << endl;
        cout << setposx (1) << setposy (tamanho + 3) << "-----------------------------------------------------" << endl;
        cout << setposx (1) << setposy (tamanho + 6) << "0. Voltar ao menu Inicial";
    }   
}



void printCriarArtigo(double **produtos, string *NomeProdutos){

    cout
    << endl
    <<setposx ((middle-16)) << setposy (7)  //estava a 12
                            <<".--------------------------------." << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"|                                |" << endl
    <<setposx ((middle-16)) <<"'--------------------------------'" << endl;

    int escolha;
    const int VENDAS = 1, STOCK = 2, RELATORIOS = 3, CLIENTES = 4;
    cout << setposx (middle-14) << setposy (6) << "Novo Produto";
    cout << setposx (middle-14) << setposy (8) << "ID Produto:";
    cout << setposx (middle-14) << setposy (9) << "Nome Produto:";
    cout << setposx (middle-14) << setposy (10) << "Stock:";
    cout << setposx (middle-14) << setposy (11) << "Preco Custo:";

}


void printAdicionarStock(double **produtos, string *nomeProdutos, int tamanho, int size[]){
    cout 
        << setposx (3) << setposy(1) << "Produtos: "
        << setposx (0) << setposy (2)  //estava a 12
        <<".------------------------------------------------------------." << endl;
    for (int i = 0; i <= tamanho + 1; i++){
        cout <<"|                                                            |" << endl;
    }
        cout <<"'------------------------------------------------------------'" << endl;

    for (int i = 0; i < 50; i++){
        if (size[i] != 0) {
        cout << setposx (1) << setposy (i+3) << i + 1 << ". " << setposx (4) << nomeProdutos[i] << setposx (18) <<"| stock: " << produtos[i][1] << setposx (36) <<"| preco " << setposx (46) << ceil((produtos[i][2] + (produtos[i][2] * 0.30))*100.0) / 100.0 << endl; 
        }
        cout << setposx (1) << setposy (tamanho + 4) << "A que produto pretende adicionar stock?" << endl;
        cout << setposx (1) << setposy (tamanho + 3) << "------------------------------------------------------------" << endl;
        cout << setposx (1) << setposy (tamanho + 6) << "0. Voltar ao menu Inicial";
    }   
}

void printEliminarArtigo(double **produtos, string *nomeProdutos, int tamanho, int size[]){
    cout 
        << setposx (3) << setposy(1) << "Produtos: "
        << setposx (0) << setposy (2)  //estava a 12
        <<".------------------------------------------------------------." << endl;
    for (int i = 0; i <= tamanho + 1; i++){
        cout <<"|                                                            |" << endl;
    }
        cout <<"'------------------------------------------------------------'" << endl;

    for (int i = 0; i < 50; i++){
        if (size[i] != 0) {
        cout << setposx (1) << setposy (i+3) << i + 1 << ". " << setposx (4) << nomeProdutos[i] << setposx (18) <<"| stock: " << produtos[i][1] << setposx (36) <<"| preco " << setposx (46) << ceil((produtos[i][2] + (produtos[i][2] * 0.30))*100.0) / 100.0 << endl; 
        }
        cout << setposx (1) << setposy (tamanho + 4) << "Que produto pretende Eliminar?" << endl;
        cout << setposx (1) << setposy (tamanho + 3) << "------------------------------------------------------------" << endl;
        cout << setposx (1) << setposy (tamanho + 6) << "0. Voltar ao menu Inicial";
    }   

}


string CompararArtigos(string *nomeProdutos, int i){
    
    string novoProd;

    bool flag = true;

        do{

            cin.ignore(256, '\n');
            cin >> novoProd;
            for (int j = 0; j<50; j++){
                if (novoProd == nomeProdutos[j]){
                    cout << "Produto " << novoProd << " ja Existe" << endl;
                    cout << setposx(middle) << setposy(9) << "            ";
                    cout << setposx(middle) << setposy(9);
                    flag = true;
                    break;
                }
                flag = false;
            }

            
        } 
        while (flag == true);

    return novoProd;
}


void RelatorioVendas(double** produtos, string* nomeProdutos, int** ClienteInt, string** ClienteString, int** StoreVendas){
        int numeroVendasmaior = -1, maisVendido, numeroVendasmenor = 999, menosVendido, maisLucro = 0;
    double lucro = 0;

    for (int i = 0; i < 50; i++){
        if (produtos[i][3] > numeroVendasmaior){ //se a quantidade de vendas no vetor for maior que a quantidade de vendas guardada na variavel
            numeroVendasmaior = produtos[i][3]; //a quantidade de vendas passar a ser essa a maior
            maisVendido = i; //e guarda a index desse produto
        }
        if (produtos[i][3] < numeroVendasmenor){
            numeroVendasmenor = produtos[i][3];
            menosVendido = i;
        }
    }

            cout << "O mais vendido e " << nomeProdutos[maisVendido] << " com " << produtos[maisVendido][3] << " unidades vendidos" << "\nO Menos vendido e " << nomeProdutos[menosVendido] << " com " << produtos[menosVendido][3] << " unidades vendidas" << endl;
    
    for (int i = 0; i< 50; i++){
        if (((produtos[i][2] * produtos[i][3]) * 0,3) > lucro){
            lucro = ((produtos[i][2] * produtos[i][3]) * 0,3);
            maisLucro = produtos[i][0];
        }
    }
        cout << "O produto com mais lucro e " << nomeProdutos[maisLucro] << endl;
}

void RelatorioVendasPCliente (double** produtos, string* nomeProdutos, int** ClienteInt, string** ClienteString, int** StoreVendas, double **InfoVendas){

    cout << "Insira o nome do Cliente" << endl;

    string nomeCliente;
    cin.ignore(256, '\n');
    cin >> nomeCliente;
    int numvendas = 0;
    int numCliente = 0;


    for (int i = 0; i<50; i++){
        if (nomeCliente.compare(ClienteString[i][0])){
            numCliente = i+2;
            break;
        }
        else {
            cout << " O cliente nao existe" << endl;
            system("pause");
        }
    }

    for (int i = 0; i<100; i++){
        if (InfoVendas[i][0] == numCliente){
            cout << "testsste";
            numvendas++;
        }
    }
    cout << "\n\nO cliente tem um total de " << numvendas << " compras efetuadas" << endl;
    system("pause");
}

void RelatorioTotalStock(double **produtos, string *nomeProdutos){
    int tamanho = 0;
    int size[50] = { 0 };

            for (int i=0; i<50; i++){
        if (produtos[i][0] != 0){
            size[i] = 1;
            tamanho++;
        }
    }
        system("cls");
        
    cout 
        << setposx (3) << setposy(1) << "Produtos: "
        << setposx (0) << setposy (2)  //estava a 12
        <<".------------------------------------------------------------." << endl;
    for (int i = 0; i <= tamanho + 1; i++){
        cout <<"|                                                            |" << endl;
    }
        cout <<"'------------------------------------------------------------'" << endl;

    for (int i = 0; i < 50; i++){
        if (size[i] != 0) {
        cout << setposx (1) << setposy (i+3) << i + 1 << ". " << setposx (4) << nomeProdutos[i] << setposx (18) <<"| stock: " << produtos[i][1] << setposx (36) <<"| preco " << setposx (46) << ceil((produtos[i][2] + (produtos[i][2] * 0.30))*100.0) / 100.0 << endl; 
        }
        cout << setposx (1) << setposy (tamanho + 3) << "------------------------------------------------------------" << endl;
            }
            cout << setposx (2);
            system("pause");
}

void RelatorioVendaPorProduto(double **produtos, string *nomeProdutos, int **StoreVendas){

int CodigoInserido, indexProduto, QtdVendas;
cout << "insira o codigo do produto" << endl;
cin >> CodigoInserido;
int totalVendas = 0;

for (int i = 0; i<50; i++){
    if (produtos[i][0] == CodigoInserido){
        indexProduto = i;
    }
}

for (int i = 0; i<100; i++){
    totalVendas = totalVendas + StoreVendas[i][indexProduto+1];
}

cout << "O " << nomeProdutos[indexProduto] << " tem " << totalVendas << " unidades Vendidas.";

}