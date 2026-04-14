#include <stdio.h>

typedef struct {
        int id;
        char nome[50];
        char telefone[15];
        char tipo[10]; 
    } contato;

    int incluirContato(contato contato[], int *totalContatos, int *idcontato) {
        if (*totalContatos >= 100) {
            printf("Agenda cheia! Nao e possível incluir mais contatos.\n");
            return -1;
        }
        
        contato[*totalContatos].id = *idcontato + 1;

        printf("id do contato: %d\n", contato[*totalContatos].id);
        printf("\n");
        printf("Digite o nome do contato: ");
        scanf("%s", contato[*totalContatos].nome);
        printf("Digite o telefone do contato: ");
        scanf("%s", contato[*totalContatos].telefone);
        printf("Digite o tipo do contato (pessoal/trabalho): ");
        scanf("%s", contato[*totalContatos].tipo);
        printf("\n");

        (*idcontato)++;
        (*totalContatos)++;
        
        printf("Contato incluido com sucesso!\n");
        return 0;
    }

    int excluircontatos(contato contato[], int *totalContatos) {
        int id;
        printf("Digite o ID do contato a ser excluido: ");
        scanf("%d", &id);
        for (int i = 0; i < *totalContatos; i++) {
            if (contato[i].id == id) {
                for (int j = i; j < *totalContatos - 1; j++) {
                    contato[j] = contato[j + 1];
                }
                (*totalContatos)--;
                printf("\n");
                printf("Contato excluido com sucesso!\n");
                return 0;
            }
        }
        printf("\n");
        printf("Contato nao encontrado!\n");
        return -1;
    }

    int listarContatos(contato contato[], int totalContatos) {
        if (totalContatos == 0) {
            printf("Nenhum contato cadastrado.\n");
            return -1;
        }

        printf("voce tem %d contatos cadastrados.\n", totalContatos);
        printf("==========================\n");
        printf("Lista de contatos:\n");
        for (int i = 0; i < totalContatos; i++) {
            printf("\nID: %d\n Nome: %s\n Telefone: %s\n Tipo: %s\n", 
                contato[i].id, 
                contato[i].nome, 
                contato[i].telefone, 
                contato[i].tipo);
        } printf("==========================\n");
        return 0;
    }

    int alterarcontatos(contato contato[], int totalContatos) {
        int id;
        printf("Digite o ID do contato a ser alterado: ");
        scanf("%d", &id);
        for (int i = 0; i < totalContatos; i++) {
            if (contato[i].id == id) {
                printf("Digite o novo nome do contato: ");
                scanf("%s", contato[i].nome);
                printf("Digite o novo telefone do contato: ");
                scanf("%s", contato[i].telefone);
                printf("Digite o novo tipo do contato (pessoal/trabalho): ");
                scanf("%s", contato[i].tipo);
                printf("Contato alterado com sucesso!\n");
                return 0;
            }
        }
        printf("\n");
        printf("Contato nao encontrado!\n");
        return -1;
    }

    int localizarcontatos(contato contato[], int totalContatos) {
        int id;
        printf("Digite o ID do contato a ser localizado: ");
        scanf("%d", &id);
        for (int i = 0; i < totalContatos; i++) {
            if (contato[i].id == id) {
                printf("\n");
                printf("ID: %d\n Nome: %s\n Telefone: %s\n Tipo: %s\n",
                    contato[i].id, 
                    contato[i].nome, 
                    contato[i].telefone, 
                    contato[i].tipo);
                return 0;
            }
        }
        printf("\n");
        printf("Contato nao encontrado!\n");
        return -1;
    }


    int main() {

    contato contato[100]; 
    static int totalContatos = 0;
    static int idcontatos = 0;
    int opcao; 

    do {
    
        printf("Menu:\n");
        printf("1. Incluir um novo contato\n");
        printf("2. Excluir um contato existente\n");
        printf("3. Alterar um contato existente\n");
        printf("4. Listar todos os contatos cadastrados\n");
        printf("5. Localizar um contato\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                printf("\n");
                incluirContato(contato, &totalContatos, &idcontatos);
                printf("\n");
                break;
              
            case 2: 
                printf("\n");
                excluircontatos(contato, &totalContatos);   
                printf("\n");      
                break;

            case 3: 
                printf("\n");
                alterarcontatos(contato, totalContatos);
                printf("\n");
                break;

            case 4: 
                printf("\n");
                listarContatos(contato, totalContatos);
                printf("\n");
                break;

            case 5: 
                printf("\n");
                localizarcontatos(contato, totalContatos);
                printf("\n");
                break;

            case 0: 
                printf("\n");
                printf("Saindo do programa...\n");
                break;

            default:
                printf("\n");
                printf("Opcao invalida! Tente novamente.\n");
                printf("\n");
                break;
        }
        } while (opcao != 0);
       
    }