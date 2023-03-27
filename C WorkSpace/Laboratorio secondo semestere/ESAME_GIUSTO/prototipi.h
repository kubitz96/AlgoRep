#ifndef PROTOTIPI_H
#define PROTOTIPI_H

void errorManager(int c);
int load_matches_from_file(char filename[], struct Configurazione **start);
void print_list(struct Configurazione *start);
void freelist(struct Configurazione * start);
void add_in_list(struct Configurazione ** start, struct Dati temp);
char the_winner_is(char Conf[3][3]);
int match_score(char Conf[3][3]);
void print_match(struct Dati* temp);
void remove_tied(struct Configurazione **start);
int sizelist(struct Configurazione * start);
int write_winners_on_file(char filename[], char filename2[], struct Configurazione *start);


#endif