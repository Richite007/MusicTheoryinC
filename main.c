#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/chords.h"


const char MUSICNOTES[] = "CDEFGAB";

int main(int argc, char *argv[]) {
    char rootNoteInput; // Key you want to know values.
    // interval number.
    char relativeMusicNotes[] = "CDEFGAB"; // We are rearranging this.

    //Get Input
    printf("Please, enter the root note:");
    scanf_s(" %c", &rootNoteInput);

    //Compute the interval from the MUSIC-NOTE[0]
    const int rootNumber = modeOfKey(MUSICNOTES, rootNoteInput);
    // test of rootNumber from a viewer perspective
    printf("(Note, Position) = (%c, %d):\n\n", MUSICNOTES[rootNumber], rootNumber);

    //RIGHT PART
    for (int i = 0; i < ((sizeof(MUSICNOTES) - 1) - rootNumber); i++) {
        relativeMusicNotes[i] = MUSICNOTES[i + rootNumber];
        printf("%c", relativeMusicNotes[i]);
    }

    //LEFT PART
    const int k = (((int) sizeof(MUSICNOTES) - 1) - (rootNumber));
    for (int i = 0; i < rootNumber; i++) {
        relativeMusicNotes[k + i] = MUSICNOTES[i];
    }

    printf("\n(Original, key, RelativeKey, sizeof(MUSICNOTES)) = (%s, %c, %s, %d)\n\n", MUSICNOTES,
           MUSICNOTES[rootNumber], relativeMusicNotes, k);
    Chord_maj(relativeMusicNotes);
    return 0;
}
