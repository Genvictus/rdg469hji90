// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 20 Oktober 2022
// Topik: ADT Stack
// Deskripsi: Praktikum bigint.c

#include <stdio.h>
#include "stack.h"

void pushInt (Stack *S, char *strint);
/* I.S. S dan msd sembarang
	F.S. masukkan angka ke dalam stack, dan catat digit desimal terbesar
	(digit paling kiri) */

Stack subsInt (Stack S1, Stack S2);
/* menghitung nilai desimal S1-S2, dengan S1 > S2, dan menyimpan digit" dalam stack
	dengan satuan terletak di paling bawah dan digit desimal terbesar di top */

int main(){
	/* KAMUS */
	Stack num1, num2, res;
	char s1[105], s2[105];
	int msd1, msd2;
	boolean ispos, iszero;
	int i, n;
	int l1, l2;

	/* ALGORITMA */
	scanf("%s", s1);
	scanf("%s", s2);

	l1 = 0;
	while(s1[l1] != '\0'){
		l1++;
	}

	l2 = 0;
	while(s2[l2] != '\0'){
		l2++;
	}

	// cek S1 > S2, simpan dalam ispos
	ispos = (l1 > l2);

	if((l1 == l2)){
		i = 0;
		while((s1[i] == s2[i]) && (i < l1-1)){
			i++;
		}
		// s1[i] != s2[i] atau i == l1-1
		ispos = s1[i] > s2[i];
		iszero = s1[i] == s2[i];
	}

	// masukkan string ke dalam stack
	if(iszero){
		printf("0\n");
	}
	else{
		if(ispos){
			pushInt(&num1, s1);
			pushInt(&num2, s2);
		}
		else {
			pushInt(&num1, s2);
			pushInt(&num2, s1);
		}

		CreateEmpty(&res);
		res = subsInt(num1, num2);	// hitung |S1-S2|

		if(!ispos){
			//cetak tanda negatif
			printf("-");
		}

		// cetak int
		while(!IsEmpty(res)){
			Pop(&res, &n);
			printf("%d", n);
		}
		printf("\n");
	}	

}

/* REALISASI PROSEDUR & FUNGSI */

void pushInt (Stack *S, char *strint){
	/* KAMUS LOKAL */
	int i;

	/* ALGORITMA */
	CreateEmpty(S);
	i = 0;
	while(strint[i] != '\0'){		// masukkan string ke dalam stack
		Push(S, (strint[i] - '0'));
		i++;
	}
}

Stack subsInt (Stack S1, Stack S2){
	/* KAMUS LOKAL */
	Stack res;
	infotype val1, val2, valtemp;
	int carrymin;

	/* ALGORITMA */
	CreateEmpty(&res);

	carrymin = 0; // pengurangan pertama tidak memiliki carry negatif
	while(!IsEmpty(S2)){
		Pop(&S1, &val1);
		Pop(&S2, &val2);
		valtemp = val1 - val2 - carrymin;
		if(valtemp < 0){
			valtemp += 10;
			carrymin = 1;
		}
		else{
			carrymin = 0;
		}
		Push(&res, valtemp);
	}
	while(!IsEmpty(S1)){
		Pop(&S1, &val1);
		valtemp = val1 - carrymin;
		if(valtemp < 0){
			valtemp += 10;
			carrymin = 1;
		}
		else{
			carrymin = 0;
		}
		Push(&res, valtemp);
	}

	return res;
}