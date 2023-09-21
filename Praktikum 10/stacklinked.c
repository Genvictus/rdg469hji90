// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 9 November 2022
// Topik: Queue dan Stack dengan struktur berkait
// Deskripsi: Pra-praktikum stacklinked.c

/* File: stacklinked.c */

#include "boolean.h"
#include "stacklinked.h"
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

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s){
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (TOP(s) == NIL);
}

int length(Stack s){
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

	/* KAMUS LOKAL */
    Address p;
    int len;
	
	/* ALGORITMA */
	p = ADDR_TOP(s);
    len = 0;
    while(p != NIL){
        p = NEXT(p);
        len++;
    }
    /* p == NIL */
    return len;
}

void CreateStack(Stack *s){
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s){
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	printf("[");
    if(!isEmpty(s)){
        p = ADDR_TOP(s);
        for(;;){
            printf("%d", INFO(p));
            p = NEXT(p);

            if(p == NIL) break;
            
            printf(",");
        }
    }
    printf("]");
}

void push(Stack *s, ElType x){
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

	/* KAMUS LOKAL */
	Address new;

	/* ALGORITMA */
    new = newNode(x);
    if(new != NIL){
        NEXT(new) = ADDR_TOP(*s);
        ADDR_TOP(*s) = new;
    }
}

void pop(Stack *s, ElType *x){
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	*x = TOP(*s);
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    free(p);
}
