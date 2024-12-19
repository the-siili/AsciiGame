#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <unistd.h> // For usleep

#define TARGET_FPS 60
#define FRAME_TIME (1.0 / TARGET_FPS)  


#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_F8 66

int KB_code=0;



double get_current_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;  // Time in seconds
}




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
            int r = rand() % 2;
			newMat[i][j] = "HA"[r];
		}
	}
	
	mat2->matrix = newMat;
  	mat2->height = height;
  	mat2->width = width;

	return mat2;
}





typedef struct{
	int x;
	int y;
	int w;
	int h;
} Camera;


Camera* NewCamera(int x, int y, int w, int h) { 
  Camera* cam = malloc(sizeof(Camera));
  cam->x = x;
  cam->y = y;
  cam->w = w;
  cam->h = h;
  return cam;
}


void addChar(char *s, char c) {

      // Move pointer to the end
    while (*s++);
  
    // Append the new character
    *(s - 1) = c;
  
    // Add null terminator to mark new end
    *s = '\0';
}

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


void simple_keyboard_input( Camera* pCam)
{
    if (kbhit())
      {
            KB_code = getch();
            //cout<<"KB_code = "<<KB_code<<"\n";

            switch (KB_code)
            {

                case KB_LEFT:
                           //Do something
                    pCam->x -= 1;
                break;

                case KB_RIGHT:
                           //Do something     
                    pCam->x += 1;
                break;

                case KB_UP:
                    pCam->y -= 1;                   
                break;

                case KB_DOWN:
                    pCam->y += 1;
                break;

            }        

      }

}

int main(void)
{	
	Mat2* pWorld = NewMat2(100, 100);
	Camera* mainCamera = NewCamera(0, 0, 15, 15);

    double previous_time = get_current_time();
    double delta_time;


	while (true) {
        double current_time = get_current_time();
        delta_time = current_time - previous_time;

        //printf("\033[2J"); // Clear the screen once at the start
        //printf("\033[?25l"); // Hide the cursor

        if (delta_time >= FRAME_TIME) {
            // Update previous time
            previous_time = current_time;

            
            simple_keyboard_input(mainCamera);

            system("cls");
            Render(pWorld, mainCamera);

            // Calculate how long we need to sleep to maintain 60 FPS
            double sleep_time = FRAME_TIME - (get_current_time() - previous_time);
            if (sleep_time > 0) {
                usleep(sleep_time * 1e6);  // Convert seconds to microseconds
            }
            
        }

	}
}