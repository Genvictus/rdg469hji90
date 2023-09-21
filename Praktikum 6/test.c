// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 6 Oktober 2022
// Topik: ADT Queue
// Deskripsi: Praktikum antrianSix.c

#include <stdio.h>
#include "boolean.h"
#include "prioqueuetime.c"

int main(){
	/* KAMUS */
	PrioQueueTime Q;
    infotype X;

	/* ALGORITMA */
	MakeEmpty(&Q, 8);
	do{
        scanf("%d %c", &Time(X), &Info(X));
        Enqueue(&Q, X);
		PrintPrioQueueTime(Q);
    } while(Time(X) != 6969);
		printf("%d %d %d\n", Head(Q), Tail(Q), NBElmt(Q));

	while(Tail(Q) != Head(Q)){
		Dequeue(&Q, &X);
        printf("%d %c\n", Time(X), Info(X));
	}
	
	do{
        scanf("%d %c", &Time(X), &Info(X));
        Enqueue(&Q, X);
		PrintPrioQueueTime(Q);
    } while(Time(X) != 6969);
		printf("%d %d %d\n", Head(Q), Tail(Q), NBElmt(Q));

	while(Tail(Q) != Head(Q)){
		Dequeue(&Q, &X);
        printf("%d %c\n", Time(X), Info(X));
	}
		Dequeue(&Q, &X);
        printf("%d %c\n", Time(X), Info(X));

		PrintPrioQueueTime(Q);
		printf("%d %d %d\n", Head(Q), Tail(Q), NBElmt(Q));
}