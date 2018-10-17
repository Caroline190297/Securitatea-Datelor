#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char a[] = {'A'};
    int len = strlen(a);
    int i = 0;
    encriptionCaesar(a, - 3);
    for(i = 0; i < len-1; i++){
        printf("%c", a[i]);
    }
    return 0;
}
