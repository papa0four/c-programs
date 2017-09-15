#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#define MERGE(str1, str2) str1##str2
#define HAS_RANK(p, hR) strcpy(MERGE(p,.thePersonsRank), #hR);
#define LAST_NAME(p, lN) strcpy(MERGE(p,.thePersonsLastName), #lN);
#define DOD_ID(p, n) p##.thePersonsDodIdNum = n;
#define CONSTANT_BUFF(p, n) p##.theBufferSize = n;

struct PeopleAtDetTx
{
	char thePersonsRank[10];
	char thePersonsLastName[50];
	int thePersonsDodIdNum;
	int theBuffSize[64];
};

int main()
{
	struct PeopleAtDetTx Sabs; 
	HAS_RANK(Sabs, SGT);
	LAST_NAME(Sabs, Sabatini);
	DOD_ID(Sabs, 1234567890);

	puts(MERGE(HAS_RANK(Sabs, SGT), LAST_NAME(Sabs, Sabatini)));

	return 0;
}