#ifndef PROTOTIPI_H
#define PROTOTIPI_H

void errorManager(int c);
int load_matches_from_file(char filename[64], struct Configurazione **start);
void print_list(struct Configurazione *start);
void freelist(struct Configurazione * start);
void add_in_list(struct Configurazione ** start, struct Dati temp);
char the_winner_is(char Conf[3][3], char *vincitore);
int match_score(char Conf[3][3], int *punteggio);
void print_match(struct Dati* temp);
void remove_tied(struct Configurazione **start, char vincitore);
int sizelist(struct Configurazione * start);
int write_winners_on_file(char filename[64], char filename2[64], struct Configurazione *start);


#endif