/* 
 * @title:	FunzioniVarieVettori.cpp
 * @author:	Gabriele Ara
 * @date:	15/11/2013
 *
 * @notes:	Le funzioni si trovano in basso sotto
 *			al main, le loro definizioni con le relative
 *			descrizioni sono qua in cima.
 *			Qualsiasi occorrenza di:
 *			-inf indica l'indice del primo elemento
 *			-sup indica l'indice de3ll'ultimo elemento
 *			-num indica il numero da cercare
 *			-pos indica la posizione del numero cercato (se trovato)
 */
#include <iostream>

using namespace std;

/*
 * Scambia i due elementi; funziona solo
 * con interi o con oggetti "castabili"
 * ad intero (credo).
 */
void exchange(int& a, int& b);

/*
 * Versione migliore della ricerca sequenziale.
 * Ricordarsi comunque che la ricerca sequenziale
 * è un algoritmo non efficiente e va usato con
 * cautela, preferibilmente con array di modeste
 * dimensioni.
 *
 * Aggiungerei qui, ma vale anche per
 * le altre funzioni, che trovo inutile il fatto
 * che la funzione è booleana e restituisce la
 * posizione per riferimento.
 * Basterebbe che la funzione fosse intera:
 * nel caso in cui venga trovato un elemento
 * essa restituirebbe un numero positivo o nullo
 * (l'indirizzo va da 0 a N) altrimenti un numero
 * negativo (ad esempio -1, che non può essere la
 * posizione di nessun elemento).
 */
bool sequential_search(int* vect, int inf, int sup, int num, int& pos);

/*
 * Versione ricorsiva della ricerca sequenziale.
 * Ancora più inefficiente della sua versione standard,
 * poiché oltre a scorrere tutti gli elementi se
 * l'elemento cercato è l'ultimo del vettore
 * necessita pure dello spazio di memoria necessario
 * per il processo ricorsivo, poi c'è da allocare e
 * deallocare memoria per ogni istanza, poi...
 * Insomma avete capito... <_<"
 * L'ho scritta solo perché mi sembrava
 * richesta tra gli esercizi.
 */
 
bool rec_sequential_search(int* vect, int inf, int sup, int num, int& pos);

/*
 * Ricerca binaria all'interno di un vettore.
 * E' l'algoritmo migliore poiché impiega al
 * massimo log2(N) operazioni per trovare/non
 * trovare un elemento in un'array di N elementi.
 * La versione che scrivo qui è la versione
 * iterativa, che, sebbene non sia credo granché
 * presa in considerazione qui al corso, è comunque
 * degna di nota, poiché impiega minori risorse della
 * controparte ricorsiva.
 */
bool binary_search(int* vect, int inf, int sup, int num, int& pos);

/*
 * Versione ricorsiva della ricerca binaria.
 */
bool rec_binary_search(int* vect, int inf, int sup, int num, int& pos);

/*
 * Selection Sort, ricorsivo.
 */
void selection_sort(int* vect, int inf, int sup);

/*
 * Bubble Sort, iterativo.
 */
void bubble_sort(int* vect, int inf, int sup);

/*
 * Stesso discorso della ricerca binaria.
 * Questo Bubble Sort ricorsivo, impiegato
 * nel corso, a mio parere è meno efficente
 * della sua versione iterativa.
 * Ricordo che ogni algoritmo ricorsivo è
 * traducibile in un'equivalente algoritmo
 * iterativo più efficente con un ciclo.
 *
 */
void rec_bubble_sort(int* vect, int inf, int sup);

/*
 * Questo main testa il corretto
 * funzionamento delle funzioni.
 */
