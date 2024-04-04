<font size=5>
Tudo começa na função principal (main).

No começo há a declaração de algumas variáveis simples, de forma que mais pra frente será explicado como elas se aplicam para formar o código como um todo.

```c
int escolha; int numero;
int pnumero;
float psaldo;
float plimite;
plista = NULL;
```

Depois, temos a chamada de um procedimento (função sem retorno), que executará algumas linhas de código predefinidas pelo programador. O procedimento “menu”, fará alguns <font color="skyblue">printf</font>, descrevendo as opções de um menu interativo. Veja:

```c
void menu()
{
     int teste;
     
    printf("\n\t\t\t\tListas encadeadas\n\n");
	printf("1. Inserir no Inicio\n");
	printf("2. Inserir no Final\n");
	printf("3. Inserir Ordenado\n");
	printf("4. Mostrar a Lista\n");
	printf("5. Remover do Inicio\n");
    printf("6. Remover do Final\n");
  	printf("7. Remover Elemento Especifico\n");
	printf("8. Buscar Elemento \n");
	printf("9. Sair\n");    
}
```

A partir daí temos um <font color="skyblue">switch</font> statement que será responsável por gerenciar e tornar funcional o menu de opções virtualizado para o usuário, dentro de um loop é claro, para que as seleções feitas pelo usuário sejam contínuas e infinitas.

```c
do {
	    printf("\nInsira a escolha: ");
		scanf("%i",&escolha);
		
	   switch (escolha) {
                  case 1:
                       // Faz algo
                       break;
                  case 2:
                       // Faz algo
                       break;
                  case 3:
                       // Faz algo
                       break;
                  case 4:
                       // Faz algo
                       break;
                  case 5:
                       // Faz algo
                       break;
                  case 6:
                       // Faz algo
                       break;
                  case 7:
                       // Faz algo
                        break;
                  case 8:
                       // Faz algo   
                       break;
                  case 9:
                       break;                         
                  default:
                          puts("Opcao invalida.");
                          break;
           }
           menu();
		
    } while (escolha != 9); 
```

Vamos analisar opção por opção para entender o que cada uma faz, quando o usuário a escolhe.

## Opção 1: Inserir no início.

O objetivo disso, é inserir um elemento no início de uma lista encadeada. Vamos analisar como funciona:

```c
case 1:
	printf("\n Digite o numero da conta :");
	scanf("%i",&pnumero);
	printf("\n Digite o saldo :");
	scanf("%f",&psaldo);
	printf("\n Digite o limite :");
	scanf("%f",&plimite);                       
	inseririnicio(pnumero,psaldo,plimite);
	break;
```

Ao escolher essa opção, o código solicita um numero, (inteiro qualquer), e joga esse número na variável “<font color="red">pnumero</font>”, declarada no início da função main. Faz a mesma coisa para as variáveis “<font color="red">psaldo</font>” e “<font color="red">plimite</font>”, dessa vez solicitando variáveis do tipo float.

Depois disso ele chama a função/procedimento, <font color="lime">inseririnicio</font>, e joga as variáveis <font color="red">pnumero</font>, <font color="red">psaldo</font> e <font color="red">plimite</font> como argumentos dessa função. Essa é a função em questão:

```c
void inseririnicio(int pnumero, float psaldo, float plimite)
{
     
	conta *aux;
	aux = (conta*) malloc(sizeof(conta));
	aux->codigo= pnumero;
	aux->saldo=psaldo;
	aux->limite=plimite;
	aux->prox = plista;
	plista = aux;
	aux = NULL;
}
```

Como pode ver, logo no começo há uma classe chamada "<font color="violet">conta</font>". Vejamos onde ela está declarada:

```c
class conta
{
	public :
		
	int codigo;
    conta *prox;
	float saldo;
	float limite;
};


conta *plista;
int posicao;
```

Uma keyword class inicia a declaração de uma classe chamada "<font color="violet">conta</font>". Essa classe possui <font color="palevioletred">codigo</font>, <font color="palevioletred">saldo</font> e <font color="palevioletred">limite</font> como atributos, similar às variáveis <font color="red">pnumero</font>, <font color="red">psaldo</font> e <font color="red">plimite</font> apresentadas anteriormente no case 1 do switch.

