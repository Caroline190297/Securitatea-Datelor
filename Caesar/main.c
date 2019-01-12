#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void decriptionCaesar (char message[], int key)
{
    int i = 0;
    int len = 0;
    while (message[i] != 0x00){
        len++;
        i++;
    }
    for (i = 0; i < len - 1; i++){
        char aux = message[i];
        if(aux >= 'A' && aux <= 'Z'){
            aux = aux - key;
            if(aux > 'Z'){
                aux = aux - 'Z' + 'A' - 1;
            }
            if(aux < 'A'){
                aux = 'Z' - ('A' - aux ) + 1;
            }
        }
        message[i] = aux;
    }
}

void encriptionCaesar (char message[], int key)
{
    int i = 0;
    int len = 0;
    while (message[i] != 0x00){
        len++;
        i++;
    }
    for (i = 0; i < len - 1; i++){
        char aux = message[i];
        if(aux >= 'A' && aux <= 'Z'){
            aux = aux + key;
            if(aux > 'Z'){
                aux = aux - 'Z' + 'A' - 1;
            }
            if(aux < 'A'){
                aux = 'Z' - ('A' - aux ) + 1;
            }
        }
        message[i] = aux;
    }
}

int main()
{
    char a[] = {'D'};
    char b[] = {'A'};
    int len = strlen(a);
    int len1= strlen(b);
    int i = 0;
    encriptionCaesar(a, - 3);
    for(i = 0; i < len-1; i++){
        printf("%c\n", a[i]);
    }

    decriptionCaesar(b, - 3);
    for(i = 0; i < len1-1; i++){
        printf("%c\n", b[i]);
    }
    return 0;
}
