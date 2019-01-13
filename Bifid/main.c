#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 255

//You can find any info here: https://en.wikipedia.org/wiki/Bifid_cipher

//ATTENTION: the table must be NxN (ex: 5x5, like in this case, not 5x6 or smth)

//Alpha Bifid_cipher written in C. Code not clean and too long.

/* TABLE
    0 1 2 3 4    Row(x)
  0 A B C D E
  1 F G H I K
  2 L M N O P
  3 Q R S T U
  4 V W X Y Z
  Col(y)
*/

struct position{
    int row;
    int column;
};

char* reverseSearchOnTable(char** table, char* sentence, struct position *pos, int table_len, int method){ //Find every 'translated' letter through positions
    int i, x, y, w=0, spaces=0, real_len, s_len = strlen(sentence);
    //char space_pos[32][16];
    char* new_sen = malloc(sizeof(char)*s_len);
    struct position *decr_pos;

    for(i=0; i<s_len; i++){
        if(sentence[i] == ' ')
            ++spaces;
    }

    /*for(y=0; y<spaces; y++){
        for(i=w; i<s_len; i++){
            if(sentence[i] == ' '){
                itoa(i,space_pos[y],10);
                w = i+1;
                break;
            }
        }
    }*/

    real_len = s_len - spaces; //REAL LENGTH - without spaces (not implemented yet)

    decr_pos = malloc(sizeof(struct position)*real_len);
        memcpy(decr_pos, pos, sizeof(struct position)*real_len); //make a copy of struct position array (with every word position)

    if(method == 1) //decipher
    {
        if(real_len % 2 == 0){
            for(x=0, w=0; x<(real_len/2); x++, w+=2){
                decr_pos[w].row = pos[x].row;
                decr_pos[w+1].row = pos[x].column;
            }

            for(y=x, w=0; y<(x+(real_len/2)); y++, w+=2){
                decr_pos[w].column = pos[y].row;
                decr_pos[w+1].column = pos[y].column;
            }

            for(x=0; x<real_len; x++)
                printf("%i%i ", decr_pos[x].row, decr_pos[x].column);
        }
        else{
            for(x=0, w=0; x<(real_len/2); x++, w+=2){
                decr_pos[w].row = pos[x].row;
                decr_pos[w+1].row = pos[x].column;
            }

            decr_pos[w].row = pos[x].row;
            decr_pos[0].column = pos[x].column;

            for(y=x+1, w=1; y<(x+1+(real_len/2)); y++, w+=2){
                decr_pos[w].column = pos[y].row;
                decr_pos[w+1].column = pos[y].column;
            }

            for(x=0; x<real_len; x++)
                printf("%i%i ", decr_pos[x].row, decr_pos[x].column);
        }

        for(x=0, w=0; x<s_len; x++,w++){
            /*for(i=0; i<spaces; i++){
                if(atoi(space_pos[i]) == x){
                    new_sen[x] = ' ';
                    ++x;
                }
            }*/
            new_sen[x] = table[decr_pos[w].row][decr_pos[w].column];
        }

        new_sen[x] = '\0';

        return new_sen;
    }

    if(real_len % 2 == 0){ //cipher
        for(x=0, w=0; x<(real_len/2); x++,w+=2){
            /*for(i=0; i<spaces; i++){
                if(atoi(space_pos[i]) == x){
                    new_sen[x] = ' ';
                    ++x;
                }
            }*/
            new_sen[x] = table[decr_pos[w].row][decr_pos[w+1].row];
            printf("%i%i ", decr_pos[w].row, decr_pos[w+1].row);
        }

        for(y=x, w=0; y<(x+(real_len/2)); y++, w+=2){
            /*for(i=0; i<spaces; i++){
                if(atoi(space_pos[i]) == y){
                    new_sen[y] = ' ';
                    ++y;
                }
            }*/
            new_sen[y] = table[decr_pos[w].column][decr_pos[w+1].column];
            printf("%i%i ", decr_pos[w].column, decr_pos[w+1].column);
        }
    }
    else
    {
        for(x=0, w=0; x<(real_len/2); x++,w+=2){
            /*for(i=0; i<spaces; i++){
                if(atoi(space_pos[i]) == x){
                    new_sen[x] = ' ';
                    ++x;
                }
            }*/
            new_sen[x] = table[decr_pos[w].row][decr_pos[w+1].row];
            printf("%i%i ", decr_pos[w].row, decr_pos[w+1].row);
        }

        new_sen[x] = table[decr_pos[w].row][decr_pos[0].column];
        printf("%i%i ", decr_pos[w].row, decr_pos[0].column);


        for(y=x+1, w=1; y<(x+1+(real_len/2)); y++, w+=2){
            /*for(i=0; i<spaces; i++){
                if(atoi(space_pos[i]) == y){
                    new_sen[y] = ' ';
                    ++y;
                }
            }*/
            new_sen[y] = table[decr_pos[w].column][decr_pos[w+1].column];
            printf("%i%i ", decr_pos[w].column, decr_pos[w+1].column);
        }
    }

    new_sen[y] = '\0'; //add terminator at the end of the sentence (to avoid memory problems)

    return new_sen;
}

