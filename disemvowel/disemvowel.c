#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

static int is_vowel(char c) {
  switch (c) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
      return 1;
    default:
      return 0;
  }
}


char* disemvowel(char* str) {
	if (str == NULL) {
		return NULL;
	}

	int length = strlen(str);
	char* newstring = (char*)malloc(length + 1);
	if (newstring == NULL) {
		return NULL;
	}

	int index = 0;
	for (int i = 0; i < length; i++) {
		if (!is_vowel(str[i])) {
			newstring[index] = str[i];
			index++;
		}
	}

	newstring[index] = '\0';

	char* final = (char*)realloc(newstring, index + 1);

	if (final == NULL) {
		free(newstring);
		return NULL;
	}
  return final;
}
