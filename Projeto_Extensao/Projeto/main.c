#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define  NUM_MAX_CAD 1024

/*-------------------- STRUCTS -----------------------*/
typedef struct{
    int id_gato;
    int ocupado;
    int microchip;
    char nome_gato[40];
    char sexo_gato;
    char pelagem[20];
    char lar_temporario[127];
    int castrado;
    char data_castracao[11];
    int vacina;
    char vacina_pendente[256];
    int status;
}Gato; //Struct sobre cadastro do gato

typedef struct{
    int id_tutor;
    int ocupado;
    char nome_tutor[100];
    char cpf[13];
    int idade;
    char rg[20];
    char email[100];
    char telefone[20];
}Tutor; //Struct sobre cadastro do adotante

void cadastrar_gato();

void leia_nome();
void leia_sexo();

//tela de menu
int tela_menu_opcoes()
{
    //guarda a opção escolhida pelo usuário
    int opcao;

     //mostra a Tela com o "Menu de Opções"
    system("cls");
    printf(" ===============================");
    printf("\n SISTEMA DE ADOCAO MIAUADOTA");
    printf("\n ===============================");

    printf("\n 1 - Cadastar Novo Gato");
    printf("\n 2 - Cadastar Tutor e Adotar Gato");
    printf("\n 3 - Consultar Registros");
    printf("\n 0 - Sair do Programa");

    //faz a leitura da opção escolhida
    printf("\n\n Escolha uma opção: ");
    int erro = scanf("%d", &opcao);

    //verifica se houve uma falha na leitura do scanf
    if(erro != 1) {
        //limpa o buffer do tecaldo (windows)
        fflush(stdin);
        //como teve uma falha na leitura, marca uma opção inválida
        opcao = -1;
    }

    //retorna a opção escolhida
    return opcao;
}

int main()
{
    //coloca o idioma como português brasil
    setlocale(LC_ALL, "Portuguese");
    system("chcp 1252 > null");

    int opcao;

    opcao = tela_menu_opcoes();


    return 0;
}

/*-------------------FUNÇÕES--------------------*/

void leia_nome(char *str){
    int erro;

    do{
        erro = 0; //sem erros

        printf("\nDigite o nome: ");
        scanf(" %255[^\n]", str);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(str) > 254){
            erro = 1;
            printf("\nERRO: Máximo de 254 caracteres!");
        }
        if(strlen(str) < 3){
            erro = 1;
            printf("\nERRO: Mínimo de 3 caracteres!");
        }

    }while(erro == 1);
}

void leia_sexo(char *sexo){
    int erro;

    do{
        erro = 0; //sem erros
        char strSexo[3];

        printf("\nEsolha o sexo (F/M): ");
        scanf(" %2[^\n]", strSexo);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(strSexo) == 1 ){
            *sexo = toupper(strSexo[0]);
        }
        else{
            erro = 1;
        }

        if ((*sexo != 'M' && *sexo != 'F') || erro == 1){
            erro = 1;
            printf("\nERRO: São apenas disponíveis os caracteres 'M' ou 'F'");
        }

    }while(erro == 1);
}
