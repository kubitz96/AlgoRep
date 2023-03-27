#ifndef PROTOTIPI_H
#define PROTOTIPI_H

float **allocMatrix(int m, int n);
void freeMatrix(float **p, int m);
int read_file(char filename[64], struct Persona **start);
void errorManager(int c);
void add_in_list(struct Persona ** start, struct Dati temp);
void print_list(struct Persona *start);
void remove_from_list(struct Persona **start, int soglia);
int write_sortedon_list(char filename[64], struct Persona *start, float ** matrix);
void freelist(struct Persona * start);
int sizelist(struct Persona * start);
void printMatrix(float **p, int m, int n);
float **build_matrix(struct Persona * start, float ** m, int size);
struct Persona * read_from_listat(struct Persona *start, int idx);

#endif