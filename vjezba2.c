#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*2. Definirati strukturu osoba (ime, prezime, godina roðenja) i napisati program koji:
a) dinamièki dodaje novi element na poèetak liste,
b) ispisuje listu,
c) dinamièki dodaje novi element na kraj liste,
d) pronalazi element u listi (po prezimenu),
e) briše odreðeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.*/

typedef struct osoba *pozicija;
struct osoba {
	char ime[64];
	char prez[64];
	int god;
	pozicija next;
};
void UnosP(pozicija);
void IspisP(pozicija);
void unosk(pozicija);
pozicija nadi(pozicija);
void brisi(pozicija);
pozicija trazipret(pozicija);

int main(void)
{
	struct osoba head, *t;
	head.next = NULL;


	printf("Postovani korisnice, unesite podatke osoba koje zelite\n");
	UnosP(&head);
	UnosP(&head);
	UnosP(&head);
	UnosP(&head);

	printf("ISPIS OSOBA\n");
	IspisP(&head);

	printf("Unesite podatke nove osobe koju cemo postaviti na kraj liste\n");
	unosk(&head);

	printf("ISPIS LISTE\n");
	IspisP(&head);

	printf("Slijedi trazenje odredene osobe u listi\n");
	t = nadi(&head);
	printf("Njezini podaci su:\n");
	printf("%s %s %d \n", t->ime, t->prez, t->god);

	printf("Slijedi brisanje odredene osobe na listi\n");
	brisi(&head);

	printf("ISPIS LISTE NAKON BRISANJA\n");
	IspisP(&head);

	
	

	return 0;
}


void UnosP(pozicija P)
{
	pozicija g;
	g = (pozicija)malloc(sizeof(struct osoba));
	
	printf("IME PREZIME GOD ROD\n");
	scanf("%s %s %d", g->ime, g->prez, &g->god);

	g->next = P->next;
	P->next = g;

	return;
}
void IspisP(pozicija P)
{
	P = P->next;
	while (P != NULL) {
		printf("%s\t%s\t%d\n", P->ime, P->prez, P->god);
		P = P->next;
	}

	return;
}

void unosk(pozicija P)
{
	pozicija g;
	g = (pozicija)malloc(sizeof(struct osoba));
	printf("IME PREZIME GOD ROD\n");
	scanf("%s %s %d", g->ime, g->prez, &g->god);

	while (P->next != NULL)
		P = P->next;

	g->next = P->next;
	P->next = g;

	return;
}
pozicija nadi(pozicija P)
{
	char prez[50];
	P = P->next;
	printf("Koju osobu zelite pronaci(upisite njeno prezime)?\n");
	scanf(" %s", prez);

	while((P!=NULL)&&(strcmp(P->prez, prez)!=0))
	{
		P = P->next;
	}

	return P;
}
pozicija trazipret(pozicija p)
{
	pozicija pret;
	char prez[50];
	pret = p;
	p = p->next;

	printf("Unesite prezime osobe\n");
	scanf(" %s", prez);

	while (p != NULL && (strcmp(p->prez, prez)!=0))
	{
		pret = p;
		p = p->next;
	}
   
	 return pret;




}



void brisi(pozicija p)
{
	pozicija temp;
	printf("Unijet cete prezime osobe koju zelite izbrisati\n");
	p = trazipret(p);

	temp = p->next;
	p->next = p->next->next;
	free(temp);




}
