// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 3 November 2022
// Topik: ADT Variasi List Linier
// Deskripsi: Pra-praktikum list_circular.c

#include <stdio.h>
#include "list_circular.h"

int main(){
	/* KAMUS */
	int n, k;
	List pemain;
	ElType hit;
	int i;
	Address p, prec;

	/* ALGORITMA */
	scanf("%d", &n);
	scanf("%d", &k);

	CreateList(&pemain);
	for(i=1;i<=n;i++){
		insertLast(&pemain, i);
	}

	i = 0;
	p = FIRST(pemain);
	for(;;){
		i++;
		if(i == k){
			FIRST(pemain) = p;
			deleteFirst(&pemain, &hit);
			p = FIRST(pemain);
			i = 0;
		}
		else{
			p = NEXT(p);
		}

		if(isEmpty(pemain)) break;

		if(i == 0)
		printf("%d\n", hit);
	}
	printf("Pemenang %d\n", hit);
}