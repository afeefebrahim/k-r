/*program to print all input lines that are longer than 80 characters.*/
#include <stdio.h>
#define MIN_LENGTH 20

int main(void) {
  char buffer[MIN_LENGTH + 1];
  int c, n=0;

  while (1) {

    c = getchar();
    if (c == EOF) break;

    if (n < MIN_LENGTH) {

      /* State 1: Fewer than MIN_LENGTH characters in line */

      if (c == '\n') n = 0;
      else {
        buffer[n++] = c;
        if (n == MIN_LENGTH) {
          buffer[n] = '\0';
          printf("%s",buffer);
        }
      }
    }

    else {

      /* State 2: At least MIN_LENGTH characters in line */

      putchar(c);
      if (c == '\n') n = 0;
    }
  }

  return 0;
}
