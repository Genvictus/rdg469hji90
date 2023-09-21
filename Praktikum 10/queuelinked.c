// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 9 November 2022
// Topik: Queue dan Stack dengan struktur berkait
// Deskripsi: Pra-praktikum queuelinked.c

/* File: queuelinked.c */

#include "boolean.h"
#include "queuelinked.h"
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x){
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (ADDR_HEAD(q) == NIL);
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

	/* KAMUS LOKAL */
    Address p;
    int len;
	
	/* ALGORITMA */
	p = ADDR_HEAD(q);
    len = 0;
    while(p != NIL){
        p = NEXT(p);
        len++;
    }
    /* p == NIL */
    return len;
}

/*** Kreator ***/
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q){
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	printf("[");
    if(!isEmpty(q)){
        p = ADDR_HEAD(q);
        for(;;){
            printf("%d", INFO(p));
            p = NEXT(p);

            if(p == NIL) break;
            
            printf(",");
        }
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */

	/* KAMUS LOKAL */
    Address p, new;
	
	/* ALGORITMA */
	new = newNode(x);
    if(new != NIL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q) = new;
        }
        else {
            NEXT(ADDR_TAIL(*q)) = new;
        }
        ADDR_TAIL(*q) = new;
    }
}

void dequeue(Queue *q, ElType *x){
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	*x = HEAD(*q);
    p = ADDR_HEAD(*q);
    if(ADDR_HEAD(*q) == ADDR_TAIL(*q)){
        ADDR_TAIL(*q) = NIL;
    }
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    free(p);
}
