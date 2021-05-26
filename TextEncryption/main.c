#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "decoder.h"

int main() {
    FILE *input, *output;
    char desktopPath[100];
    char *userName = getenv("USERNAME");
    strcpy(desktopPath, "C:/Users/");
    strcat(desktopPath, userName);
    strcat(desktopPath, "/Desktop");
    strcat(desktopPath, "/output.txt");

    char key[100];
    char fileName[100];
    char secim;
    printf("Dosya konumunu belirtmek icin txt dosyasini surukleyin:\n");
    gets(fileName);

    if (fileName[0] == '\"' || fileName[0] == '\'') {
        int i;
        for (i = 0; i < sizeof(fileName); i++) {
            fileName[i] = fileName[i + 1];
            if (fileName[i] == '\"' || fileName[0] == '\'') {
                fileName[i] = '\0';
            }
        }
    }

    printf("Anahtar Giriniz:\n");
    scanf("%s", key);

    input = fopen(fileName, "r");
    output = fopen(desktopPath, "w");

    if (input == NULL) {
        printf("Dosya bulunamadi\n");
        return 1;
    }

    size_t pos = ftell(input);
    fseek(input, 0, SEEK_END);    // Go to end
    size_t length = ftell(input); // read the position which is the size
    fseek(input, pos, SEEK_SET);

    char plain[length];

    fgets(plain, length, input);
    getchar();
    int check = 0;

    do {
        printf("1)Encrypt\n2)Decoder\n3)Cikis\n");
        scanf("%c", &secim);

        if (secim == '1') {
            encrypt(plain, key);
            fprintf(output, "%s", plain);
            printf("Dosya Masaustunuzde Sifrelendi\n");

        } else if (secim == '2') {
            decoder(plain, key);
            fprintf(output, "%s", plain);
            printf("Dosyanizin Sifresi Kirildi\n");

        } else if (secim == '3') {
            printf("Cikis Yapildi");
            break;

        } else {
            printf("Hatali Girdi");
            check = 1;
        }
    } while (check == 1);


    fclose(input);
    fclose(output);

    return 0;
}


