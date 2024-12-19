#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#include "modules/Camera.h"
#include "modules/generic/Matrix.h"
#include "modules/generic/strfuncs.h"
#include "modules/Input.h"

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_F8 66

int KB_code=0;

Camera* currentCamera;


void Render(Mat2 *pWorld, Camera *pCam) {

	Camera cam = *pCam;
	Mat2 world = *pWorld;
    
    char output[(cam.w * cam.h)];

	for (int i = cam.y; i < cam.y + cam.h; ++i) {

		for (int j = cam.x; j < cam.x + cam.w; ++j) {
            
            if(j + cam.w > world.width || j < 0 || i + cam.h > world.height ||i < 0){
                
                //printf("%c", ' ');
                addChar(output, ' ');
            }
            else{
			    //printf("%c", world.matrix[i][j]);
                addChar(output, world.matrix[i][j]);
            }
		}
		//printf("\n");
        addChar(output, '\n');
	}

    printf("%s", output);
}

bool isOpen = true;

void MoveCamera()
{

    if(GetKey(KB_LEFT))
        currentCamera->x -= 1;
    if(GetKey(KB_RIGHT))    
        currentCamera->x += 1;
    if(GetKey(KB_UP))
        currentCamera->y -= 1;                   
    if(GetKey(KB_DOWN))
        currentCamera->y += 1;

}


void Update(){
    MoveCamera();
    if(GetKey(KB_ESCAPE))
        isOpen = false;
}

int main(void)
{	
	Mat2* pWorld = NewMat2(100, 100);
	Camera* mainCamera = NewCamera(0, 0, 15, 15);
    currentCamera = mainCamera;
    
	while (isOpen) {
        Update();

        system("cls");
        Render(pWorld, mainCamera);
        Sleep(1);
	}
}