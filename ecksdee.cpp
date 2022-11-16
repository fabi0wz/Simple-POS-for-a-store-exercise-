#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (){

}







/*
matrizes:

produtos -> id produto, quantidade, nome, preçocusto

clientes -> numero, nome, nif

vendas - > numerofatura, data, nif 

Talao -> numero da fatura, numero do cliente, numero da linha, nome do produto, quantidade, Valor Entregue
iva = 23%;

podia-se fazer uma matriz a parte para os produtos que vao ser comprados (porque vao ser varios) em que a primeira linha era o numero da fatura e depois
era o nome do produto quantidade preço etc, e fazia-se um while (arrayprodutos [i][0] == numerodafatura) aquilo da cout ou whatever dos produtos que foram
comprados naquela fatura

/NFatura | Codigo Produto | Nome Produto | Quantidade | Preco s/Iva | Total c/ Iva | 
/--------|----------------|--------------|------------|-------------|--------------|
/152315  |1234            | Whatever     | 3          | 56,99       |  2951        |
/152315  |1324            | Whatever2    | 1          | 15,99       | 241          |
/152315  |1621            | Gee          | 200        | 1023        | 10231413     |
/758123  |5123            | geasd        | 123        | 523         |  13123       |
/----------------------------------------------------------------------------------/

|Id Produto | Nome Produto | Quantidade | Preco Custo|
|-----------|--------------|------------|------------|
|           |              |            |            |
|-----------|--------------|------------|------------|   

nome do produto = numero da linha da coluna para depois ir buscar a um array de strings,

int[][] myArray = {  {0, 1, 2, 3},
                     {3, 2, 1, 0},
                     {3, 5, 6, 1},
                     {3, 8, 3, 4}  };

String[][] cities = new String[3][3]          


menu:

1- Venda
    -Selecionar Produtos
    Se carregar no # por exemplo --> checkout e termina de registar e avança para proxima funcao if (input==#)
    print talão
2- Stock
    -Adicionar novo Artigo
    -Adicionar Stock a Artigo
    -Eliminar Produto
3- Relatorio
    -Criar Relatório
    -Relatório por Produto
    -Relatorio total de vendas 
                [produto mais vendido
                produto menos vendido
                produto com mais lucro
                cliente que mais comprou]
4- Clientes
  -Criar Cliente
  -Eliminar Cliente
  -Alterar nome do Cliente


extras se der tempo: 

    -Adicionar superurser, na primeira vez que se inicia o programa correr uma função que verifica se já existe algum ficheiro encryptado com p+poiudsxcfgtrdesxfcrty56e4dfgtry5t4efdsxcvgtr4ewsdazxcfrte453w2qeas<ZXDFRE4532alavra passe
    guardada, se nao houver inicia a funcao First Initilization, que pergunta o nome da Loja/comercio, e pede uma palavra passe,
    Futuramente, operacoes como alterar precos de produtos, stocks, eliminar produtos, alterar clientes etc só são permitidas se o user estiver logged in

    user input/output manopulators formatar tudo que é outputted no terminal, principalmente a fatura, tentar centrar, manter nome dos produtos a direita
    e preço a esquerda etc
*/                                                           