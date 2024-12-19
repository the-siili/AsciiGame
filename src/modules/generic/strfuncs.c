#include "strfuncs.h"


void addChar(char *s, char c) {

      // Move pointer to the end
    while (*s++);
  
    // Append the new character
    *(s - 1) = c;
  
    // Add null terminator to mark new end
    *s = '\0';
}