// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 15 September 2022
// Topik: ADT List Statik dan Dinamik
// Deskripsi: Praktikum olist.c

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

void kemunculan(ListStatik l, ElType X, int *count, int *lastfound){
	/* menghitung kemunculan nilai X dalam l dan menuliskan dalam count, serta memeriksa indeks terakhir X dalam list dan menuliskanm dalam lastfound*/
	/* KAMUS LOKAL */
	int i;

	/* ALGORITMA */
	*count = 0;
	*lastfound = IDX_UNDEF;
	for(i=0;i<=getLastIdx(l);i++){
		if(ELMT(l, i) == X){
			*count = *count + 1;
			*lastfound = i;
		}
	}
}

boolean isMedian(ListStatik l, ElType X){
	/* memeriksa apakah X adalah median */
	/* KAMUS LOKAL */
	int median;

	/* ALGORITMA */
	sortList(&l, true);
	if(listLength(l)%2 == 1){	// jumlah elemen list ganjil
		median = ELMT(l, (getLastIdx(l))/2);
	}
	else{	// jumlah elemen list genap
		median = ELMT(l, (getLastIdx(l)-1)/2);
	}
	return X == median;
}


int main(){
	/* KAMUS */
	ListStatik l;
	int X;
	int jml, lastfound, max, min;

	/* ALGORITMA */
	readList(&l);
	scanf("%d", &X);
	
	printList(l);
	printf("\n");
	
	kemunculan(l, X, &jml, &lastfound);
	
	printf("%d\n", jml);
	if(jml != 0){
		printf("%d\n", lastfound);

		extremeValues(l, &max, &min);
		if(X == max)
			printf("maksimum\n");
		if(X == min)
			printf("minimum\n");
			
		if(isMedian(l, X))
			printf("median\n");
	}
	else{
		printf("%d tidak ada\n", X);
	}
	
	return 0;
}
