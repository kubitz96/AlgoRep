#include<stdio.h>
#include<stdlib.h>



 #define ERRORE_MEMORIA -1
 #define  ERRORE_FILE    -2


float *Allocvect(int n);
void readfile(const char *filename, float **vect, int *n);
void gestiscierrore(int code);
void printvect(float *vect,int n);
float *modificavettore (float *vettore, int n);
void makeOutputFile(float* nuovovettore, int n);

int main(){

  int n; //numero degli elementi dell'array
  const char filename[200];
  float *vect;
  

      printf("Inserisci nome del file: ");
      scanf("%s", filename);
      puts("\n\n");
      //funzione che apre il file e legge il vettore//
    readfile(filename, &vect, &n);

    //funzione che stampa il vettore:
     printvect(vect,n);

    puts("\n\n");
    

    //richiamo alla funzione per modificare il vettore, creandone un altro e inserendo i valori s1 e s2 in modo da ordinarlo come vuole la traccia//
       float *nuovovettore;
        nuovovettore = modificavettore (vect,n);
   
   // funzione che stampi il nuovo vettore per finire il programma//

    makeOutputFile(nuovovettore,n);
    
    return 0;
}


void readfile(const char *filename, float **vect, int *n){

   float *vectemp;
   int ntemp;
    float x;

      FILE *pt;
      
     vectemp = Allocvect(ntemp);
      
      pt = fopen(filename, "r");

    if(pt==NULL)  {

           gestiscierrore(ERRORE_FILE);
    }
      fscanf(pt, "%d", &ntemp);

         for(size_t i= 0; i<ntemp ; i++){

            if(fscanf(pt,"%f",&x)!= EOF)
              {
                   vectemp[i]= x;
              }     
             else 
                 {
                    break;
                 }       
      }
   
      fclose(pt);
      //questo lo faccio per non portarmi appresso troppi operatori *//
      *vect = vectemp;
      *n    = ntemp;
}

float *Allocvect(int n){
    float *v;

    v =(float *)calloc(n,sizeof(float));
    if(v == NULL) 

    {
        gestiscierrore(ERRORE_MEMORIA);
    }

    return v;
}

void gestiscierrore(int code)
{
	switch (code)
	{
	    case ERRORE_FILE :
		printf(" Errore nella lettura del file ");
		break;
	    case  ERRORE_MEMORIA:
		printf(" Memoria insufficiente ");
		break;
	}
	   exit(-1);
}
 

 void printvect(float *vect, int n){

      for(size_t i = 0; i< n; i++){
            printf("%3.2f  ", vect[i]);
      }

 }

float *modificavettore (float *vect, int n){

    int s1, s2;
    float *newvect;
    int i;
    int y = 0; //lo uso come contatore

    printf ("\n\nInserisci due valori per l'ordinamento. ");
    scanf ("%d%d", &s1, &s2);

    newvect = Allocvect(n);

    for (i = 0; i < n; i++)
  {
    if (vect[i] < s1)
    {
      newvect[y] = vect[i];
      y++;
    }          
  }
  for (i = 0; i < n; i++)
  {
    if (vect[i] >= s1 &&  vect[i] <= s2)
    {
      newvect[y] = vect[i];
      y++;
    }          
  }
  for (i = 0; i < n; i++)
  {
    if (vect[i] > s2)
    {
      newvect[y] = vect[i];
       y++;
    }          
  }
    return newvect;

}

void makeOutputFile(float* nuovovettore, int n)
{
	FILE* Pnt = fopen("output.txt", "w"); //in fase di scrittura se il file non esiste viene generato//

   for(size_t i= 0; i<n; i++){

        fprintf(Pnt,"%3.2f  ", nuovovettore[i]);

   }

    fclose(Pnt);

}








