// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 8 September 2022
// Topik: ADT Sederhana
// Deskripsi: Praktikum garis.c

/* File: garis.c */
/* Tanggal: 8 September 2022 */
/* implementasi ADT GARIS */

#include <stdio.h>
#include <math.h>	//dibutuhkan untuk perhitungan panjang garis
#include "garis.h"

/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void CreateGaris (GARIS * L, POINT P1, POINT P2){
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
   
	/* KAMUS LOKAL */
	POINT P1, P2;
	
	/* ALGORITMA */
	for(;;){
		BacaPOINT(&P1);
		BacaPOINT(&P2);
		if(NEQ(P1, P2))
			break;
		else
			printf("Garis tidak valid\n");
	}
	
	CreateGaris(L, P1, P2);
	
}

void TulisGARIS (GARIS L){
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
   
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	printf("(");
	TulisPOINT(PAwal(L));
	printf(",");
	TulisPOINT(PAkhir(L));
	printf(")");
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
/* Menghitung panjang garis L :  sqrt((selisih absis titik awal dan akhir)^2 + (selisih ordinat titik awal dan akhir)^2)*/
/* dapat menggunakan primitif Panjang point, tapi ini untuk menunjukkan implementasinya */
	
	/* KAMUS LOKAL */
	float dx, dy;
	
	/* ALGORITMA */
	dx = Absis(PAkhir(L)) - Absis(PAwal(L));
	dy = Ordinat(PAkhir(L)) - Ordinat(PAwal(L));
	return sqrt(dx*dx + dy*dy);
}

float Gradien (GARIS L){
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
	
	/* KAMUS LOKAL */
	float dy, dx;
	
	/* ALGORITMA */
	dy = Ordinat(PAkhir(L)) - Ordinat(PAwal(L));
	dx = Absis(PAkhir(L)) - Absis(PAwal(L));
	return dy/dx;
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	Geser(&PAwal(*L), deltaX, deltaY);
	Geser(&PAkhir(*L), deltaX, deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2){
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (Gradien(L1) == Gradien(L2));
}

