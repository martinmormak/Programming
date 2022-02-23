#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "playfair.h"

int main(){
    char *encrypted;
    encrypted = playfair_encrypt(/*"bermudas"*/" !", "ethyl");
    printf("%s", encrypted);
    printf("\n");
    char *decrypted;
    decrypted = playfair_decrypt("Tej to nebolo po voli", "MH CB VF KX SG EN IB VT VE XS FJ TJ TB MI JT BG TG QH UN BU DS GS CH PB CB FE IM JC OS RJ LR FX TU EJ TJ VT CE QN LB PU");
    printf("%s", decrypted);
    printf("\n");
    char* reversed = reverse("NULL"/*"Hello world!"*/);
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
