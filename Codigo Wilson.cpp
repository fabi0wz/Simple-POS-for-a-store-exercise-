#include <iostream>
#include<string>
using namespace std;
#pragma region funcioes
void stockGeral(int size, int* vecQtd, string* vecProdut) {
    //atribuir qrd e produto aleatorios para teste
    for (int i = 0; i < size; i++)
    {
        vecQtd[i] = 5;
    }
    vecProdut[0] = ".Mouse";
    vecProdut[1] = ".Teclado";
    vecProdut[2] = ".Monitor";
    vecProdut[3] = ".Processador";
    vecProdut[4] = ".Gabinete";
}
void showMenu(int size, int* vecQtd, string* vecProdut) {
    cout << "**********MENU**********" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << vecProdut[i] << endl;
        cout << "Qtd: " << vecQtd[i] << endl;
    }
    cout << "0.Finalizar compra" << endl;
    cout << "9.logout" << endl;
    cout << "************************" << endl;
}
void printTalao(int size, int* vecPosic, int* vecQtdTalao, string* arrayProduto) {
    cout << "**********TALAO**********" << endl;
    for (int i = 0; i < size; i++)
    {
        if (vecPosic[i] > 0) {
            cout << arrayProduto[i] << endl;
            cout << "qtd: " << vecQtdTalao[i] << endl;
        }
    }
    cout << "*************************" << endl;
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
        cout << vecProdut[option - 1] << endl;
        cout << "Qtd: ";
        cin >> retirar;
        if (retirar <= vecQtd[option - 1]) {
            (vecPosic[option - 1])++; // nova tabela para contabilizar quantidade de cada produto comprado
            if (retirar > vecQtd[option - 1])
                cout << "Qtd indisponivel" << endl;
            else {
                vecQtd[option - 1] -= retirar;
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
void menuCliente(int size, int* vecQtd, string* vecProdut, int* vecPosic, int* vecQtdTalao) {
    int option;
    cout << "1.criar cliente" << endl;
    cout << "2.ja sou cliente: fazer compra" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        cout << "criando cliente" << endl;
        break;
    case 2:
        system("cls");
        showMenu(size, vecQtd, vecProdut);
        compra(size, vecQtd, vecPosic, vecQtdTalao, vecProdut);
        break;
    default:
        break;
    }
}
#pragma endregion
int main()
{
    int i = 0, user, size = 5, optionGeral;
    string* vecProdut = new string[size];
    /*criar o bool para sutentar o  if (option == 9) {
          return;
      }  em compra  linha 86-89*/
    bool repeticao = true;
    while (repeticao)
    {
        system("pause");
        system("cls");
        // inside cada option implementar funcao voltar a pag anterior
    //BACKMAIN:
        cout << "**************************" << endl;
        cout << "1.gerente" << endl;
        cout << "2.cliente" << endl;
        cout << "3.sair" << endl;
        cout << "**************************" << endl;
        cout << "OPTION (munu inicial) : ";
        cin >> optionGeral;
        int* vecQtd = new int[size];
        int* enumerar = new int[size];
        int* vecPosic = new int[size];
        int* vecQtdTalao = new int[size];
        stockGeral(size, vecQtd, vecProdut);
        // programar x para sair do loop
        //usar switch para navegar pelos menus e escolher as opcoes
        switch (optionGeral)
        {
        case 1:
            system("cls");
            cout << "building" << endl;
            break;
        case 2:
            system("cls");
            //criar cliente
            //ja sou cliente: fazer compra
            //showMenu pode ficar dentro da funcao cliente depois do login
            menuCliente(size, vecQtd, vecProdut, vecPosic, vecQtdTalao);
            break;
        case 3:
            system("cls");
            repeticao = false;
            // break;
        default:
            break;
        }
        // cout << "administrador fase building...";
    }
    return 0;
}