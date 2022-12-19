"# ProjetoCpp" 

# Produtos
### Produtos (2D ARRAY)
|ID PRODUTO|STOCK|PRECO|QtdVendida|
|:-|:-|:-|:-|
|1|5|2.99|2|
|2|4|27|5|
|3|2|39.99|6|
|4|7|4.99|3|

fazer produtos[3][i] = produtos[3][i] + Quantidade Vendida

### NomeProdutos (array)
|index|1|2|3|4|
|:-|:-|:-|:-|:-|
|nome produto|Mesa|Cadeira|tartaruga|Guaxini|

# Clientes
### ClienteInt (2D ARRAY)
|ID Cliente|Contacto|
|:-|:-|
|0123|932716345|
|4284|923716274|      
|5827|918675809|
|4842|937576682|

## ClienteString (2D ARRAY)
|Nome|Morada|
|:-|:-|
|Alfredo|Rua das Laranjas|
|Carlos|Rua das Tanjerinas|
|Tatiana|Travessa das Tartarugas|
|Pedro|Rua das Tartar|

# Vendas
## StoreVendas (2D ARRAY)
|N Venda|idProduto|idProduto|idProduto|
|:-|:-|:-|:-|
|idVenda|Qtd|Qtd|Qtd|
|idVenda|Qtd|Qtd|Qtd|
|idVenda|Qtd|Qtd|Qtd|
|idVenda|Qtd|Qtd|Qtd|

## InfoVendas
|NumCliente|subtotal|TotalEntregue|Troco|
|:-|:-|:-|:-|
|NCliente|subtotal|valorentregue|troco|
|NCliente|subtotal|valorentregue|troco|
|NCliente|subtotal|valorentregue|troco|
|NCliente|subtotal|valorentregue|troco|


precos faz-se Venda [i][2,3,4,5 etc while != 0]

funcao update preco

precototal = 

inserir dados na venda

        while input != 0 (checkout)
                cout insira codigo produto
                        cin Venda
                cout insira quantidade
                        cin Qtdvenda

1. Venda
- Menu Vendas
- Realizar Vendas
- Adicionar N CLiente~
- Checkout

2. Stock
- Adicionar novo Artigo
- Adicionar Stock a Artigo
- Eliminar Produto

3. Relatorio

- Criar Relatório
- Relatório por Produto
- Relatorio total de vendas 
                [produto mais vendido
                produto menos vendido
                produto com mais lucro
                cliente que mais comprou]
4. Clientes
- Criar Cliente
- Eliminar Cliente
- Alterar nome do Cliente


void Clientes();
void CriarCliente();
void EliminarCliente();
void AlterarNome();

/*
iv. Cliente: A estrutura adotada deve incluir
 id do cliente, nome, número de telefone, morada
*/

nome variaveis:
string ClienteString;
int ClienteInt;


        if (produtos[i][0] != 0){
        if (ClienteInt[i][0] != 0){

                for (int i=0; i< 50; i++){

            cout << "Codigo Cliente: " << ClienteInt[i][0] << " | ";;
            cout << "Nome Cliente: " << ClienteString[i][0] << " | ";
            cout << "Contacto: " << ClienteInt[i][1] << " | ";
            cout << "Morada: " << ClienteString[i][1] << " | ";
            cout << endl;
        } 

/*
-----------------------------2D ARRAYS --------------------------------
        COLUMN 0    COLUMN 1    COLUMN 2
ROW 0   x[0][0]     x[0][1]     x[0][2]
ROW 1   x[1][0]     x[1][1]     x[1][2]
ROW 2   x[2][0]     x[2][1]     x[2][2]

[y][x]
*/



para passar de umas funcoes para outras, pedir o argumento check
por exemplo 
int MainMenu (bool Check)

se for 0 é a primeira vez que se esta a visitar aquela janela, entao fazer system CLS e correr o programa normalmente,

mas se o check for 1, quer dizer que o user ja esteve noutro menu antes e agora esta a voltar para o main menu

(exemplo, 
        Stock(bool Check){
        codigo;
        return 1;}
)

exemplo o programa inicia e o Check do Main Menu está a 0, da system("cls") e corre o programa
entretanto corre a funcao para verificar o input do utilizador e a funcao Verificador da return de 1 para o check, isto corre novamente o programa do mainmenu mas diz para introduzir uma opcao valida
depois de estar o problema resolvido, volta-se a colocar o check em 0.

usa-se em todas as funcoes um switch case 0 e 1 para a funcao check.



extras se der tempo: 

    -Adicionar superurser, na primeira vez que se inicia o programa correr uma função que verifica se já existe algum ficheiro encryptado com p+poiudsxcfgtrdesxfcrty56e4dfgtry5t4efdsxcvgtr4ewsdazxcfrte453w2qeas<ZXDFRE4532alavra passe
    guardada, se nao houver inicia a funcao First Initilization, que pergunta o nome da Loja/comercio, e pede uma palavra passe,
    Futuramente, operacoes como alterar precos de produtos, stocks, eliminar produtos, alterar clientes etc só são permitidas se o user estiver logged in

    user input/output manopulators formatar tudo que é outputted no terminal, principalmente a fatura, tentar centrar, manter nome dos produtos a direita
    e preço a esquerda etc

    matrizes:

produtos -> id produto, quantidade, nome, preçocusto

clientes -> numero, nome, nif

vendas - > numerofatura, data, nif 

Talao -> numero da fatura, numero do cliente, numero da linha, nome do produto, quantidade, Valor Entregue
iva = 23%;

podia-se fazer uma matriz a parte para os produtos que vao ser comprados (porque vao ser varios) em que a primeira linha era o numero da fatura e depois
era o nome do produto quantidade preço etc, e fazia-se um while (arrayprodutos [i][0] == numerodafatura) aquilo da cout ou whatever dos produtos que foram
comprados naquela fatura