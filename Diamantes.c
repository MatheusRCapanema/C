#include <stdio.h>
#include <string.h>

typedef unsigned int ui;

ui dima(char *);

void main ()
{

    ui n;
    int pontos;
    char string[1005];

    scanf("%hu", &n);
    scanf("%d", &pontos);

    while (n--)
    {

        fgets(string, 1005, stdin);
        string[strlen(string) - 1] = '\0';
        printf("%hu\n", dima(string));
        memset(string, 0, sizeof(string));

    }
}

ui dima(char *string)
{

    short x = 0;
    ui QDima = 0;

    ui i, j;
    for (i = 0; string[i]; ++i)
    {

        if (string[i] != '<')
            continue;

        for (j = i + 1; string[j]; ++j)
            if (string[j] == '>')
            {

                ++QDima;
                string[i] = 'x';
                string[j] = 'x';
                break;

            }

    }

    return QDima;

}
