#include <stdio.h>

void inverte(int n, int *vec) {
	int *end = vec + n;
	for (int k = 0; k < n/2; k++) {
		int tmp = *vec;
		int *mirror = end - k - 1;
		*vec = *mirror;
		*mirror = tmp;
		vec++;
	}	
}

void inverte2d(int r, int c, int vec[r][c]) {
	for (int i = 0; i < r; i++) {
		int* pnt = &vec[0][0] + i*c;
		int* end = pnt +c -1;
		while (pnt < end) {
			int tmp = *pnt;
			*pnt = *end;
			*end = tmp;

			end--;
			pnt++;
		}
	}	
}



int main() {
	int vec[10] = {0,1,2,3,4,5,6,7,8,9};
	//inverte(10, vec);

	int matrix[3][3] = {
		{0,1,2},
		{3,4,5},
		{7,8,9}
	};

	inverte2d(3, 3, matrix);

	for (int k = 0; k < 3; k++) {
		for (int t = 0; t < 3; t++) {
			printf("%d", matrix[k][t]);
		}
		printf("\n");
	}
	printf("\n");

	int *pnt = &matrix[0][0];
	printf("%d", (pnt == matrix[0]));

	return 0;
}
