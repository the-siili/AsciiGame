#include <stdio.h>
#include <stdlib.h>

const int H = 10;
const int W = 20;

typedef struct{
	char** matrix;
	int height;
	int width;
} Mat2;

Mat2* NewMat2(int height, int width) {
  	
	Mat2* mat2 = malloc(sizeof(Mat2));

	char** newMat = (char**)malloc(height * (sizeof(char*)));

	for(int i = 0; i < height; ++i){
		newMat[i] = (char*)malloc(width * (sizeof(char)));
		for(int j = 0; j < width; ++j){
			newMat[i][j] = 'H';
		}
	}
	
	mat2->matrix = newMat;
  	mat2->height = height;
  	mat2->width = width;

	return mat2;
}



int main(){

	Mat2* pMat = NewMat2(30, 30);


	Mat2 mat = *pMat;
	for(int i = 0; i < mat.height; ++i){
		for(int j = 0; j < mat.width; ++j){
			printf("%c", mat.matrix[i][j]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}