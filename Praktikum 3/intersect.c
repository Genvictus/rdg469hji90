// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 15 September 2022
// Topik: ADT List Statik dan Dinamik
// Deskripsi: Praktikum intersect.c

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

ListStatik intersectList(ListStatik l1, ListStatik l2){
	/* membuat list irisan l1 dan l2 */
	/* KAMUS LOKAL */
	ListStatik lres;
	int i, j;

	/* ALGORITMA */
	CreateListStatik(&lres);

	for(i=0;i<=getLastIdx(l1);i++){
		for(j=0;j<=getLastIdx(l2);j++){
			if(ELMT(l1, i) == ELMT(l2, j))
				insertLast(&lres, ELMT(l1, i));
		}
	}
	return lres;
}

int main(){
	/* KAMUS */
	ListStatik l1, l2, lres;

	/* ALGORITMA */
	CreateListStatik(&l1);
	readList(&l1);
	CreateListStatik(&l2);
	readList(&l2);
	
	lres = intersectList(l1, l2);
	sortList(&lres, true);
	
	printf("%d\n", listLength(lres));
	printList(lres);
	printf("\n");
	
	return 0;
}
