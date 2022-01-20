#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define READ  0
#define WRITE 1

int main() {

	pid_t pid;
	int fd[2];
	char *args1[] = {"./numcompare", NULL};
	char *args2[] = {"./numgener", NULL};

	if (pipe(fd) == -1) {
		perror("Creating pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid == 0) {

		// The child process will execute numcompare program.
		// Close the pipe write descriptor.
		close(fd[WRITE]);
		// Redirect STDIN to read from the pipe.
		dup2(fd[READ], STDIN_FILENO);
		// Execute num compare
		execvp(args1[0], args1);
		// printf("Soy el hijo \n");
	}

	else if (pid < 0) {
		perror("fork() failed)");
		exit(EXIT_FAILURE);
	}

	else {
		// The parent process will execute numgener program.
		// Close the pipe read descriptor.
		close(fd[READ]);
		// Redirect STDOUT to write to the pipe.
		dup2(fd[WRITE], STDOUT_FILENO);
		// Execute randomnum generator
		execvp(args2[0], args2);
	}

}
