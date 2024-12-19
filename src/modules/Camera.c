#include "Camera.h"
#include <stdlib.h>


Camera* NewCamera(int x, int y, int w, int h) { 
  Camera* cam = malloc(sizeof(Camera));
  cam->x = x;
  cam->y = y;
  cam->w = w;
  cam->h = h;
  return cam;
}