#include <iostream>
#include <string>
 
using namespace std;

void PreencherParaTeste (double **produtos, string *nomeProdutos);
void showMenu(double **produtos, string *nomeProdutos);
double Vendas(double **produtos, string *nomeProdutos, int **StoreVendas);

int main(){

    double total = 0;
    //!declarar matriz produtos
    double ** produtos = new double *[50];

    for(int i = 0; i < 50; i++)
    {
    produtos[i] = new double[4];
    }
    //!declarar vetor nomeProdutos
    string * nomeProdutos = new string[50]; 

    //!Inicilizar matriz produtos a 0
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            produtos[i][j] = 0;
        }
    }
    //!Inicializar vetor nomeProdutos em vazio
    for(int i = 0; i < 50; i++)
    {
        nomeProdutos[i] = "";
    }

    
    //!declarar matriz StoreVendas (guarda numero da venda e o codigo do produto)
    int ** StoreVendas = new int *[100];

    for(int i = 0; i < 100; i++)
    {
    StoreVendas[i] = new int[51];
    }

    //!Inicilizar matriz StoreVendas a 0 (Guarda as quantidades das StoreVendas da matriz StoreVendas)
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 51; j++)
        {
            StoreVendas[i][j] = 0;
        }
    }

    //!funcao para preencher os vetores com alguns valores default
    PreencherParaTeste(produtos, nomeProdutos);
    total = Vendas(produtos, nomeProdutos, StoreVendas);

    cout << "1. Escolher Cliente" << endl
         << "2. Checkout/ Cliente final" << endl;
         system("pause");
}

double Vendas(double **produtos, string *nomeProdutos, int **StoreVendas) {

    double subtotal = 0;
    int choice, numeroVenda, quantidade, size;

    // procurou o primeiro spot com um 0 (vazio), gravou o numero dessa posicao e atribuiu a essa posicao um numero de venda
    //! o numeroVenda vai ser o mesmo durante todo o processo desta venda    
    for (int i = 0; i<50; i++){
        if (StoreVendas[i][0] == 0){
            numeroVenda = i;
            StoreVendas[i][0] = numeroVenda + 1;
        }
        break;
    } 

    //verifica qual é a quantidade de produtos existentes no vetor produtos 
    for (int i = 0; i < 50; i++){
        if (produtos[i][0] == 0){
            size = i;
            break;
        }
    }

    while (choice != 0){
        for (int i = 0 ; i< size; i++){
            cout << i + 1 << ". " << nomeProdutos[i] << " stock: " << produtos[i][1] << " preco " << produtos[i][2] << endl; 
        } 
        cout << "0. Exit" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        while (cin.fail()){
            cout << "Selecione uma opcao valida" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

        if (choice <= size && choice > 0){
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
        cout << "Subtotal: " << subtotal << endl;
    }
    return subtotal;
}


void PreencherParaTeste (double **produtos, string *nomeProdutos) {
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
}