struct position *searchOnTable(char** table, char* sentence, int table_len){ //Search on the table every letters
    struct position * pos;
    int i, x, y, w=0, spaces=0, real_len, s_len = strlen(sentence);

    for(i=0; i<s_len; i++){
        if(sentence[i] == ' ')
            ++spaces;
    }

    real_len = s_len - spaces;
    pos = malloc(sizeof(struct position)*real_len);

    for(i=0, w=0; i<s_len; i++){
        for(x=0; x<table_len; x++){
            for(y=0; y<table_len; y++){
                if(sentence[i] == ' '){
                    ++w;
                    ++i;
                }
                if(sentence[i] == table[x][y]){
                    pos[i-w].row = x;
                    pos[i-w].column = y;
                    printf("%i%i ", pos[i-w].row, pos[i-w].column);
                }

            }
        }
    }

    return pos;
}

int main(void) {
    char **table;
    char sentence[MAX_VALUE];
    char answ;
    struct position *posXY;
    char* de_crypt_sen;
    int i, table_len, method = 0;

    printf("------------- Bifid Cipher/Decipher v1.0 -------------\n\n");
    printf("Do you want to use default table? (y/n): ");
    scanf(" %c", &answ);
    printf("\n");

    if(answ == 'n'){ //make a table
        printf("Size of table (ex: 5 for 5x5): ");
        scanf("%i", &table_len);
        printf("\n");

        table = malloc(table_len * sizeof(char*));
        for (i = 0; i < table_len; i++)
            table[i] = malloc((table_len+1) * sizeof(char));

	    printf("Write your table:\n\n");
	    for(i=0; i<table_len; i++)
	        scanf("%s", table[i]);

	     /*example TABLE
            (5x5)
            abcde
            fghik
            lmnop
            qrstu
            vwxyz
            (6x6)
            abcdef
            ghijkl
            mnopqr
            stuvwx
            yz1234
            567890
            (7x7)
            ...
        */
        printf("\n");
    }
    else if(answ == 'y') //default table
    {
        table_len = 5;
        table = malloc(table_len * sizeof(char*));
        for (i = 0; i < table_len; i++)
            table[i] = malloc((table_len+1) * sizeof(char));

        table[0] = "abcde";
        table[1] = "fghik";
        table[2] = "lmnop";
        table[3] = "qrstu";
        table[4] = "vwxyz";
    }
    else
    {
        printf("Invalid operation\n");
        exit(0);
    }

    printf("Do you want to cipher (0) or decipher (1)? : ");
    scanf("%i", &method);
    printf("\n");

    if(method == 0){ //cipher
        printf("Write the sentence: ");
        scanf(" %[^\n]s", sentence);
        printf("\n");

        /* CRYPTING... word: how are you
            h  o  w   a  r  e   y  o  u
            12 23 41  00 31 04  43 23 34
                            h o w  a r e  y o u
            Row(x)          1 2 4  0 3 0  4 2 3
            Column(y)       2 3 1  0 1 4  3 3 4
            12 40 30  42 32 31  01 43 34
            h  v  q   x  s  r   b  y  u
        */

        posXY = searchOnTable(table, sentence, table_len);

        printf("\n");

        de_crypt_sen = reverseSearchOnTable(table, sentence, posXY, table_len, method);

        printf("\n\nCiphered sentence: %s\n", de_crypt_sen);

        if(answ == 'n')
            printf("\nREMEMBER: Copy your table, otherwise you can't decipher the sentence.\n");

        printf("\n");

        system("PAUSE");
    }
    else if(method == 1){ //decipher
        printf("Write the sentence: ");
        scanf(" %[^\n]s", sentence);
        printf("\n");

        /* DECRYPTING... word: hvq xsr byu
            h  v  q   x  s  r   b  y  u
            12 40 30  42 32 31  01 43 34
                            h v q  x s r  b y u
            Row(x)          1 4 3  4 3 3  0 4 3
            Column(y)       2 0 0  2 2 1  1 3 4
                            h o w  a r e  y o u
            Row(x)          1 2 4  0 3 0  4 2 3
            Column(y)       2 3 1  0 1 4  3 3 4
            12 23 41  00 31 04  43 23 34
            h  o  w   a  r  e   y  o  u
        */
        posXY = searchOnTable(table, sentence, table_len);

        printf("\n");

        de_crypt_sen = reverseSearchOnTable(table, sentence, posXY, table_len, method);

        printf("\n\nDeciphered sentence: %s\n", de_crypt_sen);

        printf("\n");

        system("PAUSE");
    }
    else
    {
        printf("Invalid operation\n");
        exit(0);
    }

	return 0;
}
