#include <stdio.h>

int reduce(int r, int c, float in[r][c], int r1, int c1, float out[r1][c1])
{
	int y_cur = 0;  // cursor de y da matriz saida
	float *pntin = &in[0][0]; // ponteiro da entrada
	float *pntout = &out[0][0]; // ponteiro da saida
	while (y_cur < r1) {
		int x_cur = 0; // cursor de da matriz saida
		while (x_cur < c1) {
			float sum = 0.0f; //acumulador da soma
			
			float *bloco = pntin + (2*y_cur) * c + (2 * x_cur); //posição da mini matriz da entrada

			sum += *bloco; // bloco[0,0]
			sum += *(bloco + 1); // bloco [0,1]
			sum += *(bloco + c); // bloco [1,0]
			sum += *(bloco + c + 1); // bloco [1,1]

			*(pntout + y_cur * c1 + x_cur) = sum / 4.0f; //adiciona a media da soma na posição da matriz

			x_cur++;
		}
		y_cur++;
	}
	return 1;
}

int main() {
	float v[4][6] = { {  3,  2,  3,  6,  5,  3 },
                      {  7,  8,  9, 10,  1, 12 },
                      { 13, 14, 11, 16, 17, 18 },
                      { 19, 20, 21, 22,  1, 24 } };
    	float res[4/2][6/2];
	
	if (reduce(4, 6, v, 4/2, 6/2, res)) {
        	for (int i = 0; i < 2; i++) {
        	    for (int j = 0; j < 3; j++) {
                		printf("%.2f ", res[i][j]);
            		}
		    printf("\n");
        	}
    	} else {
        	printf("Falha na redução\n");
    	}
}
