#include <stdio.h>
#include <string.h>// strcpy,strlen, strcmp
#include <locale.h>// acentua��o


/*
 OBSERVA��ES DO C�DIGO:

Agenda de contatos que realiza as seguintes atividades: Adi��o de Contato, Remo��o de Contato,
Busca de Contato (por Nome e por Telefone) e Listar os Contatos (em Ordem Alfab�tica e
agrupar por Tipo de Rela��o). Cada contato ser� composto de Nome (at� 100 caracteres), Telefone (11 d�gitos),
Endere�o (at� 300 caracteres), Tipo de Rela��o (O usu�rio poder� escolher entre 3 op��es de rela��o)
e email (at� 50 caracteres).

Em termos l�gicos fizemos um semi CRUD(Que nesse caso seria um CRSD(CREATE, READ, SORT, DELETE)) utilizando estrutura e
vetor est�tico para armazenar os dados.

REFER�NCIAS:

clubedohardware.com.br; pt.stackoverflow.com; embarcados.com.br; t.me/cppbrazil; Jo�o Canuto(Monitor); www.vivaolinux.com.br;

Programa��o descomplicada https://www.youtube.com/playlist?list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp (Ordena��o, Busca)
Xave Coding https://www.youtube.com/playlist?list=PL3ZslI15yo2pCf0WpZmV-ga02kMPxKH3p (Struct, String, Fun��es)


*/

//Fun��o para limpar tela
void CleanScreen(){
system("clear");
//system("cls");//caso o SO seja Windows
}

void ShowMenu (){//fun��o mais utilizada pelo programa, exibe o menu

    printf("\n#####################################################\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#              1 - Listar Contatos                  #\n"
           "#              2 - Buscar Contatos                  #\n"
           "#              3 - Adicionar Contato                #\n"
           "#              4 - Remover Contato                  #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#      Feito por: Jana�na, Jo�o Pedro e Vinicius    #\n"
           "#####################################################\n");
}

//Criando a struct respons�vel pela "uni�o" dos dados de um contato para que todos dados sejam salvos somente em uma posi��o do vetor
//Utilizamos o typedef junto com o struct para transformar essa struct em um novo tipo de vari�vel
typedef struct dados_contact{
    char Name[101];//respons�vel por armazenar o nome
    char Telefone[12];//respons�vel por armazenar o telefone
    char Address[301];//respons�vel por armazenar o Endere�o
    int RelationType;//respons�vel por armazenar o tipo de rela��o
    char Email[51];//respons�vel por armazenar o e-mail
}DadosCtt;//aqui demos o nome desse novo tipo de vari�vel

DadosCtt dados[1000];// Criamos um vetor est�tico para armazenar a struct de dados dos contatos e j� damos o limite m�ximo de contatos


