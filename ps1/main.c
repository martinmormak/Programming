#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "playfair.h"

int main(){
    char *encrypted;
    //encrypted = playfair_encrypt("dote", "optometry");
    encrypted = playfair_encrypt("frogs", "Kto sa skorej wrati nech wytiahne noz z bratowho mena a ked wyjde krw moze wediet ze mu je brat ziwy ale ak potecie woda istotne je mrtwy ");
    printf("%s", encrypted);
    printf("\n");
    char *decrypted;
    decrypted = playfair_decrypt("dote", encrypted);
    printf("%s", decrypted);
    printf("\n");
    char* reversed = reverse("NULL"/*"Hello world!"*/);
    printf("%s", reversed);
    printf("\n");
    encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
    printf("%s\n", encrypted);
    decrypted = vigenere_decrypt("CoMPuTeR", encrypted);
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
