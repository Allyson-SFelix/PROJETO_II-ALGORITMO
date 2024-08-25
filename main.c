#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    float litro,valorLitro,total;
}GasolinaComum;
typedef struct{
    float litro,valorLitro,total;
}Diesel;
typedef struct{
    char nome[31];
    char email[80];
    char senha[13];
    GasolinaComum  abastecimentoComum[20];
    Diesel abastecimentoDiesel[20];
    int numeroVendaDiesel;
    int numeroVendaGasolina;
}Contas;
Contas usuario[1];

void entrar_sair(int valorEntrarSair);
void cadastro(int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroValorNumeroUsuario, int *ponteiroQuantVendasPorTipo);
int verificacao_email(int *ponteiroValorNumeroUsuario);
//
void menu(int valorEntrarSair,int *ponteiroValorNumeroUsuario,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
void login(int valorEntrarSair,int *ponteiroValorNumeroUsuario,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
void mudar_usuario(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
//
void rifa(int valorEntrarSair,int *ponteiroValorNumeroUsuario,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
//
void menuGasolina(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
void adicionar_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
void listar_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGasa,int *pontNumeroVendaDiesel);
void excluir_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
void editar_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
int verificacaoQuantidadeGas(int *ponteiroValorNumeroUsuario,int *ponteiroQuantVendasPorTipo);
//
void menuDiesel(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVenda,int *pontNumeroVendaGas);
void adicionar_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVenda,int *pontNumeroVendaGas);
void excluir_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVenda,int *pontNumeroVendaGas);
void listar_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVenda,int *pontNumeroVendaGas);
void editar_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVenda,int *pontNumeroVendaGas);
int verificacaoQuantidadeDiesel(int *ponteiroValorNumeroUsuario,int *ponteiroQuantVendasPorTipo);
//
//
void somar_caixa(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel);
//
//
int verificacaoQuantidadeGas(int *ponteiroValorNumeroUsuario,int *ponteiroQuantVendasPorTipo){
        // quero fazer usando uma variavel de soma dentro de for quando a varaivel total for diferente de 0
        int varSomadora=0;
        for(int i=0;i<20;i++){
            if(usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].total !=0){
                    varSomadora++;
            }
        }
        if(varSomadora>=10){
            return 0;
        }else{
            return 1;
        }
}
//
void editar_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    printf("LISTANDO\n");
    int existe=0;
    for (int i=0;i<20;i++){
        if(usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro!=0){
            printf("\n-------------------------\n");
            printf(" ABASTECIMENTO:\n litros=%.2f\n valor=%.2f\n Numero da Venda=%d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].total,i+1);
            printf("\n-------------------------\n");
            existe++;
        }
    }
    if(existe==0){
        printf("NAO HA ABASTECIMENTOS\n");
        menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }else{
        printf("DIGITA O NUMERO DA VENDA QUE ALMEJA EDITAR ");
        int codEditar=0;
        scanf("%d",&codEditar);
        codEditar--;
        if(codEditar>=0 && codEditar<20){
            if (usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codEditar].total!=0){
                printf("DIGITA O VALOR DA VENDA :\n");
                scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codEditar].total);
                usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codEditar].litro=usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codEditar].total/usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codEditar].valorLitro;
                printf("A VENDA FOI EDITADA COM SUCESSO \n");
                menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
            }else{
                printf("OPCAO INVALIDA\n");
                menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
            }
        }else{
            printf("OPCAO INVALIDA\n");
            menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        }
    }
}
//
void excluir_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    printf("LISTANDO\n");
    int existe=0;
    for (int i=0;i<20;i++){
        if(usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro!=0){
            printf("\n-------------------------\n");
            printf(" ABASTECIMENTO:\n litros=%.2f\n valor=%.2f\n Numero da Venda=%d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].total,i+1);
            printf("\n-------------------------\n");
            existe++;
        }
    }
    if(existe==0){
        printf("NAO HA ABASTECIMENTOS\n");
        menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }else{
        printf("DIGITA O NUMERO DA VENDA QUE ALMEJA EXCLUIR: ");
        int codExcluir=0;
        scanf("%d",&codExcluir);
        codExcluir--;
        if(codExcluir>=0 && codExcluir<20){
            usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codExcluir].total=0;
            usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codExcluir].litro=0;
            usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[codExcluir].valorLitro=0;
            printf("A VENDA FOI EXCLUIDA COM SUCESSO \n");
            menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        }else{
            printf("OPCAO INVALIDA");
            menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        }
    }

}
//
void listar_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    printf("LISTANDO ABASTECIMENTOS\n");
    int existe=0;
    for (int i=0;i<20;i++){
        if(usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro!=0){
            printf("\n-------------------------\n");
            printf(" ABASTECIMENTO:\n litros=%.2f\n valor=%.2f\n Numero da Venda=%d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].total,i+1);
            printf("\n-------------------------\n");
            existe++;
        }
    }
    if(existe==0){
        printf("NAO HA ABASTECIMENTOS\n");
    }
    printf("\nDIGITE ALGO PARA VOLTAR\n");
    char algo[1];
    scanf("%s",algo);
    if(strcmp(algo,"")!=0){
        system("cls");
        menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
}
//
void adicionar_GC(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    int exec=verificacaoQuantidadeGas(ponteiroValorNumeroUsuario,ponteiroQuantVendasPorTipo);
    if(exec==0){
        system("cls");
        printf("ABASTECIMENTOS CHEIOS");
        menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
    else{
            printf("ADICIONAR ABASTECIMENTOS \n");
            printf("Digite o valor do litro (em reais): ");
            scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].valorLitro);
            printf("\n");
            printf("Escolha um dos dois metodos para inserir os dados:\n");
            printf("\n");
            printf("Digite 1 - - Pela quantidade de Litros\n");
            printf("Digite 2 - - Pelo valor total do abastecimento\n");
            printf("\n");
            int opcaoAbastecimento=0;
            scanf("%d",&opcaoAbastecimento);
            printf("\n");
            switch(opcaoAbastecimento){
            case 1:
                (*pontNumeroVendaGas)++;
                printf("Digite a quantidade de litro(s): ");
                scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].litro);
                usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].total=usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].litro *usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].valorLitro;
                system("cls");
                printf("\n-------------------------\n");
                printf("ABASTECIMENTO:\nlitros= %.2f L\nvalor= RS %.2f\nNumero da Sequencia= %d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].total,*pontNumeroVendaGas);
                printf("\n-------------------------\n");
                (*ponteiroQuantVendasPorTipo)++;
                printf("ABASTECIMENTO CADASTRADO\n");
                menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
            break;
            case 2:
                (*pontNumeroVendaGas)++;
                printf("Digite o valor (em reais): ");
                scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].total);
                usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].litro=usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].total/usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].valorLitro;
                system("cls");
                printf("\n ------------------------\n");
                printf("ABASTECIMENTO:\nlitros= %.2f L\nvalor= RS %.2f\nNumero da Sequencia= %d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[*ponteiroQuantVendasPorTipo].total,*pontNumeroVendaGas);
                printf("\n-------------------------\n");
                (*ponteiroQuantVendasPorTipo)++;
                printf("ABASTECIMENTO CADASTRADO\n");
                menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
            break;
            default:
                system("cls");
                printf("OPCAO INVALIDA");
                menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
            }
    }
}
//
void menuGasolina(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
        printf("------MENU GASOLINA------\n");
        printf("Digite 1 - - ADICIONAR ABASTECIMENTOS    \n");
        printf("Digite 2 - - LISTAR ABASTECIMENTOS  \n");
        printf("Digite 3 - - EXCLUIR ABASTECIMENTOS  \n");
        printf("Digite 4 - - EDITAR ABASTECIMENTOS \n");
        printf("Digite 0 - - VOLTAR \n");
        int codMenuGasolina=0;
        scanf("%d",&codMenuGasolina);
        switch(codMenuGasolina){
        case 1:
            system("cls");
            adicionar_GC(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
        case 2:
            system("cls");
            listar_GC(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
        case 3:
            system("cls");
            excluir_GC(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
        case 4:
            system("cls");
            editar_GC(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
        case 0:
            system("cls");
            menu(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
        default:
            system("cls");   //limpatela
			printf("OPCAO INVALIDO\n");
			menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        }
}
//
//
int verificacaoQuantidadeDiesel(int *ponteiroValorNumeroUsuario,int *ponteiroQuantVendasPorTipo){
     // quero fazer usando uma variavel de soma dentro de for quando a varaivel total for diferente de 0
        int varSomadora=0;
        for(int i=0;i<20;i++){
            if(usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].total !=0){
                    varSomadora++;
            }
        }
        if(varSomadora>=10){
            return 0;
        }else{
            return 1;
        }
}
//
void editar_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaDiesel,int *pontNumeroVendaGas){
    printf("LISTANDO\n");
    int existe=0;
    for (int i=0;i<20;i++){
        if(usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro!=0){
            printf("\n-------------------------\n");
            printf(" ABASTECIMENTO:\n litros=%.2f\n valor=%.2f\n Numero da Venda=%d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].total,i+1);
            printf("\n-------------------------\n");
            existe++;
        }
    }
    if(existe==0){
        printf("NAO HA ABASTECIMENTOS\n");
        menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
    }else{
        printf("DIGITA O NUMERO DA VENDA QUE ALMEJA EDITAR ");
        int codEditar=0;
        scanf("%d",&codEditar);
        codEditar--;
        if(codEditar>=0 && codEditar<20){
            if (usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codEditar].total!=0){
                printf("DIGITA O VALOR DA VENDA :\n");
                scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codEditar].total);
                usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codEditar].litro=usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codEditar].total/usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codEditar].valorLitro;
                printf("A VENDA FOI EDITADA COM SUCESSO \n");
                menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
            }else{
                system("cls");
                printf("OPCAO INVALIDA\n");
                menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
            }
        }else{
            system("cls");
            printf("OPCAO INVALIDA\n");
            menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        }
    }
}
//
void excluir_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaDiesel,int *pontNumeroVendaGas){
     printf("LISTANDO\n");
    int existe=0;
    for (int i=0;i<20;i++){
        if(usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro!=0){
            printf("\n-------------------------\n");
            printf(" ABASTECIMENTO:\n litros=%.2f\n valor=%.2f\n Numero da Venda=%d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].total,i+1);
            printf("\n-------------------------\n");
            existe++;
        }
    }
    if(existe==0){
        printf("NAO HA ABASTECIMENTOS\n");
        menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
    }else{
        printf("DIGITA O NUMERO DA VENDA QUE ALMEJA EXCLUIR: ");
        int codExcluir=0;
        scanf("%d",&codExcluir);
        codExcluir--;
        if(codExcluir>=0 && codExcluir<20){
            usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codExcluir].total=0;
            usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codExcluir].litro=0;
            usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[codExcluir].valorLitro=0;
            printf("A VENDA FOI EXCLUIDA COM SUCESSO \n");
            menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        }else{
            printf("OPCAO INVALIDA");
            menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        }
    }

}
//
void listar_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaDiesel,int *pontNumeroVendaGas){
    printf("LISTANDO ABASTECIMENTOS\n");
    int existe=0;
    for (int i=0;i<20;i++){
        if(usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro!=0){
            printf("\n-------------------------\n");
            printf(" ABASTECIMENTO:\n litros=%.2f\n valor=%.2f\n Numero da Venda=%d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].total,i+1);
            printf("\n-------------------------\n");
            existe++;
        }
    }
    if(existe==0){
        printf("NAO HA ABASTECIMENTOS\n");
    }
    printf("\nDIGITE ALGO PARA VOLTAR\n");
    char algo[1];
    scanf("%s",algo);
    if(strcmp(algo,"")!=0){
            system("cls");
        menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
    }
}
//
void adicionar_D(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaDiesel,int *pontNumeroVendaGas){
    int exec=verificacaoQuantidadeDiesel(ponteiroValorNumeroUsuario,ponteiroQuantVendasPorTipo);
    if(exec==0){
        system("cls");
        printf("ABASTECIMENTOS CHEIOS");
        menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
    }
    else{
            printf("ADICIONAR ABASTECIMENTOS \n");
            printf("Digite o valor do litro (em reais): ");
            scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].valorLitro);
            printf("\n");
            printf("Escolha um dos dois metodos para inserir os dados:\n");
            printf("\n");
            printf("Digite 1 - - Pela quantidade de Litros\n");
            printf("Digite 2 - - Pelo valor total do abastecimento\n");
            printf("\n");
            int opcaoAbastecimento=0;
            scanf("%d",&opcaoAbastecimento);
            printf("\n");
            switch(opcaoAbastecimento){
            case 1:
                (*pontNumeroVendaDiesel)++;
                printf("Digite a quantidade de litro(s): ");
                scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].litro);
                usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].total=usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].litro *usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].valorLitro;
                system("cls");
                printf("\n-------------------------\n");
                printf("ABASTECIMENTO:\nlitros= %.2f L\nvalor= RS %.2f\nNumero da Sequencia= %d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].total,*pontNumeroVendaDiesel);
                printf("\n-------------------------\n");
                (*ponteiroQuantVendasPorTipo)++;
                printf("ABASTECIMENTO CADASTRADO\n");
                menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
            break;
            case 2:
                (*pontNumeroVendaDiesel)++;
                printf("Digite o valor (em reais): ");
                scanf("%f",&usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].total);
                usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].litro=usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].total/usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].valorLitro;
                system("cls");
                printf("\n ------------------------\n");
                printf("ABASTECIMENTO:\nlitros= %.2f L\nvalor= RS %.2f\nNumero da Sequencia= %d\n",usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].litro,usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[*ponteiroQuantVendasPorTipo].total,*pontNumeroVendaDiesel);
                printf("\n-------------------------\n");
                (*ponteiroQuantVendasPorTipo)++;
                printf("ABASTECIMENTO CADASTRADO\n");
                menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
            break;
            default:
                system("cls");
                printf("OPCAO INVALIDA");
                adicionar_D(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
            }
    }
}
//
void menuDiesel(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaDiesel,int *pontNumeroVendaGas){
        printf("------MENU DIESEL------\n");
        printf("Digite 1 - - ADICIONAR ABASTECIMENTOS    \n");
        printf("Digite 2 - - LISTAR ABASTECIMENTOS  \n");
        printf("Digite 3 - - EXCLUIR ABASTECIMENTOS  \n");
        printf("Digite 4 - - EDITAR ABASTECIMENTOS \n");
        printf("Digite 0 - - VOLTAR \n");
        int codMenuDisel=0;
        scanf("%d",&codMenuDisel);
        switch(codMenuDisel){
        case 1:
            system("cls");
            adicionar_D(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        break;
        case 2:
            system("cls");
            listar_D(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        break;
        case 3:
            system("cls");
            excluir_D(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        break;
        case 4:
            system("cls");
            editar_D(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        break;
        case 0:
            system("cls");
            menu(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        break;
        default:
            system("cls");   //limpatela
			printf("OPCAO INVALIDO\n");
			menuDiesel(ponteiroValorNumeroUsuario, valorEntrarSair, valorIdentificaUsuario, ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
        }
}
//
//

void somar_caixa(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    //em reais
    float totalGasolina=0;
    for (int i = 0; i < 20; i++) {
        totalGasolina += usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].total;
    }
    float totalDiesel=0;
    for (int i = 0; i < 20; i++) {
        totalDiesel += usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].total;
    }
    //em litros
    float litrosGasolina=0;
    for (int i = 0; i < 20; i++) {
        litrosGasolina += usuario[*ponteiroValorNumeroUsuario].abastecimentoComum[i].litro;
    }

    float litrosDiesel=0;
    for (int i = 0; i < 20; i++) {
        litrosDiesel += usuario[*ponteiroValorNumeroUsuario].abastecimentoDiesel[i].litro;
    }

    // Imprime o resultado na tela
    printf("SOMANDO CAIXA DO FRENTISTA %s\n", usuario[*ponteiroValorNumeroUsuario].nome);
    printf("\n-------------------------\n");
    printf("Total de vendas de Gasolina Comum(em reais): RS %.2f\n", totalGasolina);
    printf("Total de vendas de Diesel(em reais): RS %.2f\n", totalDiesel);
    printf("\n-------------------------\n");
    printf("Total de vendas de Gasolina Comum(em litros): %.2f L\n", litrosGasolina);
    printf("Total de vendas de Diesel(em litros): %.2f L\n", litrosDiesel);
    printf("\n-------------------------\n");
    float valorTotal=totalDiesel+totalGasolina;
    float litrosTotal=litrosDiesel+litrosGasolina;
    printf("Total de vendas (em reais): RS %.2f\n", valorTotal);
    printf("Total de vendas (em litros): %.2f L\n", litrosTotal);
    printf("\n-------------------------\n");
    //
    printf("\n");
    printf("\nDIGITE ALGO PARA VOLTAR\n");
    char algo[1];
    scanf("%s",algo);
    if(strcmp(algo,"")!=0){
        system("cls");
        menu(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
}
void menu(int valorEntrarSair,int *ponteiroValorNumeroUsuario,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
	int codMenuPrincipal;
	printf("------MENU PRINCIPAL------\n");
	printf("Digite 1 - - GASOLINA COMUM    \n");
	printf("Digite 2 - - DIESEL S-10  \n");
	printf("Digite 3 - - MUDAR FRENTISTA \n");
	printf("Digite 4 - - SOMAR CAIXA DO FRENTISTA\n");
	printf("Digite 5 - - VER A TABELA DA RIFA\n");
	printf("Digite 0 - - PARA SAIR \n");
	scanf("%d",&codMenuPrincipal);
	getchar();
	switch(codMenuPrincipal){
		case 1:
            system("cls");
            menuGasolina(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
		break;
		case 2:
		    system("cls");
		    menuDiesel(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaDiesel,pontNumeroVendaGas);
		break;
		case 3:
            system("cls");   //limpatela
		    mudar_usuario(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
		break;
		case 4:
            system("cls");   //limpatela
            somar_caixa(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
        case 5:
            system("cls");   //limpatela
		    rifa(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        break;
		case 0:
            system("cls");
            entrar_sair(valorEntrarSair);
            return;
		break;
		default:
            system("cls");   //limpatela
			printf("OPCAO INVALIDO\n");
			menu(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        }

}
//
void rifa(int valorEntrarSair,int *ponteiroValorNumeroUsuario,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    printf("CARTELA DE RIFA\n");
    int rifa[5][5];
    int valorRifa=1;
    printf("\n-------------------------------\n");
    for(int i=0;i<5;i++){
        for(int p=0;p<5;p++){
            rifa[i][p]=valorRifa;
            valorRifa++;
        }
    }
    for(int i=0;i<5;i++){
        for(int p=0;p<5;p++){
            printf(" (%d) ",rifa[i][p]);
        }
        printf("\n-------------------------------\n");
    }
    printf("\n \n \n");
    printf("Digite algo para voltar\n");
    char algo[1];
    scanf("%s",algo);
    //condicao de saida
    if(strcmp(algo,"")!=0){
        system("cls");
        menu(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
}
//
void mudar_usuario(int *ponteiroValorNumeroUsuario,int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
    //listando os usuarios
    for(int i=0;i<=1;i++){
        printf("%s - - - numero= %d \n", usuario[i].nome,i+1);
    }
    printf("ESCOLHA O SEU USUARIO\n");
    scanf("%d", ponteiroValorNumeroUsuario);
    getchar();
    (*ponteiroValorNumeroUsuario) --;
    // comparacao de usuario 1 e 2
    if(*ponteiroValorNumeroUsuario==1 || *ponteiroValorNumeroUsuario==0){
        // comparacao de usuario vazio ou nao
        if (usuario[*ponteiroValorNumeroUsuario].nome[0] == '\0'){
            system("cls");
            printf("USUARIO ESCOLHIDO\n");
            cadastro(valorEntrarSair,valorIdentificaUsuario,ponteiroValorNumeroUsuario,ponteiroQuantVendasPorTipo);
        }else{
            system("cls");
            printf("FACA O LOGIN DE ACORDO COM AS CREDENCIAIS CADASTRADAS\n");
            login(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
        }
    }else{
        system("cls");
        printf("USUARIO INVALIDO\n");
        mudar_usuario(ponteiroValorNumeroUsuario,valorEntrarSair,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
}
//
void login(int valorEntrarSair,int *ponteiroValorNumeroUsuario,int valorIdentificaUsuario,int *ponteiroQuantVendasPorTipo,int *pontNumeroVendaGas,int *pontNumeroVendaDiesel){
        printf("LOGIN\n");
	//pedindo
		printf("Digite seu email: ");
		char email_digitado[80];
		scanf("%s",email_digitado);
		getchar();
		printf("Digite sua senha: ");
		char senha_digitado[13];
		scanf("%s",senha_digitado);
		getchar();
    //conferindo
    if (strcmp(email_digitado,usuario[*ponteiroValorNumeroUsuario].email)==0 && (strcmp(senha_digitado,usuario[*ponteiroValorNumeroUsuario].senha))==0){
        strcpy(email_digitado, "");
        strcpy(senha_digitado,"");
        system("cls");
        menu(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }else{
        system("cls");
        printf("CREDENCIAIS INCORRETAS\n");
        strcpy(email_digitado, "");
        strcpy(senha_digitado,"");
        login(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
}
//
int verificacao_email(int *ponteiroValorNumeroUsuario){
    int tamanhoEmail=strlen(usuario[*ponteiroValorNumeroUsuario].email);
    int emailDiferente=0;
    for(int i=0;i<tamanhoEmail;i++){
        if (usuario[*ponteiroValorNumeroUsuario].email[i] =='@' && tamanhoEmail<80 ){
            emailDiferente++;
        }
    }
    int verificacaoComparando=0;
    if (emailDiferente>0){
        for(int i=0;i<=4;i++){
            if(i!=*ponteiroValorNumeroUsuario && (strcmp(usuario[*ponteiroValorNumeroUsuario].email,usuario[i].email))==0){
                    return 0;
            }else{
                verificacaoComparando++;
            }
        }
        if(verificacaoComparando!=0){
            return 1;
        }
    }else{
        return 0;
    }
}
//
void cadastro(int valorEntrarSair,int valorIdentificaUsuario,int *ponteiroValorNumeroUsuario,int *ponteiroQuantVendasPorTipo ){
    //
    int *pontNumeroVendaGas= &usuario[*ponteiroValorNumeroUsuario].numeroVendaGasolina;
    int *pontNumeroVendaDiesel= &usuario[*ponteiroValorNumeroUsuario].numeroVendaDiesel;
    //
    *pontNumeroVendaGas=0;
    *pontNumeroVendaDiesel=0;
    //
    printf("ENTROU NO CADASTRO\n");
    //
    // deixando vazio
    strcpy(usuario[*ponteiroValorNumeroUsuario].nome, "");
    strcpy(usuario[*ponteiroValorNumeroUsuario].email, "");
    strcpy(usuario[*ponteiroValorNumeroUsuario].senha, "");
    //
    // cadastrando
    printf("Digite seu nome: ");
    scanf("%s",usuario[*ponteiroValorNumeroUsuario].nome);
    getchar();
    printf("Digite seu email: ");
    scanf("%s",usuario[*ponteiroValorNumeroUsuario].email);
    getchar();
    printf("Digite sua senha: ");
    scanf("%s",usuario[*ponteiroValorNumeroUsuario].senha);
    getchar();
    //
    // funcao de verificacao de email
    int codVerificacaoEmail= verificacao_email(ponteiroValorNumeroUsuario);
    // volta do valor da funcao e condicoes
    if (codVerificacaoEmail==0){
        system("cls");   //limpatela
        printf("ERRO NO CADASTRO TENTE NOVAMENTE\n");
        printf("Regras para email:\n");
        printf("Conter @\nmax 79caracteres\n");
        printf("Ser diferente dos outros emails\n");
        printf("\n");
        //
        //apagar o que foi salvo nao oficial
        strcpy(usuario[*ponteiroValorNumeroUsuario].nome, "");
        strcpy(usuario[*ponteiroValorNumeroUsuario].email, "");
        strcpy(usuario[*ponteiroValorNumeroUsuario].senha, "");
        //volta para cadastro sem alterar o valorNumeroUsuario
        cadastro(valorEntrarSair,valorIdentificaUsuario,ponteiroValorNumeroUsuario,ponteiroQuantVendasPorTipo);
    }else{
        // indo para login
        system("cls");
        login(valorEntrarSair,ponteiroValorNumeroUsuario,valorIdentificaUsuario,ponteiroQuantVendasPorTipo,pontNumeroVendaGas,pontNumeroVendaDiesel);
    }
}
//
void limpandoUsuarios(){
    for(int i=0;i<2;i++){
        strcpy(usuario[i].email,"");
        strcpy(usuario[i].nome,"");
        strcpy(usuario[i].senha,"");
        usuario[i].numeroVendaGasolina = 0;
        usuario[i].numeroVendaDiesel = 0;
        for(int p=0;p<20;p++){
            usuario[i].abastecimentoComum[p].total=0;
        }
        for(int p=0;p<20;p++){
            usuario[i].abastecimentoDiesel[p].total=0;
        }
    }
}
//
void entrar_sair(int valorEntrarSair){
    valorEntrarSair--;
    int valorIdentificaUsuario=0;
    int *ponteiroValorNumeroUsuario= &valorIdentificaUsuario;
    int quantidadeVendasPorTipo=0;
    int *ponteiroQuantVendasPorTipo= &quantidadeVendasPorTipo;
    if(valorEntrarSair>0){
            printf("----------------------\n");
            printf("---- BEM VINDO(A) ----\n");
            printf("--- SYSTEM-GAS&OIL ---\n");
            printf("----------------------\n");
            printf("Digite 1 - - Entrar \n");
            printf("Digite 0 - - Sair \n");
            scanf("%d",&valorEntrarSair);
            getchar();
            switch(valorEntrarSair){
                case 0:
                    system("cls");
                break;
                case 1:
                    valorEntrarSair=1;
                    limpandoUsuarios();
                    system("cls");   //limpatela
                    cadastro(valorEntrarSair,valorIdentificaUsuario,ponteiroValorNumeroUsuario,ponteiroQuantVendasPorTipo);
                break;
                default:
                    system("cls");
                    printf("OPCAO INVALIDA\n");
                    entrar_sair(valorEntrarSair);
            }
        }
    else{
    printf("FINALIZANDO O PROGRAMA\n");
    }
}
//
int main(){
    int valorEntrarSair=2; //opcao para sair
    entrar_sair(valorEntrarSair);
    return 0;
}


