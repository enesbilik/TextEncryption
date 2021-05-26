
#ifndef UNTITLED1_DECODER_H
#define UNTITLED1_DECODER_H
#endif //UNTITLED1_DECODER_H

// MoXtsN -> enes -> HaSanN


void d_for_small_letters(char *c) {
    int dif = 'a' - *c - 1;
    if (dif >= 0 && *c > 38) {
        *c = 'z' - dif;
    }
}

void d_for_capital_letters(char *c) {
    int dif = 'A' - *c - 1;

    if (dif > 0 && *c > 38 ) {
        *c = 'Z' - dif;
    }
}

void decoder(char *plain, char *key) {
    int i = 0, j = 0;
    while (plain[i] != '\0') {
        char temp = plain[i];

        plain[i] -= toAlphabet(key[j]);

        if (is_small(temp)) {
            d_for_small_letters((plain + i));
            //printf("**%d\n\n\n", plain[i]);
        } else {
            d_for_capital_letters(&plain[i]);
        }

        i++;
        j++;

        if (key[j] == '\0')
            j = 0;
    }

}

