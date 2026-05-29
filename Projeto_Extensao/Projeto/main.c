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

Gato gatos[NUM_MAX_CAD];
int qtd_gatos = 0;

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
void cadastrar_tutor();

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

     do {
        // 1. Mostra o menu e captura a opção escolhida pelo usuário
        opcao = tela_menu_opcoes();

        // 2. Avalia a opção escolhida
        switch (opcao) {
            case 1:
                printf("--- CADASTRO DE GATO ---");
                // === AQUI A FUNÇÃO É CHAMADA ===
                cadastrar_gato();

                // Pausa a tela para o usuário ver a mensagem de sucesso
                printf("\nPressione ENTER para voltar ao menu...");
                getchar(); // Captura o ENTER pendente se houver
                getchar(); // Aguarda o usuário pressionar ENTER
                break;

            case 2:
                printf("--- CADASTRO DE TUTOR E ADOCAO ---");
                cadastrar_tutor();

                // Pausa a tela para o usuário ver a mensagem de sucesso
                printf("\nPressione ENTER para voltar ao menu...");
                getchar(); // Captura o ENTER pendente se houver
                getchar(); // Aguarda o usuário pressionar ENTER
                break;

            case 3:
                printf("\n[Em desenvolvimento] Consulta de Registros...\n");
                system("pause");
                break;

            case 0:
                printf("\nSaindo do programa... Obrigado!\n");
                break;

            default:
                printf("\nERRO: Opção inválida! Tente novamente.\n");
                system("pause");
                break;
        }

    } while (opcao != 0); // O loop continua enquanto a opção for diferente de 0

    return 0;
}

/*-------------------FUNÇÕES--------------------*/

void leia_string(char *str, char mensagem[]){ //função universarl para ler strings
    int erro;

    do{
        erro = 0; //sem erros

        printf("%s", mensagem);
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

void leia_idade (int *idade){
    int erro;

    do
    {
        erro = 0; //sem erros

        printf("\nDigite a idade: ");
        scanf(" %d", idade);

        fflush(stdin); //limpa o buffer do teclado

        if(*idade < 18) //verifica se é maior de 18
        {
            erro = 1;
            printf("ERRO: O tutor deve ser maior de 18 anos!\n");
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

void leia_adocao() {
    int microchip_escolhido;
    int encontrado = 0;

    printf("\nDigite o MICROCHIP do gato que sera adotado por este tutor: ");
    scanf("%d", &microchip_escolhido);



    for(int i = 0; i < qtd_gatos; i++) {

        if(gatos[i].microchip == microchip_escolhido &&
            gatos[i].status == 1) {

            // marca como adotado
            gatos[i].status = 0;

            encontrado = 1;

            printf("\nGato '%s' adotado com sucesso!",
                    gatos[i].nome_gato);
        break;
    }
}

if(encontrado == 0) {
    printf("\nERRO: Gato nao encontrado ou ja adotado!");
}
}


void cadastrar_gato() {
    // 1. Criamos uma variável do tipo da sua Struct Gato para agrupar os dados
    Gato novo_gato;

    // Inicializa campos de controle da struct
    novo_gato.ocupado = 1;
    novo_gato.status = 1; // Ativo no sistema

    printf("\nDigite o numero do Microchip (Apenas numeros): ");
    scanf("%d", &novo_gato.microchip);

    // 2. Limpa o buffer do teclado de forma segura
    fflush(stdin);

    // 3. USO DA SUA FUNÇÃO UNIVERSAL DE STRING (Nome)
    leia_string(novo_gato.nome_gato, "\nDigite o nome: ");

    // 4. USO DA SUA FUNÇÃO UNIVERSAL DE SEXO
    // Como sexo_gato é um char simples na struct, passamos com '&'
    leia_sexo(&novo_gato.sexo_gato);

    if (novo_gato.sexo_gato == 'F') {
        printf("Sexo cadastrado com sucesso: Feminino\n");
    } else {
        printf("Sexo cadastrado com sucesso: Masculino\n");
    }

    // 5. REAPROVEITANDO A FUNÇÃO DE STRING PARA PELAGEM E LAR TEMPORÁRIO
    leia_string(novo_gato.pelagem, "\nDigite a pelagem: ");

    leia_string(novo_gato.lar_temporario, "\nDigite o lar temporario: ");

    // 6. USO DA SUA FUNÇÃO UNIVERSAL BOOLEANA (Castrado)
    // Adaptado para usar a sua função leia_booleano (0 ou 1) que está no código
    leia_booleano(&novo_gato.castrado);

    if(novo_gato.castrado == 1) {
        printf("\n Digite a data da castracao (DD/MM/AAAA): ");
        scanf(" %10[^\n]", novo_gato.data_castracao);
        fflush(stdin);
    } else {
        strcpy(novo_gato.data_castracao, "N/A");
    }

    // 7. USO DA SUA FUNÇÃO UNIVERSAL BOOLEANA + PENDÊNCIAS (Vacina)
    // Usamos a pergunta invertida para fazer sentido com o seu leia_booleano (1 para Sim/Em dia, 0 para Não)
    printf("\n O gato possui TODAS as vacinas em dia?");
    leia_booleano(&novo_gato.vacina);

    if(novo_gato.vacina == 0) {
        // Se não está em dia, chama a sua função de pendências
        leia_pendencias(novo_gato.vacina_pendente);
    } else {
        strcpy(novo_gato.vacina_pendente, "Nenhuma");
    }

    novo_gato.id_gato = qtd_gatos + 1;

    // salva no vetor
    gatos[qtd_gatos] = novo_gato;

    // aumenta quantidade cadastrada
    qtd_gatos++;

    printf("\n=========================================");
    printf("\n*** SUCESSO: Felino '%s' gravado no banco de dados! ***\n", novo_gato.nome_gato);

}

void cadastrar_tutor() {
    Tutor novo_tutor;

    // Inicializa campos de controle da struct
    novo_tutor.ocupado = 1;

    leia_cpf(novo_tutor.cpf);

    leia_string(novo_tutor.nome_tutor, "\nDigite o nome: ");

    leia_idade(&novo_tutor.idade);

    leia_email(novo_tutor.email);

    leia_telefone(novo_tutor.telefone);

   printf("\n--- GATOS DISPONIVEIS PARA ADOCAO ---\n");

    for(int i = 0; i < qtd_gatos; i++) {

        // status == 1 significa disponível
        if(gatos[i].status == 1) {

            printf("\nMicrochip: %d",
                gatos[i].microchip);

            printf(" | Nome: %s",
                gatos[i].nome_gato);

            printf(" | Sexo: %c",
                gatos[i].sexo_gato);

            printf("\n------------------------------------");
        }
    }

    leia_adocao();



    printf("\n*** SUCESSO: Tutor %s cadastrado e Adocao concluida! ***", novo_tutor.nome_tutor);
}
