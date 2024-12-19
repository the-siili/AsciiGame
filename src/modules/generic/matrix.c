#include <stdlib.h>
#include "matrix.h"


Mat2* NewMat2(int height, int width) {
  	
	Mat2* mat2 = malloc(sizeof(Mat2));

	char** newMat = (char**)malloc(height * (sizeof(char*)));

	for(int i = 0; i < height; ++i){

        
		newMat[i] = (char*)malloc(width * (sizeof(char)));
		for(int j = 0; j < width; ++j){
            int r = rand() % 2;
			newMat[i][j] = "HA"[r];
		}
	}
	
	mat2->matrix = newMat;
  	mat2->height = height;
  	mat2->width = width;

	return mat2;
}


