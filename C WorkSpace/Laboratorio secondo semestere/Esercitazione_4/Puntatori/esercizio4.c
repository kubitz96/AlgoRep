/*Dato in input un vettore  v , scrivere una funzione che restituisca un vettore  riassunto  di 3 elementi dove:

il primo elemento punta al minimo di  v . Se tale valore è presente più volte, si desidera che l'elemento punti alla prima occorrenza
il secondo elemento punta al massimo di  v . Se tale valore è presente più volte, si desidera che l'elemento punti all'ultima occorrenza
il terzo elemento punta al valore più frequente nel vettore  v . In caso di parità, si punterà all'ultima occorrenza*/

#include<stdio.h>

#define N 5

void funzionerias(int vettore[], int n, int *vettrias[]);

int main()
{
	int v[N] = {1,2,2,2,5};
	int *riassunto[3];		//vettore di puntatori, quindi che puntano agli elementi del vettore originale

	funzionerias(v, N, riassunto);

	for (int i = 0; i < 3; ++i)
	{
		printf("%d ", *riassunto[i]);
	}
	printf("\n");

	return 0;
}

void funzionerias(int vettore[], int n, int *vettrias[])
{
	int frequenza[n];
	int idmin, idmax, idmaxfre;

	idmin = idmax = 0;	//sfrutto gli indirizzi dato che devo ritornare un vettore riassunto che punta agli elementi del vettore primario 

	for (int i = 0; i < n; ++i)
	{
		if(vettore[i] > vettore[idmax]) idmax = i;
		if(vettore[i] < vettore[idmin]) idmin = i;
		for (int j = 0; j < n; ++j)
		{
			if(vettore[i] == vettore[j]) ++frequenza[i];
		}
	}

	idmaxfre = 0;

	for (int i = 1; i < n; ++i)
	{
		if(frequenza[i] > frequenza[idmaxfre]) idmaxfre = i;
	}

	vettrias[0] = &vettore[idmin];
	vettrias[1] = &vettore[idmax];
	vettrias[2] = &vettore[idmaxfre];
}