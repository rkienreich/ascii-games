#include <stdio.h>
#include <locale.h>
#include <unistd.h>

#define KA 9632

int main()
{
	setlocale(LC_ALL,"");
	int i;
	int bar[10];
	
	// initialisiere bar mit Leerzeichen
	for (i= 0; i < sizeof(bar) -1 ; i++)
		bar[i] = ' ';
	bar[sizeof(bar) - 1] = '\0';
	
	for (i = 0; i < sizeof(bar) - 1; i++) {
			bar[i] = KA;
			fflush(stdout);
			printf("\r%ls", bar);
			sleep(1);
	}
		
	printf("\n");
	return 0;
}

