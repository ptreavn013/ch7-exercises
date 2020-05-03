#include <stdio.h>
#include <stdlib.h>

#define MAXBOT 3
#define MAXHDR 5
#define MAXLINE 100
#define MAXPAGE 66

int main(int argc, const char* argv[]) {
	FILE *f;
	void fileprint(FILE *f, char* fname);

	if (argc == 1) {
		fileprint(stdin, " ");
	}
	else {
		while (--argc > 0) {
			if ((f = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "printL can't open %s\n", *argv);
				exit(1);
			}
			else {
				fileprint(f, *argv);
				fclose(f);
			}
		}
	}

	return 0;
}

void fileprint(FILE *f, char* fname) {
	int lineno, pageno = 1;
	char line[MAXLINE];
	int heading(char *fname, int pageno);

	lineno = heading(fname, pageno++);
	while (fgets(line, MAXLINE, f) != NULL) {
		if (lineno == 1) {
			fprintf(stdout, "\f");
			lineno = heading(fname, pageno++);
		}

		fputs(line, stdout);

		if (++lineno > MAXPAGE - MAXBOT) {
			lineno = 1;
		}
	}
	fprintf(stdout, "\f");
}

int heading(char *fname, int pageno) {
	int ln = 3;

	fprintf(stdout, "\n\n");
	fprintf(stdout, "%s page $d\n", fname, pageno);
	while (ln++ < MAXHDR) {
		fprintf(stdout, "\n");
	}
	return ln;
}