DadosCtt *AddContact(int pos){
    char NameCMPExist[101];//Recebe o nome e compara
    char TelCMPExist[12];//Recebe o telefone e compara
    char EmailTemp[51];//Recebe o e-mail temporariamente
    char TelTemp[12];//Recebe o telefone temporariamente
    int DadosTam = 0;//Recebe o tamanho dos dados inseridos
    int QtdArroba = 0;//Contador de arrobas do e-mail
    
    // o usu�rio ir� inserir um nome de at� 100 caracteres
    printf("\nNome: ");
    fgets(NameCMPExist,100,stdin);
    fflush(stdin);//limpando stdin

    for(int i=0;i<pos;i++){//Percorre toda lista de contatos
        if(strcmp(NameCMPExist,dados[i].Name) == 0){//verifica se existe algum nome igual cadastrado
            printf("Este n�mero j� est� salvo, delete ele caso queira cadastra-lo novamente!\n");
          
          return 0;
        }
    }
        
    //O usu�rio ir� inserir um endere�o de at� 300 caracteres
    printf("\nEndere�o: ");
    fgets(dados[pos].Address,300, stdin);
    fflush(stdin);

    //O usu�rio poder� inserir um email de at� 50 caracteres
    printf("\nEmail: ");
    fgets(EmailTemp, 50, stdin);

    DadosTam = strlen(EmailTemp);//envia o tamanho do e-mail para a vari�vel DadosTam
    for(int i= 0;i < DadosTam;i++){//percorre todo e-mail
        char a = EmailTemp[i];//o char a assume a posi��o i de cada vez que o for rodar, cada posi��o de i vale como uma letra  
        if(a == '@'){//caso alguma posi��o i seja equivalente ao caractere @
            QtdArroba++;//Essa vari�vel ir� somar mais 1 a ela mesma.
        }
    }

DadosTam = 0;//Zera o tamanho da vari�vel para ser reutilizada
        
    if(QtdArroba>1 || QtdArroba<1){//Caso o formato de e-mail esteja incorreto(e-mail s� pode possuir um arroba)
        printf("\nFormato de e-mail inv�lido, recomece seu cadastro!\n");
            
      return 0;
    }
    
    if (QtdArroba == 1){
        strcpy(dados[pos].Email, EmailTemp);
    }


    //O usu�rio ir� inserir um telefone de 11 digitos
    printf("\nTelefone(11 Digitos no M�ximo): ");
    scanf("%s", &TelTemp);
    getchar();//Consome o enter inserido pelo usu�rio
    
    DadosTam = strlen(TelTemp);//Envia o tamanho do telefone para DadosTam
    
    if(DadosTam != 11){//Caso o tamanho do telefone seja diferente de 11 o mesmo ser� considerado inv�lido
        printf("\nQuantidade de digitos inv�lida, recomece seu cadastro!\n");

      return 0;  
    }

    strcpy(TelCMPExist, TelTemp);//Caso esteja tudo ok o telefone passar� para pr�xima verifica��o

    for(int i=0;i<pos;i++){//percorre toda lista de contatos
        if(strcmp(TelCMPExist,dados[i].Telefone) == 0){//Comparando o telefone inserido com todos cadastrados
            printf("Este n�mero j� est� salvo, delete ele caso queira cadastra-lo novamente!\n");//caso exista algum igual
            
          return 0;
        }
    }
    
    //O usu�rio poder� escolher entre 3 op��es de rela��o
    printf("\nTipo de rela��o com o contato(1 = Pessoal \\ 2 = Profissional \\ 3 = Outros): ");
    scanf("%d", &dados[pos].RelationType);
    getchar();//Consome o enter inserido pelo usu�rio

    strcpy(dados[pos].Name, NameCMPExist);//o strcpy � chamado para passar a string da vari�vel comparadora para a struct
    strcpy(dados[pos].Telefone, TelCMPExist);

    return 0;//finaliza a fun��o
}

void ListContacts(int Cont){
int i,j;//declaro vari�veis utilizadas na posi��o

    //Ordena��o por Insertion Sort(Em ordem alfabetica)
    DadosCtt AuxSort;//Crio uma struct do mesmo tipo da minha struct que armazena os dados
    for(i = 0; i < Cont; i++){//percorre o vetor para ordenar os contatos pela ordem alfabetica dos nomes
        AuxSort = dados[i];//insiro os dados de cada posi��o da minha struct Dados nesta struct Ordenadora
                           //O programa ordena por ordem alfabetica, come�ando pelo nome do 1� contato
                           //indo at� o �ltimo contato, movendo suas posi��es at� que estejam todos em ordem alfabetica.
        for(j=i;(j>0) && (strcmp(AuxSort.Name,dados[j-1].Name)<0);j--)//Ordeno alfabeticamente atrav�s deste for
            dados[j] = dados[j - 1];//Vou movendo meu contato para esquerda at� que o contato esteja na posi��o correta
        
        dados[j] = AuxSort;//Devolvo o contatos que est� na posi��o correta para minha struct de contatos
    }//reinicia todo processo


    printf("####### LISTA DE CONTATOS #######\n");

    printf("\n------- CONTATOS PESSOAIS -------\n");

    int checkerCtt = 0;// Vari�vel respons�vel por checar se existe algum contato em determinado tipo de rela��o

    //Ap�s possuirmos todos contatos em ordem alfabetica os mesmos s�o separados em tipos de rela��o, continuando em ordem alfabetica
    //O que acontece � que o for a seguir percorre todos contatos inserindo no print apenas os contatos que possuem a condi��o do if
    //Para que os contatos sejam exibidos de forma correta, foi utilizado um for e um if para cada tipo de rela��o 
    for(i=0; i<Cont; i++) {//percorre todo vetor est�tico verificando se o tipo de rela��o de algum contato � igual a 1.
        if(dados[i].RelationType == 1){

            printf("Nome: %s", dados[i].Name);
            printf("Telefone: %s\n", dados[i].Telefone);
            printf("Endere�o: %s", dados[i].Address);
            printf("Email: %s\n", dados[i].Email);
            checkerCtt++;
        }

    }

    //Caso o if acima n�o tenha se tornado v�lido nenhuma vez, este pr�ximo if se torna verdadeiro
    if(checkerCtt==0){
        printf("Nenhum Contato encontrado!\n");
    }

    printf("------- RELACAO PROFISSIONAL -------\n");
    
    checkerCtt = 0;// Zerando vari�vel respons�vel por checar se existe algum contato em determinado tipo de rela��o

    for(i=0; i<Cont; i++) {
        if(dados[i].RelationType == 2){

            printf("Nome: %s", dados[i].Name);
            printf("Telefone: %s\n", dados[i].Telefone);
            printf("Endere�o: %s", dados[i].Address);
            printf("Email: %s\n", dados[i].Email);
            checkerCtt++;
        }
    }
    
    if(checkerCtt==0){
        printf("Nenhum Contato encontrado!\n");
    }


    printf("------- OUTRAS RELACOES -------\n");

    checkerCtt = 0;// Zerando vari�vel respons�vel por checar se existe algum contato em determinado tipo de rela��o

    for(i=0; i<Cont; i++) {

        if(dados[i].RelationType == 3){

            printf("Nome: %s", dados[i].Name);
            printf("Telefone: %s\n", dados[i].Telefone);
            printf("Endere�o: %s", dados[i].Address);
            printf("Email: %s\n", dados[i].Email);
            checkerCtt++;
        }

    }

    if(checkerCtt==0){
        printf("Nenhum Contato encontrado!\n");
    }

}

