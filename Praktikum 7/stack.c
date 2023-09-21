// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 19 Oktober 2022
// Topik: ADT Stack
// Deskripsi: Pra-praktikum stack.c

/* File : stack.c */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "stack.h"
#include "boolean.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */


/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return Top(S) == Nil;
}

boolean IsFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return Top(S) == MaxEl-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
    if(Top(*S) == Nil){
        Top(*S) = 0;
    }
    else{
        Top(*S)++;
    }
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
    *X = InfoTop(*S);
    if(Top(*S) == 0){
        Top(*S) = Nil;
    }
    else{
        Top(*S)--;
    }
}
