// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 15 September 2022
// Topik: ADT List Statik dan Dinamik
// Deskripsi: Praktikum intersect.c

#include <stdio.h>
#include "boolean.h"
#include "liststatik.c"


int main(){
	/* KAMUS */
	ListStatik l1, l2, lres;

	/* ALGORITMA */
	readList(&l1);
	readList(&l2);
	
	sortList(&l1, true);
	sortList(&l2, true);
	
	printf("%d %d\n", listLength(l1), listLength(l2));
	printList(l1);
	printf("\n");
	printList(l2);
	printf("\n");
	
	return 0;
}
