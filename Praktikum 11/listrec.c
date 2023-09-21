// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 16 November 2022
// Topik: ADT List Rekursif
// Deskripsi: Pra-praktikum listrec.c

#include "boolean.h"
#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

/* Manajemen Memori */
Address newNode(ElType x){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

	/* KAMUS LOKAL */
	Address p;

	/* ALGORITMA */
	p = (Address) malloc(sizeof(Node));
	if(p != NIL){
		INFO(p) = x;
		NEXT(p) = NIL;
	}
	return p;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */

	/* KAMUS LOKAL */

	/* ALGORITMA */
	return (l == NIL);
}

boolean isOneElmt(List l){
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if(!isEmpty(l)){
		return NEXT(l) == NIL;
	}
	else{
		return false;
	}
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return INFO(l);
}

List tail(List l){
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return NEXT(l);
}

List konso(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
   
	/* KAMUS LOKAL */
	Address new;
	
	/* ALGORITMA */
	new = newNode(e);
	if(new != NIL){
		NEXT(new) = l;
		return new;
	}
	else{
		return l;
	}
}

List konsb(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 

	/* KAMUS LOKAL */
	Address new;
	
	/* ALGORITMA */
	if(isEmpty(l)){	/* BASIS */
		new = newNode(e);
		return new;
	}
	else{	/* REKURENS */
		NEXT(l) = konsb(tail(l), e);
		return l;
	}
}

List copy(List l){
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 

	/* KAMUS LOKAL */
	List cplist;
	
	/* ALGORITMA */
	if(isEmpty(l)){	/* BASIS */
		return NIL;
	}
	else{	/* REKURENS */
		return konso(copy(tail(l)), head(l));
	}
}

List concat(List l1, List l2){
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if(isEmpty(l1) && isEmpty(l2)){	/* BASIS */
		return NIL;
	}
	else if(isEmpty(l1)){	/* REKURENS */
		return konso(concat(l1, tail(l2)), head(l2));
	}
	else{
		return konso(concat(tail(l1), l2), head(l1));
	}
}

/* Fungsi dan Prosedur Lain */
int length(List l){
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if(isEmpty(l)){	/* BASIS */
		return 0;
	}
	else{
		return 1 + length(tail(l));
	}
}

boolean isMember(List l, ElType x){
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if(isEmpty(l)){	/* BASIS */
		return false;
	}
	else if(x == head(l)){
		return true;
	}
	else{	/* REKURENS */
		return isMember(tail(l), x);
	}
}

void displayList(List l){
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if(!isEmpty(l)){
		printf("%d\n", head(l));
		displayList(tail(l));
	}
	/* else -> do nothing */
}
