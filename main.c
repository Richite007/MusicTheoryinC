#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Chord_maj();
void Chord_min();
int modeOfKey();

const char MUSICNOTES[] = "CDEFGAB";

int main(int argc, char* argv[]) {

	char rootNoteInput; // Key you want to know values.
	int rootNumber;		// interval number.
	char relativeMusicNotes[] = "CDEFGAB"; // We are rearranging this.

	//Get Input 
	printf("Please, enter the root note:");
	scanf_s(" %c", &rootNoteInput);

	//Compute the interval from the MUSICNOTE[0] 
	rootNumber = modeOfKey(MUSICNOTES, rootNoteInput);
	// test of rootNumber from a viewer perspective
	printf("(Note, Position) = (%c, %d):\n\n", MUSICNOTES[rootNumber], rootNumber);

	//RIGHT PART
	for (int i = 0; i < ((sizeof(MUSICNOTES)-1) - rootNumber); i++)
	{
		relativeMusicNotes[i] = MUSICNOTES[i + rootNumber];
		printf("%c", relativeMusicNotes[i]);
	}

	//LEFT PART
	int k = ((sizeof(MUSICNOTES) - 1) - (rootNumber));
	for (int i = 0; i < rootNumber; i++)
	{
		relativeMusicNotes[k + i] = MUSICNOTES[i];
	}
	
	printf("\n(Original, key, RelativeKey, sizeof(MUSICNOTES)) = (%s, %c, %s, %d)\n\n", MUSICNOTES, MUSICNOTES[rootNumber], relativeMusicNotes, k);
	Chord_maj(relativeMusicNotes);
	return 0;
}

void Chord_maj(char key[])
{
	printf("%cmaj Chord is : ", key[0]);
	for (int i = 0; i <= 5; i += 2)
	{
		printf("%c\t", key[i]);
	}
}

void Chord_min(char key[])
{
	printf("%cmin Chord is : ", key[0]);
	for (int i = 0; i <= 5; i += 2)
	{
		if (i == 2)
		{
			printf("%cb\t", key[i]);
			continue;
		}
		printf("%c\t", key[i]);
	}
}

int modeOfKey(char NotesDiatonic[], char rootNoteInput) {
	for (int i = 0; i < 7; i++)
	{
		if (NotesDiatonic[i] == rootNoteInput) {
			return i;
		}
	}

}
