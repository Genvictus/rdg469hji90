// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 7 September 2022
// Topik: ADT Sederhana
// Deskripsi: Pra-Praktikum point.c

/* File: point.c */
/* Tanggal: 7 September 2022 */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	
	/* KAMUS LOKAL */
	
	Absis(*P) = X;
	Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	
	/* KAMUS LOKAL */
	float X, Y;
	
	scanf("%f %f", &X, &Y);
	CreatePoint (P, X, Y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
	
	/* KAMUS LOKAL */
	
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	
	/* KAMUS LOKAL */
	
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	
	/* KAMUS LOKAL */
	
	return (!EQ(P1, P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */

	/* KAMUS LOKAL */
	
	return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	
	/* KAMUS LOKAL */
	
	return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	
	/* KAMUS LOKAL */
	
	return (Absis(P) == 0);
}

int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
	
	/* KAMUS LOKAL */
	
	if (Absis(P) > 0 && Ordinat(P) > 0)
    {
        return 1;
    }
    else if (Absis(P) < 0 && Ordinat(P) > 0)
    {
        return 2;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0)
    {
        return 3;
    }
    else if (P.X > 0 && Ordinat(P) < 0)
    {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
	
	/* KAMUS LOKAL */
	
	Absis(P) += 1;
	return P;
}

POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	
	/* KAMUS LOKAL */
	
	Ordinat(P) += 1;
	return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
	
	/* KAMUS LOKAL */
	
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return P;
}

POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
	
	/* KAMUS LOKAL */
	
	if(SbX)
		Ordinat(P) = -Ordinat(P);
	else
		Absis(P) = -Absis(P);
	
	return P;
}

float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
	
	/* KAMUS LOKAL */
	
	return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2){
/* Menghitung jarak P1 dan P2 */
	
	/* KAMUS LOKAL */
	float dx, dy;
	
	dx = Absis(P1) - Absis(P2);
	dy = Ordinat(P1) - Ordinat(P2);
	return sqrt(dx*dx + dy*dy);
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
	
	/* KAMUS LOKAL */
	
	Absis(*P) += deltaX;
	Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
	
	/* KAMUS LOKAL */
	
	Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
	
	/* KAMUS LOKAL */
	
	Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
	
	/* KAMUS LOKAL */
	
	if (SbX)
		Ordinat(*P) = -Ordinat(*P);
	else
		Absis(*P) = -Absis(*P);
}

void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
	
	/* KAMUS LOKAL */
	const float PI = 3.1415926535897932384626;
	float X,Y;
	
	Sudut = Sudut/180 * PI; //ubah sudut dari derajat ke radian
	X = cos(Sudut) * Absis(*P) - sin(Sudut) * (Ordinat(*P));
    Y = sin(Sudut) * Absis(*P) + cos(Sudut) * (Ordinat(*P));
	
	Absis(*P) = X;
	Ordinat(*P) = Y;
}


