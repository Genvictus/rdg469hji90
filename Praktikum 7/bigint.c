// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 20 Oktober 2022
// Topik: ADT Stack
// Deskripsi: Praktikum bigint.c

#include <stdio.h>
#include "stack.h"

#define CAP 105

void pushInt (Stack *S, char *strint);
/* I.S. S dan msd sembarang
	F.S. masukkan angka ke dalam stack, dan catat digit desimal terbesar
	(digit paling kiri) */

Stack subsInt (Stack S1, Stack S2);
/* menghitung nilai desimal S1-S2, dengan S1 > S2, dan menyimpan digit" dalam stack
	dengan satuan terletak di paling bawah dan digit desimal terbesar di top */

void cleanLeadingZero (char *strint);
/* I.S. strint terdefinisi, hanya terdiri dari karakter-karakter bilangan desimal
	F.S. strint tidak memiliki leading zero, bisa saja kosong */

int main(){
	/* KAMUS */
	Stack num1, num2, res;
	char s1[CAP], s2[CAP], sres[CAP];
	int msd1, msd2;
	boolean ispos, iszero;
	int i, n;
	int l1, l2;

	/* ALGORITMA */
	scanf("%s", s1);
	cleanLeadingZero(s1);

	scanf("%s", s2);
	cleanLeadingZero(s2);

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

	if(iszero){
		printf("0\n");
	}
	else{
		// masukkan string ke dalam stack
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
		
		i = 0;
		while(!IsEmpty(res)){
			Pop(&res, &n);
			sres[i] = '0' + n;
			i++;
		}
		sres[i] = '\0';

		cleanLeadingZero(sres);
		printf("%s\n", sres);
	}

	return 0;
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

void cleanLeadingZero (char *strint){
	/* KAMUS LOKAL */
	int i,j;

	/* ALGORITMA */
	i = 0;
	while(strint[i] == '0'){
		i++;
	}
	// strint[i] != 0, bisa saja akhir string

	j = 0;
	while(strint[i] != '\0'){
		strint[j] = strint[i];
		i++;
		j++;
	}
	// strint[i] == '0', j bisa saja 0 (tidak terdapat bilangan non 0)

	strint[j] = '\0';
}