// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 8 September 2022
// Topik: ADT Sederhana
// Deskripsi: Praktikum mtime.c

/* File: mtime.c */
/* Tanggal: 8 September 2022 */
/* program yang digunakan untuk membaca beberapa pasangan TIME yang merepresentasikan waktu mulai dan waktu selesai pembicaraan telepon di suatu perusahaan penyedia layanan telepon */

#include <stdio.h>
#include "time.h"

int main(){
	/* KAMUS LOKAL */
	int N, i;
	TIME T1, T2, Ttemp, TMin, TMax;
	
	/* ALGORITMA */
	scanf("%d", &N);
	
	CreateTime(&TMin, 23, 59, 59);	// inisialisasi nilai TMin dan Tmax
	CreateTime(&TMax, 0, 0, 0);
	
	for(i=1;i<=N;i++){
		printf("[%d]\n", i);
		BacaTIME(&T1);
		BacaTIME(&T2);
		
		if(TGT(T1, T2)){	// T1 > T2, tukar (jadikan T2 sebagai waktu akhir)
			Ttemp = T1;
			T1 = T2;
			T2 = Ttemp;
		}
		
		printf("%d\n", Durasi(T1, T2));
		
		if(TLT(T1, TMin))
			TMin = T1;
		
		if(TGT(T2, TMax))
			TMax = T2;
	}
	TulisTIME(TMin);
	printf("\n");
	TulisTIME(TMax);
	printf("\n");
}

