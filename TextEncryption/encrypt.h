
#ifndef UNTITLED1_ENCRYPT__H

#define UNTITLED1_ENCRYPT__H
#endif //UNTITLED1_ENCRYPT__H

int toAlphabet(char c) {
    if (c >= 'A' && c <= 'Z')return (c % 'A') + 1;
    if (c >= 'a' && c <= 'z') return (c % 'a') + 1;
    return 0;
}

int is_small(char c) {
    return c <= 'z' && c >= 'a';
}

void e_for_small_letters(char *c) {

    if (*c > 'z' && *c <= 127) {
        *c -= 26;
    }
    if (*c >= -128 && *c <= 64) {
        *c += 128 + 102; // +128 --> 0'a tamamlamak için
        // +102 --> küçük harflere tamamlamak için
    }
}

void e_for_capital_letters(char *c) {
    if (*c > 'Z')
        *c -= 26;
}

void encrypt(char *plain, char *key) {
    int i = 0, j = 0;
    while (plain[i] != '\0') {
        char temp = plain[i];

        plain[i] += toAlphabet(key[j]);

        if (is_small(temp)) {
            e_for_small_letters((plain + i));
            //printf("**%d\n\n\n", plain[i]);
        } else {
            e_for_capital_letters(&plain[i]);
        }

        i++;
        j++;

        if (key[j] == '\0')
            j = 0;
    }

}

