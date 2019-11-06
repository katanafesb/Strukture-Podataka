#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct osoba *pozicija;
struct osoba {
	char ime[64];
	char prez[64];
	int god;
	pozicija next;
};
int UnosP(pozicija);
int IspisP(pozicija);
int unosk(pozicija);
pozicija nadi(pozicija);
int brisi(pozicija);
pozicija trazipret(pozicija);
int unosiza(pozicija);
int unosispred(pozicija);
int sort(pozicija);
int unos_u_dat(pozicija);
int ispis_iz_datoteke(pozicija);

int main(void)
{
	struct osoba head, head1, *t;
	head.next = NULL;
	head1.next = NULL;


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

	printf("Unijet cete prezime osobe iza koje zelite unijeti novu\n");
	unosiza(&head);
	IspisP(&head);

	printf("Unijet cete prezime osobe ispred koje zelite unijeti novu\n");
	unosispred(&head);
	IspisP(&head);

	printf("sortirana lista\n");
	sort(&head);
	IspisP(&head);

	printf("Unos u datoteku\n");
	unos_u_dat(&head);

	printf("Ispis iz datoteke u novu listu\n");
	ispis_iz_datoteke(&head1);
	IspisP(&head1);

	printf("Slijedi brisanje odredene osobe na listi\n");
	brisi(&head);

	printf("ISPIS LISTE NAKON BRISANJA\n");
	IspisP(&head);



	//system("PAUSE>1");
	return 0;
}


int UnosP(pozicija P)
{
	pozicija g;
	g = (pozicija)malloc(sizeof(struct osoba));

	printf("IME PREZIME GOD ROD\n");
	scanf("%s %s %d", g->ime, g->prez, &g->god);

	g->next = P->next;
	P->next = g;

	return 0;
}
int IspisP(pozicija P)
{
	P = P->next;
	while (P != NULL) {
		printf("%s\t%s\t%d\n", P->ime, P->prez, P->god);
		P = P->next;
	}

	return 0;
}

int unosk(pozicija P)
{
	pozicija g;
	g = (pozicija)malloc(sizeof(struct osoba));
	printf("IME PREZIME GOD ROD\n");
	scanf("%s %s %d", g->ime, g->prez, &g->god);

	while (P->next != NULL)
		P = P->next;

	g->next = P->next;
	P->next = g;

	return 0;
}
pozicija nadi(pozicija P)
{
	char prez[50];
	P = P->next;
	printf("Koju osobu zelite pronaci(upisite njeno prezime)?\n");
	scanf(" %s", prez);

	while ((P != NULL) && (strcmp(P->prez, prez) != 0))
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

	while (p != NULL && (strcmp(p->prez, prez) != 0))
	{
		pret = p;
		p = p->next;
	}

	return pret;




}
int unosiza(pozicija p)
{
	p = nadi(p);
	printf("Unesite novi element\n");


	UnosP(p);

	return 0;
}
int unosispred(pozicija p)
{
	p = trazipret(p);

	printf("Unesite novi element\n");
	UnosP(p);

	return 0;
}

int sort(pozicija p)
{
	pozicija prev_j, j, end, temp;
	end = NULL;

	while (p->next != end)
	{
		prev_j = p;
		j = p->next;
		while (j->next != end)
		{
			if (strcmp(j->prez, j->next->prez) > 0)
			{
				temp = j->next;
				prev_j->next = temp;
				j->next = temp->next;
				temp->next = j;

				j = temp;
			}
			prev_j = j;
			j = j->next;

		}
		end = j;
	}

	return 0;
}

int unos_u_dat(pozicija p)
{
	p = p->next;
	FILE *fp;
	fp = fopen("datoteka3.txt", "w");
	if (fp == NULL){
		printf("greska pri otvaranju datoteke\n");
		return;
	}
		
	else
	{
		while (p!= NULL)
		{
			fprintf(fp, "%s %s %d\n", p->ime, p->prez, p->god);
			p = p->next;
		}
	}

	fclose(fp);

	return 0;
}
pozicija napravi_novu(pozicija p)
{
	pozicija g;
	g = (pozicija)malloc(sizeof(struct osoba));
	if(g==NULL)
	{
		printf("Neuspjesno alocirana memorija\n");
		return;
	}
	g->next = p->next;
	p->next = g;

	return g;


}


int ispis_iz_datoteke(pozicija p)
{
	pozicija g;
	FILE *fp = fopen("datoteka3.txt", "r");
	if (fp == NULL){
		printf("greska pri otvaranju datoteke\n");
		return;
	}
	while (!feof(fp))
	{
		g = napravi_novu(p);
		fscanf(fp, " %s %s %d", g->ime, g->prez, &g->god);
		printf("%s %s %d\n", g->ime, g->prez, g->god);


	}

	fclose(fp);

	return 0;
}




int brisi(pozicija p)
{
	pozicija temp;
	printf("Unijet cete prezime osobe koju zelite izbrisati\n");
	p = trazipret(p);

	temp = p->next;
	p->next = p->next->next;
	free(temp);


	return 0;

}

