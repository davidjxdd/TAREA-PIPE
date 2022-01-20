#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd, sz;
	char *archivo = "archivo.txt";

	fd = open(archivo, O_WRONLY | O_TRUNC | O_CREAT);

	// All the printf statements will be written in the file

	srand(time(NULL));
	int s = rand() % 1000;
	char t[20];

	sprintf(t, "%d", s);
	sz = write(fd, t, sizeof(t));
	printf("El numero generado es: %d and %s\n", s, t);
	close(fd);

return 0;
}

