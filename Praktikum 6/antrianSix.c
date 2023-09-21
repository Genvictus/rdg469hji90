// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 6 Oktober 2022
// Topik: ADT Queue
// Deskripsi: Praktikum antrianSix.c

#include <stdio.h>
#include "boolean.h"
#include "queue.h"

int main(){
	/* KAMUS */
	int kode, t;
	Queue q;
	ElType val;
	int n, maks, min;
	float avg;

	/* ALGORITMA */
	CreateQueue(&q);
	n = 0;
	maks = -99999;
	min = 99999;
	avg = 0;
	do{
		scanf("%d", &kode);
		if(kode == 1){	// enq
			scanf("%d", &val);
			if(isFull(q)){
				printf("Queue penuh\n");
			}
			else{
				enqueue(&q, val);
			}
		}
		else if(kode == 2){	// deq
			if(isEmpty(q)){
				printf("Queue kosong\n");
			}
			else{
				dequeue(&q, &val);
				n++;
				if(maks < val){
					maks = val;
				}
				if(min > val){
					min = val;
				}
				avg += val;
			}
		}
	} while (kode != 0);

	printf("%d\n", n);
	if(n == 0){
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
	}
	else{
		printf("%d\n", min);
		printf("%d\n", maks);
		avg = avg/n;
		printf("%.2f\n", avg);
	}

	return 0;
}