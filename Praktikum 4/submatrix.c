// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 22 September 2022
// Topik: ADT Matrix
// Deskripsi: Praktikum submatrix.c

#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

int jmlDaerah(Matrix m, int rstart, int cstart, int M){
	/* KAMUS LOKAL */
	int i, j;
	int count;

	/* ALGORITMA */
	count = 0;
	for(i=rstart; i < rstart+M; i++){
		for(j=cstart; j < cstart+M; j++){
			if(ELMT(m, i, j) != 0)
				count++;
		}
	}
	return count;
}

int main(){
	/* KAMUS */
	int N, M;
	Matrix m;
	int daerah, maks, temp;
	int i, j;

	/* ALGORITMA */
	scanf("%d%d", &N, &M);
	readMatrix(&m, N, N);

	daerah = 1;				// mulai dari daerah pertama
	maks = jmlDaerah(m, 0, 0, M);

	for(i=0; i <= getLastIdxRow(m)-M+1; i++){
		for(j=0; j <= getLastIdxCol(m)-M+1; j++){
			temp = jmlDaerah(m, i, j, M);
			if(temp > maks){
				maks = temp;
				daerah = (N-M+1)*i + j + 1;
			}
		}
	}
	printf("%d\n", daerah);

	return 0;
}