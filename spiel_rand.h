#ifndef _H_SPIEL_RAND
#define _H_SPIEL_RAND

typedef enum {TOO_LOW, TOO_HIGH, LOWER_BOUNDS, UPPER_BOUNDS, MATCH} mstate;

/** die grenze **/
int get_boundary(void);

/** rollt den würfel **/
void role_dice(int bound);

/** die ratezahl prüfen, ohne sie nach aussen zu geben **/
mstate matches(int guess);

/** anzahl der versuche **/
int get_tries(void);

#endif
