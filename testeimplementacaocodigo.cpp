#include <iostream>
#include <string>
 
using namespace std;

void PreencherParaTeste (double **produtos, string *nomeProdutos);
void showMenu(double **produtos, string *nomeProdutos);
void compra(double **produtos, string *nomeProdutos)

int main(){

    double ** produtos = new double *[50];
    string * nomeProdutos = new string[50]; 

    for(int i = 0; i < 50; i++)
    {
    produtos[i] = new double[3];
    }

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            produtos[i][j] = 0;
        }
    }
    for(int i = 0; i < 50; i++)
    {
        nomeProdutos[i] = "";
    }

    PreencherParaTeste(produtos, nomeProdutos);
}

void compra(int size, int* vecQtd, int* vecPosic, int* vecQtdTalao, string* vecProdut) {
    int option, retirar;
    for (int i = 0; i < size; i++)
    {
        vecPosic[i] = 0;
        vecQtdTalao[i] = 0;
    }
    cout << "OPTION(compra) : ";
    cin >> option;
    /*      bool repeticao = true;
    while (repeticao) em main()   */
    if (option == 9) {
        return;
    }
    while (option != 0) {
        system("cls");
        if (option == 9) {
            return;
        }
        cout << nomeProdutos[option - 1] << endl;
        cout << "Qtd: ";
        cin >> retirar;
        if (retirar <= produtos[option - 1][1]) {
            (vecPosic[option - 1])++;
            if (retirar > produtos[option - 1][1])
                cout << "Qtd indisponivel" << endl;
            else {
                produtos[option - 1][1] -= retirar;
            }
            vecQtdTalao[option - 1] += retirar;
        }
        showMenu(size, vecQtd, vecProdut);
        cout << "option (compra/showmenu): ";
        cin >> option;
    }
    //when finish while loop call function printTalao
    printTalao(size, vecQtdTalao, vecPosic, vecProdut);
}


void showMenu(double **produtos, string* nomeProdutos) {
    cout << "**********MENU**********" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << i + 1 << nomeProdutos[i] << endl;
        cout << "Qtd: " << produtos[i][1] << endl;
    }
    cout << "0.Finalizar compra" << endl;
    cout << "9.logout" << endl;
    cout << "************************" << endl;
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