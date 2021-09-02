#include "gameobject.hpp"
#include "texturemanager.hpp"
#include <pspctrl.h>
#include "game.hpp"

TextureManager texture;
SceCtrlData ctrldata;
Game maingame;


gameObject::gameObject(char* texturesheet, float x, float y, int w, int h, int Type) {
    if (texturesheet == NULL) {
        objTexture = TextureManager::loadTexture("assets/ricardo.png");
    }
    else {
        objTexture = TextureManager::loadTexture(texturesheet);
    }
    
	xpos = x;
	ypos = y;
	width = w;
	height = h;
    type = Type;
    xoud = x;
    youd = y;
}

void gameObject::update() {
	switch (type) {
        case 0:
            //player
            sceCtrlReadBufferPositive(&ctrldata, 1);

                xoud = xpos;
                youd = ypos;
        

                if (ctrldata.Buttons & PSP_CTRL_UP) { 
                    ypos -= 1;
                }

                if (ctrldata.Buttons & PSP_CTRL_DOWN) {
                    ypos += 1;
                }

                if (ctrldata.Buttons & PSP_CTRL_RIGHT) {                  
                    xpos += 1;
                }

                if (ctrldata.Buttons & PSP_CTRL_LEFT) {                   
                    xpos -= 1; 
                }

               
               
        break;
        case 1:
            //heen en weer bewegende enemy
            if (movestate) {
                if (xpos <= min) {
                    movestate = false;
                }
                xpos--;
            }
            else if (!movestate) {
                if (xpos >= max) {
                    movestate = true;
                }
                xpos++;
            }
        break;
        case 2:
            //omhoog en omlaag bewegende enemy
            if (movestate) {
                if (ypos <= min) {
                    movestate = false;
                }
                ypos--;
            }
            else if (!movestate) {
                if (ypos >= max) {
                    movestate = true;
                }
                ypos++;
            }
        break;
    }
}

void gameObject::render() {
	
    
        texture.drawTexture(xpos, ypos, width, height, objTexture);

}