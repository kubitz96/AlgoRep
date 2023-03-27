#ifndef PROTOTIPI_H
#define PROTOTIPI_H

int read_file(char filename[64], struct Azienda **start);
void errorManager(int c);
void add_in_list(struct Azienda ** start, struct Dati temp);
void print_list(struct Azienda *start);
void remove_from_list(struct Azienda **start, int soglia);
int write_sortedon_list(char filename[64], struct Azienda *start);
void freelist(struct Azienda * start);
int sizelist(struct Azienda * start);

#endif