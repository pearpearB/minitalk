#include <stdio.h>

int main(int argc, char **argv){
	unsigned char *str = (unsigned char *)argv[1];

	for (int i = 0; str[i]; i++)
		printf("%d\n", str[i]);

	return 0;
}