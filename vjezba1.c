#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	char ime[15];
	char prezime[20];
	int bod;

}podaci;

int main()
{
	int br, i = 0;
	podaci *niz;
	float *rel_br;
	FILE *fp = fopen("dat.txt", "r");

	niz = (podaci*)malloc(sizeof(podaci));
	rel_br = (float *)malloc(sizeof(float));

	while (getc(fp) != '\n')
		continue;

	while (!feof(fp))
	{
		fscanf(fp, "%s", niz[i].ime);
		fscanf(fp, "%s", niz[i].prezime);
		fscanf(fp, "%d", &niz[i].bod);

		niz = (podaci*)realloc(niz, (i + 2) * sizeof(podaci));

		i++;

	}

	rel_br = (float*)malloc(i * sizeof(float));

	for (br = 0; br < i; br++)
		rel_br[br] = (float)niz[br].bod / 70 * 100;


	printf("IME\tPREZIME\tAPSOLUTNI BR. BODOVA\tRELATIVNI BR. BODOVA\n");
	for (br = 0; br < i; br++)
		printf("%s\t%s\t%d\t              %f\n", niz[br].ime, niz[br].prezime, niz[br].bod, rel_br[br]);


	return 0;
}


