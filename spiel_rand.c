#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "spiel_rand.h"

static int current_random_number = 0;
static int tries = 0;
static int boundary = 0;

int get_boundary()
{
  return boundary;
}

void role_dice(int bound)
{
  boundary = bound;
  time_t t;
  srand((unsigned) time(&t));
  current_random_number = (rand() % boundary) + 1;
}

mstate matches(int guess) 
{
  tries++;

  if (current_random_number <= 0)
    {
      return LOWER_BOUNDS;
    } else if (current_random_number > get_boundary()) 
    {
      return UPPER_BOUNDS;
    }

  if (current_random_number == guess) 
    {
      return MATCH;
    } else if (current_random_number < guess)
    {
      return TOO_LOW;
    } else if (current_random_number > guess)
    {
      return TOO_HIGH;
    }

    exit(-1);
}

int get_tries(void)
{
  return tries;
}