O interessante mesmo é que tem uma referência à ela mesma em seu segundo atributo, "<font color="palevioletred">*prox</font>". Basicamente aqui, o atributo de classe é um ponteiro que aponta para uma instância da classe conta (ela mesma). Isso é o fator chave que permite encadear a nossa lista.

Mas qual o primeiro elemento encadeado ? O ponteiro <font color="palevioletred">*plista</font>, declarado logo depois da classe, que aponta para uma instância de conta ! No entanto ele está apenas declarado e nada lhe foi atribuído, resultando em um ponteiro que aponta para <font color="cyan">null</font> por enquanto (ou pelo menos para um valor indefinido e aleatório na memória), pois não há nenhum objeto do tipo <font color="violet">conta</font> associado a esse ponteiro atualmente.

Voltemos à nossa função <font color="lime">inseririnicio</font>:

```c
void inseririnicio(int pnumero, float psaldo, float plimite)
{
     
	conta *aux;
	aux = (conta*) malloc(sizeof(conta));
	aux->codigo= pnumero;
	aux->saldo=psaldo;
	aux->limite=plimite;
	aux->prox = plista;
	plista = aux;
	aux = NULL;
}
```
Na primeira instrução do procedimento, declara-se um ponteiro <font color="red">*aux</font> que aponta para uma instância de <font color="violet">conta</font>. Depois atribui-se à esse ponteiro uma <font color="skyblue">memory allocation (malloc)</font> e converte o seu tipo (<font color="skyblue">casting</font>) de <font color="violet">void</font> para <font color="violet">conta</font>. Dessa maneira, a <font color="skyblue">memory allocation</font> está ligada à uma conta, e o ponteiro <font color="red">*aux</font> aponta, não para <font color="cyan">null</font>, mas para uma instância de <font color="violet">conta</font> !

Agora só precisamos definir qual o código, saldo e limite da conta, passados como argumentos do procedimento <font color="lime">inseririnicio</font> lá no case 1 do switch.

```c
inseririnicio(pnumero,psaldo,plimite);
```

Mas a pergunta que fica é: e o atributo de classe <font color="palevioletred">*prox</font>, o que será atribuído à ele ?

Bom, se queremos inserir um novo nó (uma conta) encadeado no começo da lista, basta dizer que o <font color="palevioletred">*prox</font> (próximo nó) desse nó é toda a lista já encadeada.

```c
aux->prox = plista;
```

E depois basta dizer que esse nó é o novo início de lista, ou seja, o novo <font color="palevioletred">plista</font>.

```c
plista = aux;
```

## Opção 2: Inserir no final.

```c
void inserirfinal(int pnumero, float psaldo, float plimite)
{
     
	conta *aux, *aux2;
	aux = (conta*) malloc(sizeof(conta));
	aux->codigo= pnumero;
	aux->saldo=psaldo;
	aux->limite=plimite;
	aux->prox = NULL;
	if (plista==NULL)
	{
        plista=aux;
        aux=NULL;
    }
    else
    {
        aux2=plista;
        while (aux2->prox != NULL)
        {
             aux2=aux2->prox;
        } 
        aux2->prox = aux;
        aux = NULL;
        aux2 = NULL;
    }     
}
```

Aqui o código começa fazendo as mesmas coisas do case anterior, só que ele faz uma checagem para ver se a lista está vazia. Se estiver ele apenas adiciona o <font color="red">aux</font> (novo nó) ao início da lista.

Só que quando a lista já existe, é necessário realizar outro procedimento, que explicarei a seguir.

Existe um loop while aqui, que se repetirá enquanto o <font color="palevioletred">*prox</font> do <font color="red">aux2</font> for diferente de <font color="cyan">null</font>, ou seja, enquanto ainda houver próximos elementos, que significa enquanto <font color="red">aux2</font> não estiver apontando para o último elemento da lista encadeada.

O código que é executado repetidamente sob efeito dessa condição é simplesmente o de "avançar" um nó.

```c
aux2=aux2->prox;
```

Em outras palavras, ele vai avançando, desde o começo da lista, até <font color="red">aux2</font> apontar para o último nó da lista encadeada.

Agora fica fácil de saber como encadear o novo nó ao final da lista, não é mesmo ? Basta indicar que o <font color="palevioletred">*prox</font> de <font color="red">aux2</font> (que atualmente aponta para <font color="cyan">null</font>) é igual ao novo elemento alocado na memória (<font color="red">aux</font>).

