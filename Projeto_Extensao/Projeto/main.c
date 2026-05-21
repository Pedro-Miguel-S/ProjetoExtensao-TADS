#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define  NUM_MAX_CAD 1024
#define NUM_MAX_NOME 101

/*-------------------- STRUCTS -----------------------*/
typedef struct{
    int id_gato;
    int ocupado;
    int microchip;
    char nome_gato[NUM_MAX_NOME];
    char sexo_gato;
    char pelagem[101];
    char lar_temporario[101];
    int castrado;
    char data_castracao[11];
    int vacina;
    char vacina_pendente[256];
    int status;
}Gato; //Struct sobre cadastro do gato

typedef struct{
    int id_tutor;
    int ocupado;
    char nome_tutor[NUM_MAX_NOME];
    char cpf[13];
    int idade;
    char email[101];
    char telefone[15];
}Tutor; //Struct sobre cadastro do adotante

void cadastrar_gato();

void leia_string(); //verificação universal de string --- nome, pelagem, lar
void leia_sexo();
void leia_booleano(); // verifica universal de booleano - vacina, castrado
void leia_pendencias(); //função para escrever as pendências e verificação
void leia_cpf(); //função para ler e verificar o cpf
void leia_email(); // função para ler e verificar email
void leia_telefone(); // função para ler e verificar o telefone

//tela de menu
int tela_menu_opcoes()
{
    //guarda a opção escolhida pelo usuário
    int opcao;

     //mostra a Tela com o "Menu de Opções"
    system("cls");
    printf(" ===============================");
    printf("\n SISTEMA DE ADOÇÃO MIAUADOTA");
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

void leia_string(char *str){ //função universarl para ler strings
    int erro;

    do{
        erro = 0; //sem erros

        printf("\n Digite o nome: ");
        scanf(" %100[^\n]", str);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(str) > 100){ //verificação do tamanho da string
            erro = 1;
            printf("\n ERRO: Máximo de 100 caracteres!");
        }
        if(strlen(str) < 3){
            erro = 1;
            printf("\n ERRO: Mínimo de 3 caracteres!");
        }

    }while(erro == 1);
}

void leia_sexo(char *sexo){ //função universal para ler o sexo
    int erro;

    do{
        erro = 0; //sem erros
        char strSexo[3];

        printf("\n Esolha o sexo (F/M): ");
        scanf(" %2[^\n]", strSexo);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(strSexo) == 1 ){  //verificação dos caracteres F ou M
            *sexo = toupper(strSexo[0]);
        }
        else{
            erro = 1;
        }

        if ((*sexo != 'M' && *sexo != 'F') || erro == 1){
            erro = 1;
            printf("\n ERRO: São apenas disponíveis os caracteres 'M' ou 'F'");
        }

    }while(erro == 1);
}

void leia_booleano(int *boolean){ //função universal para verificar 1 ou 0, ou seja, verdadeiro ou falso
    int erro;

    do{
        erro = 0; //sem erros

        printf("\n O gato é castrado?\n 1 - Sim\n 0 - Não\n Escolha: ");
        scanf("%d", boolean);


        if (*boolean != 0 && *boolean != 1){
            erro = 1;
            printf("\n ERRO: São apenas disponíveis os números 1 e 0");
        }

    }while(erro == 1);
}

void leia_pendencias(char *str){ //função para ler as pendencias de vacinação
    int erro;

    do{
        erro = 0; //sem erros

        printf("\n Pendencias da vacina: ");
        scanf(" %255[^\n]", str);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(str) > 254){ //verificação do tamanho da string
            erro = 1;
            printf("\n ERRO: Máximo de 254 caracteres!");
        }
    }while(erro == 1);
}

void leia_cpf(char *str){ //validacao e leitura do cpf
    int erro;

    do
    {
        erro = 0; //sem erros

        printf("\nDigite o CPF: ");
        scanf(" %12[^\n]", str);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(str) != 11) //verifica se o cpf tem 11 digitos
        {
            erro = 1;
            printf("ERRO: O CPF deve possuir 11 (onze) dígitos!\n");
        }

    }while(erro == 1);
}

void leia_email(char *email){ //função para ler e validar o email
    int erro;
    int arroba;

    do{
        erro = 0; //sem erros
        arroba = 0; //verificar arroba

        printf("\n Email: ");
        scanf(" %100[^\n]", email);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(email) > 100){ //verificação do tamanho da string
            erro = 1;
            printf("\n ERRO: Máximo de 100 caracteres!");
        }

        for(int i = 0; email[i] != '\0'; i++){ //for para verificar se o email cadastrado possui o @
            if(email[i] == '@'){
                arroba = 1;
                break;
            }
        }

        if(arroba == 0){ // if apenar para colocar o erro com uma mensagem diferente
            erro = 1;
            printf("\n ERRO: Email precisa ter @!");
        }

    }while(erro == 1);
}

void leia_telefone(char *numero){ //função para ler e verificar o telefone
    int erro;

    do
    {
        erro = 0; //sem erros

        printf("\nDigite o Telefone: ");
        scanf(" %14[^\n]", numero);

        fflush(stdin); //limpa o buffer do teclado

        if(strlen(numero) > 14){ //verificação do tamanho da string numero
            erro = 1;
            printf("\n ERRO: Máximo de 14 caracteres!");
        }

    }while(erro == 1);
}
