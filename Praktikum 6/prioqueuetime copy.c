// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 6 Oktober 2022
// Topik: ADT Queue
// Deskripsi: Praktikum prioqueuetime.c

/* File : prioqueue.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "prioqueuetime.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */

    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull (PrioQueueTime Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    return ((Tail(Q) % MaxEl(Q)) + 1) == Head(Q);
}

int NBElmt (PrioQueueTime Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

    /* KAMUS LOKAL */
    int l;
    
    /* ALGORITMA */
    if((Head(Q) == Nil) && (Tail(Q) == Nil)){
        l = 0;
    }
    else{
        if(Head(Q) <= Tail(Q)){
            l = Tail(Q) - Head(Q) + 1;
        }
        else {
            l = MaxEl(Q) - Head(Q) + (Tail(Q) + 1);
        }
    }
    return l;
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    (*Q).T = (infotype*) malloc((Max+1) * sizeof(infotype));
    MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    free((*Q).T);
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

    /* KAMUS LOKAL */
    int i;
    int m;

    /* ALGORITMA */
    m = MaxEl(*Q);

    if(IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        Elmt(*Q, Tail(*Q)) = X;
    }
    else{
        i = Tail(*Q);
        while(i != Head(*Q) && (Time(X) < Time(Elmt(*Q,i)))){
            Elmt(*Q, ((i % m) + 1)) = Elmt(*Q, i);
            i = (((i-2+m) % m) + 1);
        }
        // i == Head ATAU (Time(X) >= Time(Elmt(*Q,i))) <- tempat yang tepat
        if((Time(X) < Time(Elmt(*Q,i)))){
            Elmt(*Q, ((i % m) + 1)) = Elmt(*Q, i);
            Elmt(*Q, i) = X;
        }
        else {
            Elmt(*Q, ((i % m) + 1)) = X;
        }
        Tail(*Q) = ((Tail(*Q) % m) + 1);
    }
}

void Dequeue (PrioQueueTime * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

    
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    i = Head(Q);
    while(i != Tail(Q)){
        printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
        i = (i % MaxEl(Q)) + 1;
    }
    printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
    printf("#\n");
}

