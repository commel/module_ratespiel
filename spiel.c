#include <stdio.h>
#include "spiel_rand.h"

int main() {
  mstate state = LOWER_BOUNDS;
  role_dice(50);

  printf("Ich habe mir eine Zufallszahl zwischen 1 und %d ausgedacht. Du musst sie erraten!\n", get_boundary());
  
  while (state != MATCH) {
    int ratezahl = -1;
    scanf("%d", &ratezahl);

    state = matches(ratezahl);

    switch(state) {
    case TOO_LOW:
      printf("Meine Zahl ist kleiner\n");
      break;
    case TOO_HIGH:
      printf("Meine Zahl ist größer\n");
      break;
    case MATCH:
      printf("Glückwunsch, du hast die Zahl in %d Versuchen erraten!\n", get_tries());
      break;
    case LOWER_BOUNDS:
      printf("Die Zahl muss größer sein als 0\n");
      break;
    case UPPER_BOUNDS:
      printf("Die Zahl ist nicht größer als %d\n", get_boundary());
      break;
    default:
      printf("Dieser Fall ist nicht vorgesehen\n");
    }
  }
  

  return 0;
}
