#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroGerado;
    int tentativa;
    int tentativas = 10;
    char jogarNovamente;
    int opcao;

    srand(time(NULL));

    do {
        printf("\n=== MENU DO JOGO ===\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            printf("\nAte logo!\n");
            break;
        } else if (opcao != 1) {
            printf("\nOpcao invalida! Tente novamente.\n");
            continue;
        }

        tentativas = 10; 
        numeroGerado = rand() % 9000 + 1000; 
        int codigo[4] = {
            numeroGerado / 1000,
            (numeroGerado / 100) % 10,
            (numeroGerado / 10) % 10,
            numeroGerado % 10
        };

        int descobertos[4] = {-1, -1, -1, -1}; 

        printf("\n=== JOGO DE DESCOBERTA DE CÓDIGO ===\n");

        while (tentativas > 0) {
            printf("\nDigite sua tentativa de código: ");
            scanf("%d", &tentativa);

            if (tentativa < 1000 || tentativa > 9999) {
                printf("O numero deve ter EXATAMENTE 4 digitos! Tente novamente.\n");
                continue;
            }

            int tent[4] = {
                tentativa / 1000,
                (tentativa / 100) % 10,
                (tentativa / 10) % 10,
                tentativa % 10
            };

            int acertos = 0;

            for (int i = 0; i < 4; i++) {
                if (tent[i] == codigo[i]) {
                    descobertos[i] = tent[i];
                    acertos++;
                }
            }

            if (acertos == 0) {
                printf("\nVoce nao acertou nenhum digito dessa vez...\n");
            } else {
                printf("\nVoce acertou %d digito(s) dessa vez...\n", acertos);
            }

            tentativas--;
            printf("Faltam %d tentativa(s)....\n", tentativas);

            printf("Seu código é: ");
            for (int i = 0; i < 4; i++) {
                if (descobertos[i] != -1) {
                    printf("%d ", descobertos[i]);
                } else {
                    printf("_ ");
                }
            }
            printf("\n\n<<< Tecle Algo >>>\n");

            if (descobertos[0] != -1 && descobertos[1] != -1 && descobertos[2] != -1 && descobertos[3] != -1) {
                printf("\nPARABÉNS! Você descobriu o código: %d\n", numeroGerado);
                break;
            }

            if (tentativas == 5 || tentativas == 3) {
                printf("\nVocê ainda precisa acertar %d dígitos\n", 4 - acertos);
                printf("Vou te dar uma dica!!!!\n");
                printf("==> O Segundo Dígito (dezena) é %s!!!\n", codigo[1] % 2 == 0 ? "PAR" : "ÍMPAR");
                printf("==> ");
                for (int i = 0; i < 4; i++) {
                    if (i == 1)
                        printf("%s ", codigo[1] % 2 == 0 ? "PAR" : "ÍMPAR");
                    else if (descobertos[i] != -1)
                        printf("%d ", descobertos[i]);
                    else
                        printf("_ ");
                }
                printf("\n");
            }
        }

        if (tentativas == 0 && (
            descobertos[0] == -1 ||
            descobertos[1] == -1 ||
            descobertos[2] == -1 ||
            descobertos[3] == -1
        )) {
            printf("\nGAME OVER! O código era: %d\n", numeroGerado);
        }

        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nObrigado por jogar!\n");
    return 0;
}
