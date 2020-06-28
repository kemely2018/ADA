/* CODIGO: https://www.programsnake.com/c/character-count.html*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int characters, words, lines;


    file = fopen("datos.txt", "r");


    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }


    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        if (ch == '\n' || ch == '\0')
            lines++;

        if (ch == ' ' || ch == '\t' || ch == '\0')
            words++;
    }


    if (characters > 0)
    {
        words++;
        lines++;
    }

    printf("\n");
    printf("Total numeros      = %d\n", words-1);
    printf("Total filas      = %d\n", lines-1);

    fclose(file);

    return 0;
}