int main()
{
	int vect[] = {0,4,1,5,6,4,8,4,1,2,3,1,8,0,5,3};
	int dim = sizeof(vect)/sizeof(int);
	int pos;
	
	///////////////////////////////////////////////////////////////////////////////
	cout<<"Ricerca sequenziale di un '3': ";
	
	if(sequential_search(vect, 0, dim-1, 3, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
		cout<<"Non trovato"<<endl<<endl;
	
	cout<<"Ricerca sequenziale di un '7': ";
	
	if(sequential_search(vect, 0, dim-1, 7, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
		cout<<"Non trovato"<<endl<<endl;
	
	///////////////////////////////////////////////////////////////////////////////
	cout<<"Ricerca sequenziale ricorsiva di un '3': ";
	
	if(rec_sequential_search(vect, 0, dim-1, 3, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
		cout<<"Non trovato"<<endl<<endl;
	
	cout<<"Ricerca sequenziale ricorsiva di un '7': ";
	
	if(rec_sequential_search(vect, 0, dim-1, 7, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
	
		cout<<"Non trovato"<<endl<<endl;
	
	///////////////////////////////////////////////////////////////////////////////
	cout<<"Vettore originale: ";
	
	for(int i=0; i<dim; i++)
		cout<<vect[i]<<", ";
	cout << endl<<endl;
	
	selection_sort(vect, 0, dim-1);
	
	cout<<"Vettore ordinato (sel_sort): ";
	
	for(int i=0; i<dim; i++)
		cout<<vect[i]<<", ";
	cout << endl<<endl;
	
	///////////////////////////////////////////////////////////////////////////////
	int vectB[] = {0,4,1,5,6,4,8,4,1,2,3,1,8,0,5,3};
	
	cout<<"Vettore originale: ";
	
	for(int i=0; i<dim; i++)
		cout<<vectB[i]<<", ";
	cout << endl<<endl;
	
	bubble_sort(vectB, 0, dim-1);
	
	cout<<"Vettore ordinato (bub_sort): ";
	
	for(int i=0; i<dim; i++)
		cout<<vectB[i]<<", ";
	cout << endl<<endl;
	
	///////////////////////////////////////////////////////////////////////////////
	int vectC[] = {0,4,1,5,6,4,8,4,1,2,3,1,8,0,5,3};
	
	cout<<"Vettore originale: ";
	
	for(int i=0; i<dim; i++)
		cout<<vectC[i]<<", ";
	cout << endl<<endl;
	
	rec_bubble_sort(vectC, 0, dim-1);
	
	cout<<"Vettore ordinato (rec_bub_sort): ";
	
	for(int i=0; i<dim; i++)
		cout<<vectC[i]<<", ";
	cout << endl<<endl;
	
	
	///////////////////////////////////////////////////////////////////////////////
	cout<<"Ricerca binaria di un '3': ";
	
	if(binary_search(vect, 0, dim-1, 3, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
		cout<<"Non trovato"<<endl<<endl;
	
	cout<<"Ricerca binaria di un '7': ";
	
	if(binary_search(vect, 0, dim-1, 7, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
	
		cout<<"Non trovato"<<endl<<endl;
	
	
	///////////////////////////////////////////////////////////////////////////////
	cout<<"Ricerca binaria ricorsiva di un '3': ";
	
	if(rec_binary_search(vect, 0, dim-1, 3, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
		cout<<"Non trovato"<<endl<<endl;
	
	cout<<"Ricerca binaria ricorsiva di un '7': ";
	
	if(rec_binary_search(vect, 0, dim-1, 7, pos))
		cout<<"Trovato in pos: "<<pos<<endl<<endl;
	else
	
		cout<<"Non trovato"<<endl<<endl;
		
	return 0; //boia che palle 'sti test...
}

void exchange(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}


bool sequential_search(int* vect, int inf, int sup, int num, int& pos)
{
	for(int i = inf; i <= sup; i++)
		if(vect[i] == num)
		{
			pos = i;
			return true;
		}
	
	return false;
}

bool rec_sequential_search(int* vect, int inf, int sup, int num, int& pos)
{
	if(vect[inf] == num)
	{
		pos = inf;
		return true;
	}
	
	if(inf+1 <= sup)
		return rec_sequential_search(vect, inf+1, sup, num, pos);
	else
		return false;
}

bool binary_search(int* vect, int inf, int sup, int num, int& pos)
{
	int middle;
	
	while(inf <= sup)
	{
		middle = (inf+sup)/2;
	
		if(vect[middle] == num)
		{
			pos = middle;
			return true;
		}
		
		if(vect[middle] > num)
			sup = middle-1;
		else
			inf = middle+1;
	}
	
	return false;
}

bool rec_binary_search(int* vect, int inf, int sup, int num, int& pos)
{
	int middle = (inf+sup)/2;
	
	if(vect[middle] == num)
	{
		pos = middle;
		return true;
	}
	
	if(vect[middle] > num)
	{
		if(inf < middle)
			return rec_binary_search(vect, inf, middle-1, num, pos);
		else
			return false;
	}
	else
	{
		if(sup > middle)
			return rec_binary_search(vect, middle+1, sup, num, pos);
		else
			return false;
	}
}

void selection_sort(int* vect, int inf, int sup)
{
	int min = inf;
	for(int i = inf+1; i <= sup; i++)
	{
		if(vect[i] < vect[min])
			min = i;
	}
	
	if(min > inf)
		exchange(vect[inf], vect[min]);
	
	if(inf+1 < sup)
		selection_sort(vect, inf+1, sup); // NOTE: il return è implicito
}

void bubble_sort(int* vect, int inf, int sup)
{
	//segnala se è avvenuto o meno uno scambio
	bool flag;
	do
	{
		flag = false;
		for(int i = inf; i < sup; i++)
		{
			
			if(vect[i] > vect[i+1])
			{
				flag = true;
				exchange(vect[i], vect[i+1]);
			}
		}
		
		
	}
	while(flag); // NOTE: il return è implicito
}

void rec_bubble_sort(int* vect, int inf, int sup)
{
	//segnala se è avvenuto o meno uno scambio
	bool flag = false;
	for(int i = inf; i < sup; i++)
	{
		if(vect[i] > vect[i+1])
		{
			flag = true;
			exchange(vect[i], vect[i+1]);
		}
	}
	
	if(flag)
		return rec_bubble_sort(vect, inf, sup);
}