```c
aux2->prox = aux;
```

## Opção 3: Inserir ordenado.

```c
void inserirmeio(int pnumero, float psaldo, float plimite)
{
   conta *aux1 , *aux2;
   conta *aux;
   aux = (conta*) malloc(sizeof(conta));
   aux->codigo= pnumero;
   aux->saldo=psaldo;
   aux->limite=plimite;
 
   
   if (plista!=NULL)
   {
         
        aux1=plista;         
        aux2=plista;  
        while (aux1 != NULL && pnumero > aux1->codigo)
        {
             aux2=aux1;
             aux1=aux1->prox;
          
        }
       
      
       if (aux1==plista)
        {
        
            aux->prox = plista;
            plista = aux;
            aux = NULL;
        }
        else
        {
            if (aux1 == NULL)
            {
       
                    aux2->prox=aux;
                    aux->prox=NULL;       
            }
            else
            {
       
                    aux2->prox=aux;
                    aux->prox=aux1;
                    aux=NULL;
                    aux1=NULL;
                    aux2=NULL;
            }        
        }     
   }     
   else
   {
       aux->prox=NULL;
       plista=aux;
   }
}  
```

Aqui o código começa alocando na memória uma instância de <font color="violet">conta</font>, (através do ponteiro <font color="red">aux</font>), define os atributos de classe dessa instância, passados por argumentos do procedimento <font color="lime">inserirmeio</font> que foi chamado no case 3 do switch.

Depois ele checa para ver se a lista está vazia, (se plista é <font color="cyan">null</font>). Se estiver ele simplesmente insere o novo nó (<font color="red">aux</font>) no início da lista.

Caso a lista contenha itens, ele fará o seguinte:

Avançará item por item, jogando cada item percorrido no ponteiro <font color="red">aux1</font> e o seu anterior no ponteiro <font color="red">aux2</font>, até chegar em um item em que tenha seu <font color="palevioletred">codigo</font> maior ou igual que o código fornecido no argumento <font color="red">pnumero</font> do procedimento <font color="lime">inserirmeio</font> em questão. Isso significa que, quando o <font color="palevioletred">codigo</font> (atributo de classe) do <font color="red">aux1</font> for igual ou maior do que o <font color="red">pnumero</font> ele parará de percorrer a lista e deixará que os ponteiros <font color="red">aux1</font> e <font color="red">aux2</font> fiquem respectivamente no elemento que tem <font color="palevioletred">codigo</font> igual ao código fornecido em <font color="red">pnumero</font>, e no seu anterior.

Depois o procedimento checa se <font color="red">aux1</font> é igual ao primeiro elemento da lista encadeada, e, se for, ele insere o novo nó no começo da lista encadeada, antes da atual plista, encadeando assim o novo nó antes de todos os outros, mesmo procedimento do case 1 do switch.

```c
aux->prox = plista;
```

Depois diz que o novo plista (começo da lista) é o novo nó inserido.

```c
plista = aux;
aux = NULL;
```

Só que, e caso <font color="red">aux1</font> for diferente do primeiro elemento da lista encadeada ? Aí nesse caso ele checa se o elemento é o <font color="palevioletred">*prox</font> do último elemento (ou seja, se ele é igual a <font color="cyan">null</font>):

```c
if (aux1 == NULL)
{

     aux2->prox=aux;
     aux->prox=NULL;       
}
else
{

     aux2->prox=aux;
     aux->prox=aux1;
     aux=NULL;
     aux1=NULL;
     aux2=NULL;
} 
```

Se o <font color="red">aux1</font> for igual a <font color="cyan">null</font>, ele pega o penultimo elemento (<font color="red">aux2</font>), e fala que o seu <font color="palevioletred">*prox</font> é o novo nó a ser adicionado. Em outras palavras ele adiciona o nó ao final de toda a lista, atribuindo <font color="cyan">null</font> ao <font color="palevioletred">*prox</font> do novo nó, é claro, já que este será o novo último elemento, e o último elemento sempre terá <font color="cyan">null</font> como <font color="palevioletred">*prox</font>.

