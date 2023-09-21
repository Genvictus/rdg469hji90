// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 8 September 2022
// Topik: ADT Sederhana
// Deskripsi: Praktikum vector.c

/* File: vector.c */
/* Tanggal: 8 September 2022 */
/* implementasi ADT VECTOR */

#include <stdio.h>
#include<math.h> 	// menghitung magnitudo
#include "point.h"

/* *** Definisi ABSTRACT DATA TYPE VECTOR *** */
#define VECTOR POINT
/* *** Notasi Akses: Selektor VECTOR *** */
#define AbsisComponent(V) Absis(V)
#define OrdinatComponent(V) Ordinat(V)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
void CreateVector(VECTOR *v, float x, float y){
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	AbsisComponent(*v) = x;
	OrdinatComponent(*v) = y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return sqrt(AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v));
}

VECTOR Add(VECTOR a, VECTOR b){
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
	
	/* KAMUS LOKAL */
	VECTOR res;
	float X, Y;
	
	/* ALGORITMA */
	X = AbsisComponent(a) + AbsisComponent(b);
	Y = OrdinatComponent(a) + OrdinatComponent(b);
	CreateVector(&res, X, Y);
	
	return res;
}

VECTOR Substract(VECTOR a, VECTOR b){
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	AbsisComponent(b) = -AbsisComponent(b);
	OrdinatComponent(b) = -OrdinatComponent(b);
	
	return (Add(a,b));
}

float Dot(VECTOR a, VECTOR b){
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b));
}
VECTOR Multiply(VECTOR v, float s){
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * v.x, s * v.y) */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	AbsisComponent(v) = s*AbsisComponent(v);
	OrdinatComponent(v) = s*OrdinatComponent(v);
	
	return v;
}

