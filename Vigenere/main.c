#include<stdio.h>
#include<string.h>

int main(){
    char message[] = "ANAAREMERE";
    char key[] = "DICU";

    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    char newKey[messageLen], encryptedMessage[messageLen], decryptedMessage[messageLen];

    //generating new key
    for(i = 0, j = 0; i < messageLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encryption
    for(i = 0; i < messageLen; ++i)
        encryptedMessage[i] = ((message[i] + newKey[i]) % 26) + 'A';

    encryptedMessage[i] = '\0';

    //decryption
    for(i = 0; i < messageLen; ++i)
        decryptedMessage[i] = (((encryptedMessage[i] - newKey[i]) + 26) % 26) + 'A';

    decryptedMessage[i] = '\0';

    printf("Original Message: %s", message);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMessage);
    printf("\nDecrypted Message: %s", decryptedMessage);

    return 0;
}

