#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "playfair.h"

int main(){
    char *encrypted;
    //encrypted = playfair_encrypt("dote", "optometry");
    encrypted = playfair_encrypt("Ked ti zima pod sa zohriat zavola ten zdola", "A mladenec mu rozpovedal ze je to taka a taka zakliata hora a kto sa raz do nej dostane ten stadial nevyjde viacej");
    printf("%s", encrypted);
    printf("\n");
    char *decrypted;
    decrypted = playfair_decrypt("Ked ti zima pod sa zohriat zavola ten zdola", encrypted);
    printf("%s", decrypted);
    printf("\n");
    free(decrypted);
    free(encrypted);
    char* reversed = reverse("NULL"/*"Hello world!"*/);
    printf("%s", reversed);
    printf("\n");
    free(reversed);
    char* encrypted2;
    encrypted2 = vigenere_encrypt("CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR CoMPuTeR", "Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world!");
    printf("%s\n", encrypted2);
    char* decrypted2;
    decrypted2 = vigenere_decrypt("CoMPuTeR", encrypted2);
    printf("%s\n", decrypted2);
    free(encrypted2);
    free(decrypted2);
    unsigned char* encrypted3;
    encrypted3= bit_encrypt("Hello world!");
    for(int i=0; i < 12;i++) {
        printf("%x ", encrypted3[i]);
    }
    printf("\n");
    char* decrypted3;
    decrypted3 = bit_decrypt(encrypted3);
    printf("%s",decrypted3);
    printf("\n");
    free(encrypted3);
    free(decrypted3);
    unsigned char* encrypted4;
    encrypted4 = bmp_encrypt("CoMPuTeRCOMPUTERCOMPUTERCOMPUTERCOMPUTERCOMPUTERCOMPUTER", "Hello world!");
    for(int i=0; i < 12;i++) {
        printf("%x ", encrypted4[i]);
    }
    printf("\n");
    char* decrypted4;
    decrypted4 = bmp_decrypt("CoMPuTeR", encrypted4);
    printf("%s\n", decrypted4);
    free(encrypted4);
    free(decrypted4);
}
