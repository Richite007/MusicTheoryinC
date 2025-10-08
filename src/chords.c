#include <stdio.h>
#include "src/chords.h"

void Chord_maj(char key[]) {
    printf("%c-Maj Chord is : ", key[0]);
    for (int i = 0; i <= 5; i += 2) {
        printf("%c\t", key[i]);
    }
}

void Chord_min(char key[]) {
    printf("%c-Min Chord is : ", key[0]);
    for (int i = 0; i <= 5; i += 2) {
        if (i == 2) {
            printf("%cb\t", key[i]);
            continue;
        }
        printf("%c\t", key[i]);
    }
}

int modeOfKey(const char *NotesDiatonic, const char rootNoteInput) {
    int counter = 0;
    for (int i = 0; i < 7; i++) {
        if (NotesDiatonic[i] == rootNoteInput) {
            counter = i;
        }
    }
    return counter;
}