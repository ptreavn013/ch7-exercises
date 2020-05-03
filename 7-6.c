#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, const char* argv[]) {
	FILE *f1, *f2;
	void filecomp(FILE *f1, FILE *f2);

	if (argc != 3) {
		fprintf(stderr, "comp: need two file names\n");
		exit(1);
	}
	else  {
		if ((f1 = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "comp: can't open %s\n", *argv);
			exit(1);
		}
		else if ((f2 = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "comp: can't open %s\n", *argv);
			exit(1);
		}
		else {
			filecomp(f1, f2);
			fclose(f1);
			fclose(f2);
			exit(0);
		}
	}
}

void filecomp(FILE *f1, FILE *f2) {
	char line1[MAX], line2[MAX];
	char *lp1, *lp2;

	do {
		lp1 = fgets(line1, MAX, f1);
		lp2 = fgets(line2, MAX, f2);

		if (lp1 == line1 && lp2 == line2) {
			if (strcmp(line1, line2) != 0) {
				printf("first difference in line\n%s\n", line1);
				lp1 = lp2 = NULL;
			}
		}
		else if (lp1 != line1 && lp2 == line2) {
			printf("end of first file at line\n%s\n", line2);
		}
		else if (lp1 == line1 && lp2 != line 2) {
			printf("end of second file at line\n%s\n", line1);
		}
	} while (lp1 == line1 && lp2 == line2);
}