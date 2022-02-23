#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "playfair.h"

int main(){
    char *encrypted;
    encrypted = playfair_encrypt("bermudas", "ethyl");
    printf("%s", encrypted);
    printf("\n");
    char *decrypted;
    decrypted = playfair_decrypt("justifying", "EM IJ GA RC");
    printf("%s", decrypted);
    printf("\n");
    char* reversed = reverse("Hello world!");
    printf("%s", reversed);
    printf("\n");
    encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
    printf("%s\n", encrypted);
    decrypted = vigenere_decrypt("CoMPuTeR", "JSXAI PSINR!");
    printf("%s\n", decrypted);
    unsigned char* encrypted2;
    encrypted2 = bit_encrypt("Hello world!");
    for(int i=0; i < 12;i++) {
        printf("%x ", encrypted2[i]);
    }
    printf("\n");
    decrypted = bit_decrypt(encrypted2);
    printf("%s",decrypted);
    printf("\n");
    encrypted2 = bmp_encrypt("CoMPuTeR", "Hello world!");
    for(int i=0; i < 12;i++) {
        printf("%x ", encrypted2[i]);
    }
    printf("\n");
    decrypted = bmp_decrypt("CoMPuTeR", encrypted2);
    printf("%s\n", decrypted);
    //free(encrypted);
    //free(encrypted2);
    //free(decrypted);
    //free(reversed);
}
