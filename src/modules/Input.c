#include "Input.h"
#include <stdbool.h>
#include <conio.h>

bool GetKey(int keycode){
    if (kbhit()){
        int pressedKey = getch();
        if(keycode == pressedKey){
            return true;
        }
    }
    return false;
}