Mas caso o <font color="red">aux1</font> não seja igual a <font color="cyan">null</font>, ou seja, se o <font color="red">aux1 e aux2</font> estiverem apontando para um elemento no meio da lista encadeada, o procedimento adiciona o novo nó em questão antes do nó que contém o <font color="palevioletred">codigo</font> igual ao <font color="red">pnumero</font> (<font color="palevioletred">*prox</font> de <font color="red">aux2</font>).

```c
aux2->prox=aux;
```

Depois, perceba que o agora os nós presentes em <font color="red">aux1</font> em diante estão fora da lista encadeada, devido a inserção do novo nó no meio da lista que aponta para <font color="cyan">null</font>. Se nada for feito eles serão perdidos ! Então precisamos reencadeá-los, dizendo que o <font color="palevioletred">*prox</font> desse novo nó (<font color="red">aux</font>) é igual ao <font color="red">aux1</font>. 

```c
aux->prox=aux1;
```

Consequentemente, reencadeamos esses elementos na lista, e o novo nó foi inserido com êxito ordenadamente.

## Opção 4: Mostrar lista.

```c
void mostrarlista()
{
conta *aux;
if(plista != NULL)
{
	aux = plista;
	do{
		printf("\n Conta : %i  - Saldo : %f - Limite : %f \n",aux->codigo,aux->saldo, aux->limite);
		aux = aux->prox;

    }
    while (aux != NULL);
} 
else 
     printf("\n \n ************** Lista Vazia ***************** ");
    
}
```

Primeiro o procedimento declara um ponteiro para uma instância de <font color="violet">conta</font> e checa pra ver se a lista está vazia ou não. Se estiver imprime "************** Lista Vazia *****************".

Se não estiver vazia, o procedimento aponta o ponteiro <font color="red">aux</font> para o início da lista encadeada, e, percorre a lista inteira dando <font color="skyblue">printf</font> em cada nó da lista, bem como em quase todos os seus atributos de classe.

```c
printf("\n Conta : %i  - Saldo : %f - Limite : %f \n",aux->codigo,aux->saldo, aux->limite);
aux = aux->prox;
```

## Opção 5: Remover início.

```c
void removerinicio()
{
     if (plista==NULL)
        printf("Lista Vazia");
     else
     {
         plista=plista->prox;
     }      
}    
```

Primeiro ele checa pra ver se a lista está vazia, e, se não estiver ele simplesmente diz que o nó do começo da lista (primeiro nó [<font color="palevioletred">plista</font>]) é igual ao próximo, anulando desencadeando o primeiro nó da lista.

## Opção 6: Remover fim.

```c
void removerfim()
{
     conta *aux;
     conta *aux2;
     if (plista==NULL)
        printf("Lista Vazia");
     else
     {
         aux=plista;
         aux2=plista;
         while (aux->prox != NULL)
         {
             aux2 = aux;  
             aux=aux->prox;
         }   


        if (aux==aux2)
           plista=NULL;
        else
           aux2->prox = NULL;  
         free(aux);
          
         
     }      
     
}  
```

Primeiro o procedimento declara dois ponteiros <font color="red">aux</font> e <font color="red">aux2</font>. Checa para ver se a lista está vazia, e, caso não esteja vazia, o procedimento assume que tanto <font color="red">aux</font> quanto <font color="red">aux2</font> apontam para o começo da lista (primeiro elemento, <font color="palevioletred">plista</font>).

Depois ele percorre elemento por elemento da lista, até <font color="red">aux</font> chegar o último nó da lista, e <font color="red">aux2</font> chegar ao penultimo. Se <font color="red">aux</font> for igual a <font color="red">aux2</font>, significa que só existe um nó na lista, pois o loop while nem roda nesse caso, e ambos permanecem apontando em <font color="palevioletred">plista</font>. Dessa maneira, para remover basta igualar <font color="palevioletred">plista</font> a <font color="cyan">null</font>, apagando toda a lista encadeada.

Mas caso exista mais de um elemento, tanto <font color="red">aux</font> quanto <font color="red">aux2</font> estarão apontando para o último e penúltimo nó da lista respectivamente, então para remover o último basta dizer que o <font color="palevioletred">*prox</font> de <font color="red">aux2</font> (penultimo) é igual a <font color="cyan">null</font>. Depois, precisamos liberar da memória o <font color="red">aux</font>.

```c
aux2->prox = NULL;  
free(aux);
```
</font>
