#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca para o uso de strings

int registro(){ //função de registro do usuário

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do sistema. Ficou definido para portugues.

    //definindo variáveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    //inserção da chave primária = cpf
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    //copiando a string cpf para string arquivo
    strcpy(arquivo, cpf);

    FILE *file; //define que um arquivo file será criado ou modificado
    file = fopen(arquivo, "w"); //cria arquivo
    fprintf(file, cpf); //escreve no arquivo
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a"); // "a" de atualizar
    fprintf(file, " , "); // coloca uma vírgula entre as strings
    fclose(file); //fecha o arquivo novamente

    printf("Digite o nome que deseja registrar: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " , ");
    fclose(file);

    printf("Digite o sobrenome do mesmo: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " , ");
    fclose(file);

    printf("Digite o cargo do individuo: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
}

int consulta(){

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do sistema. Ficou definido para portugues.

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); //abre o arquivo e lê o seu conteudo

    //condicional caso o arquivo esteja nulo
    if(file == NULL){
        printf("CPF NAO LOCALIZADO!\n");
    }

    //loop para printar na tela o conteudo que está dentro do arquivo
    while(fgets(conteudo, 200, file) != NULL){
        printf("\nEssas sao as informacoes do usuario: \n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int excluir(){

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do sistema. Ficou definido para portugues.

    char cpf[40];

    printf("Digite o CPF a ser excluido: ");
    scanf("%s", cpf);

    //deleta o arquivo "cpf" -> file
    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    //caso o arquivo esteja nulo
    if(file == NULL){
        printf("O CPF nao se encontra no sistema.\n");
        system("pause");
    }

}

int main(){

	int opcao = 0; // variável para armazenar a opção que o usuário desejar
	int i = 1;
	char senhadigitada[10];
	int comparacao;

    printf("-> Cartorio Da EBAC <-\n\n");
    printf("-> Login de Administrador <-\n");
    printf("-> Digite sua senha: ");
    scanf("%s", &senhadigitada);

    comparacao = strcmp(senhadigitada, "admin");

    if(comparacao == 0){

        system("cls");
        for (i = 1; i == 1;){

            system("cls");

            setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem do sistema. Ficou definido para portugues.

            printf("-> Cartorio Da EBAC <-\n\n"); //Título do sistema

            printf("-> Menu <-\n\n"); //Inicio do menu

            printf("->Escolha uma das opcoes a seguir:\n\n");
            printf("\t1 -> Registrar usuario\n");
            printf("\t2 -> Consultar usuario\n");
            printf("\t3 -> Excluir usuario\n");
            printf("\t4 -> Sair do sistema\n\n"); // Fim do menu

            printf("Digite a opcao desejada: ");
            scanf("%d", &opcao); // armazenamento da opção digitada pelo usuário

            system("cls"); //limpar a tela

            switch (opcao)
            {
            case 1:
                registro(); //chama a função registro
                break;

            case 2:
                consulta(); //chama a função consulta
                break;

            case 3:
                excluir(); //chama a função excluir
                break;

            case 4:
                printf("Ate a proxima!\n");
                return 0;
                break;

            default: // caso o usuário digite um número indisponivel no menu
                printf("Opcao indisponivel!\n");
                system("pause");
                break;
            }
        }
    }else{
            printf("Senha incorreta!\n");
    }
	printf("\nSoftware desenvolvido por Daniel Moraes Cardoso, atraves do curso oferecido pela EBAC.\n");
}
