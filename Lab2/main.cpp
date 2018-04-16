#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
using namespace std;

long i=0;
void memLeak() {
	char *ptr= (char *)malloc(64000);
	strcpy(ptr, "teste");
	printf("%i\n",i++);
	free(ptr); 

	printf("%s\n",ptr);
	
}

long stackover(long x) {
	printf("%i\n",i++);
	return stackover(x);
}

int main(int argc, char** argv) {
	//for(int i=0;i<1000000;i++)
	//	memLeak();
	stackover(1);
	return 0;
}
