#include <stdlib.h>
#include <stdio.h>

int main()
{
    float nota[4], soma_notas, media_aritmetica;
    char aluno[50];
    int continuar;
    FILE *arquivo;

    do
    {
        system("cls");

        printf("=============================\n");
        printf("      BOLETIM ESCOLAR        \n");
        printf("=============================\n");

        printf("Nome do aluno: ");
        scanf("%s", &aluno);

        system("cls");

        printf("=============================\n");
        printf("   BOLETIM ESCOLAR - NOTAS   \n");
        printf("=============================\n");

        for (int i = 0; i < 4; i++)
        {
            printf("Nota nº %d: \n", i + 1);
            scanf("%f", &nota[i]);
        }

        system("cls");

        printf("=============================\n");
        printf("      BOLETIM ESCOLAR        \n");
        printf("=============================\n");

        arquivo = fopen("boletins.txt", "a");

        if (arquivo == NULL)
        {
            printf("\nO arquivo não foi aberto corretamente");
        }
        else

        printf("Aluno: %s\n\n", aluno);

            fprintf(arquivo, "Aluno: %s\n", aluno);

        soma_notas = 0;

        for (int i = 0; i < 4; i++)
        {
            printf("Nota nº %d: %.1f\n", i + 1, nota[i]);

                fprintf(arquivo, "Nota nº %d: %.1f\n", i + 1, nota[i]);

            soma_notas = nota[i] + soma_notas;
        }

        media_aritmetica = 0;

        media_aritmetica = (soma_notas / 4);

        printf("-----------------------------\n");
        printf("Média final: %.1f\n", media_aritmetica);

            fprintf(arquivo, "Média final: %.1f\nSituação: ", media_aritmetica);

        printf("Situação: ");

        if (media_aritmetica >= 7)
        {
            printf("Aprovado");
                fprintf(arquivo, "Aprovado\n\n");
        }
        else if (media_aritmetica >= 5)
        {
            printf("Recuperação");
                fprintf(arquivo, "Recuperação\n\n");
        }
        else if (media_aritmetica < 5)
        {
            printf("Reprovado");
                fprintf(arquivo, "Reprovado\n\n");
        }
       
        fclose(arquivo);

        printf("\n-----------------------------\n");
        printf("\nSelecione:\n");
        printf("(1) - Cadastrar outro aluno\n");
        printf("(0) - Sair\n");

        scanf("%d", &continuar);

    } while (continuar != 0);
}