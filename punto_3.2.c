#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_BUF 1024

int main() {

	int fd;
	char *archivo = "archivo.txt";
	char buf[MAX_BUF];

	fd = open(archivo, O_RDONLY);
	read(fd, buf, MAX_BUF);
	printf("c = %s\n", buf);
	close(fd);


	int a = atoi(buf);
	if(a >= 500 && a <= 1000){
		printf("%d es mayor o igual a 500\n", a);

	}

	else if(a < 500 && a >= 0){
		printf("%d es menor que 500\n", a);
	}

	else {
		perror("Numero fuera de rango\n");
		exit(2);
	}

return 0;

}
