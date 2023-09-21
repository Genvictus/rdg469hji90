// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 15 September 2022
// Topik: ADT List Statik dan Dinamik
// Deskripsi: Praktikum merge.c

#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

void mergeList(ListDin *lres, ListDin l1){
	/* I.S. lres & l1 terdefinisi
		F.S. lres digabungkan elemen l1 */
	/* KAMUS LOKAL */
	int i, j;
	boolean found;
	
	/* ALGORITMA */
	for(i=0;i<=getLastIdx(l1);i++){
		found = false;
		for(j=0;j<=getLastIdx(*lres);j++){
			found |= ELMT(l1, i) == ELMT(*lres, j);
		}
		if(!found)
			insertLast(lres, ELMT(l1, i));
	}
}

int main(){
	/* KAMUS */
	ListDin l1, l2, lres;

	/* ALGORITMA */
	CreateListDin(&l1, 200);
	readList(&l1);
	CreateListDin(&l2, 200);
	readList(&l2);
	
	CreateListDin(&lres, 400);
	mergeList(&lres, l1);
	mergeList(&lres, l2);
	sort(&lres, true);
	
	printf("%d\n", listLength(lres));
	printList(lres);
	printf("\n");
	
	return 0;
}