void searchContacts(int contt){
    char nome[100]; //variav�l que armazena o nome a ser buscado
    char tel[12];
    int i,option;

    printf("\nInforme a op��o para buscar(1 = Nome \\ 2 = Telefone): ");
    scanf("%d", &option);
    getchar();

    switch(option){
    case 1:

        printf("\nDigite o nome para busca: "); //intera��o com o usu�rio p/entrada e leitura de dados
        fgets(nome,100,stdin);

        for(i=0;i<contt;i++){ //leitura fazendo referencia a variavel name da struct dados (leitura da struct)
            if(strcmp(nome,dados[i].Name) == 0){ //compara a variavel nome com os dados armazenados na struct dados em Name,
                                            //se for verdadeira entra nas condicionais

                if(dados[i].RelationType == 1){ //inicia a condicional relacionando o nome com dado do tipo de rela��o que ele est� vinculado
                    printf("\n------- INFORMA��ES DO CONTATO -------\n"); //se no caso o tipo de rela��o do nome for == 1 ele entre no primeiro if
                    printf("\n\tNome:    %s", dados[i].Name);              // e assim sucessivamente, relacionando o nome ao tipo de rela��o
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de rela��o: Pessoal");
                    printf("\n--------------------------------------\n");
                  
                  return 0;
                }

                if(dados[i].RelationType == 2){
                    printf("\n------- INFORMA��ES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de rela��o: Profissional");
                    printf("\n--------------------------------------\n");
                  
                  return 0;
                }

                if(dados[i].RelationType == 3){
                    printf("\n------- INFORMA��ES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de rela��o: Outras rela��es");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

            }
        }
    
    break;

    case 2:

        printf("\nDigite o telefone para busca: ");
        fgets(tel,12,stdin);
        getchar();

        for(i=0;i<contt;i++){
            if(strcmp(tel,dados[i].Telefone) == 0){


                if(dados[i].RelationType == 1){
                    printf("\n------- INFORMA��ES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de rela��o: Pessoal");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

                if(dados[i].RelationType == 2){
                    printf("\n------- INFORMA��ES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de rela��o: Profissional");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

                if(dados[i].RelationType == 3){
                    printf("\n------- INFORMA��ES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de rela��o: Outras rela��es");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

            }


        }

}

    if(strcmp(tel,dados[i].Telefone) != 0){
        printf("\nContato n�o cadastrado!\n");
      return 0;
    }
}


DadosCtt *DelContact(int Lastposition){//Recebe a posi��o do �ltimo vetor e nomeia-o como Lastposition

    char NomeCMPDel[101];// vari�vel que ir� receber o telefone do contato que o usu�rio deseja deletar (NomeComparatorDelete)
    int op2; // vari�vel que ir� receber a op��o de busca de contato que o usu�rio ir� utilizar
    char TelCMPDel[12];// vari�vel que ir� receber o telefone do contato que o usu�rio deseja deletar (TelefoneComparatorDelete)
    int i, n;// Vari�vel contadora para percorrer toda lista;

    printf("\nDigite 1 para pesquisar por nome ou digite 2 para pesquisar por telefone: ");
    scanf("%d", &op2);
    //Envia a op��o do usu�rio para o endere�o de mem�ria da vari�vel op2
    getchar();//Consome o enter

    switch (op2)//envia o dado da vari�vel op2 para o switch case comparar com os casos
    {

    case 1:
    //caso o usu�rio envie 1 para op2

        printf("Informe o nome do contato que deseja deletar: ");
        fgets(NomeCMPDel, 101, stdin); //Enviando o nome do contato que o usu�rio deseja deletar para
                                      //a vari�vel NomeCMPDel

        for(i=0;i<Lastposition; i++){//percorre toda lista de contatos
            if(strcmp(NomeCMPDel,dados[i].Name) == 0){//condi��o respons�vel por checar se h� algum nome igual ao inserido
                for(n = i; n < Lastposition; n++)//percorre do contato desejado para apagar at� o �ltimo(Este for n�o possui chaves, pois s� existe uma instru��o pra ele que � a linha logo abaixo)
                    dados[n] = dados[n + 1];//movendo cada contato para uma posi��o a esquerda
                                        //levando o contato desejado para �ltima posi��o
                Lastposition--;//Diminui uma posi��o para esquerda, que no caso apaga tamb�m o contato desejado

                printf("Contato excluido com sucesso!");

              return 0;
            
            }

        }

    break;

    case 2:
    //caso o usu�rio envie 2 para op2

        printf("Informe o telefone do contato que deseja deletar: ");
        fgets(TelCMPDel, 12, stdin); //Enviando o telefone do contato que o usu�rio deseja deletar para
                                     //a vari�vel TelCMPDel

        for(i=0;i<Lastposition; i++){// for respons�vel por percorrer toda lista
            if(strcmp(TelCMPDel, dados[i].Telefone) == 0){// if testador caso encontre o telefone na lista
                for(n = i; n < Lastposition; n++)
                    dados[n] = dados[n + 1];

                Lastposition--;

                printf("Contato excluido com sucesso!");

              return 0;
            }

        }


    }
}

int main(){
    setlocale(LC_ALL, "");

    //Declara��o de vari�veis(Op��o do usu�rio para qual fun��o utilizar; Posi��o inicial do vetor que ir� guardar os dados)
    int option;
    int pos=0;

    //Inicia o Programa em Loop
    do{

        //Zerando a vari�vel de op��o do menu
        option = 0;

        //Chama fun��o menu para exibi-lo
        ShowMenu();

        //Selecionar op��o do menu inicial
        printf("Digite a op��o desejada: ");
        scanf("%d", &option);
        getchar();//Consome o enter digitado


        //switch case das op��es do menu para chamar as fun��es desejadas
        switch (option){

        //Listar contatos
        case 1:
            CleanScreen();
            if(pos>0){
                ListContacts(pos++);
            }
            else{
                printf("Nenhum Contato cadastrado!\n");
            }
        break;

        //Buscar Contato
        case 2:
            CleanScreen();
            if(pos>0){
                searchContacts(pos++);
            }else
            {
                printf("Voc� n�o pode buscar nenhum contato, pois n�o possui nenhum contato cadastrado!\n");
            }
        break;

        //Adicionar contato
        case 3:
            CleanScreen();
            AddContact(pos++);
        break;

        //Deletar Contato    
        case 4:
            CleanScreen();
            if(pos>0){
            DelContact(pos++);
            }else
            {
                printf("Voc� n�o pode deletar nenhum contato, pois n�o possui nenhum contato cadastrado!\n");
            }
        break;

        //Caso o usu�rio escolha uma op��o incorreta
        default:
            printf("Op��o incorreta!\n");
        break;
        }
    }while (option==1 || option==2 || option==3 || option==4);//O while ir� verificar se a op��o selecionada foi um desses 4 valores

    return 0;
}
