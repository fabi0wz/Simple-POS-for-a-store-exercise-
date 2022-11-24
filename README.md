"# ProjetoCpp" 

# Produtos
### Produtos (2D ARRAY)
|index|ID PRODUTO|STOCK|PRECO|
|:-|:-|:-|:-|
|0|125|5|2.99|
|1|126|4|27|
|2|127|2|39.99|
|3|128|7|4.99|

### NomeProdutos (array)
|index|0|1|2|3|
|:-|:-|:-|:-|:-|
||Mesa|Cadeira|tartaruga|Guaxini|

# Clientes
### ClienteInt (2D ARRAY)
|index|ID Cliente|Contacto|
|:-|:-|:-|
|0|0123|932716345|
|1|4284|923716274|      
|2|5827|918675809|
|3|4842|937576682|

## ClienteString (2D ARRAY)
|index|Nome|Morada|
|:-|:-|:-|
|0|Alfredo|Rua das Laranjas|
|1|Carlos|Rua das Tanjerinas|
|2|Tatiana|Travessa das Tartarugas|
|3|Pedro|Rua das Tartar|

# Vendas
## Venda (2D ARRAY)
|index|N Venda|Cliente|
|:-|:-|:-|
|0|1235|id cliente|
|1|5134|id cliente|
|2|551234|id cliente|
|3|1345|id cliente|

## Venda Produtos (Array)
|index|0|1|2|3|4|
|:-|:-|:-|:-|:-|:-|
|Codigo Produto|1235|1324|12345|412|1356|12345|

## Venda Produtos Quantidade (Array)

|index|0|1|2|3|4|
|:-|:-|:-|:-|:-|:-|
|Quantidade|4|5|12|2|1|25|


1. Venda
- Selecionar Produtos
    Se carregar no # por exemplo --> checkout e termina de registar e avança para proxima funcao if (input==#)
    print talão

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