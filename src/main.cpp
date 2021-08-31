#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "glib2d.h"
#include <stdlib.h>
#include "texturemanager.hpp"
#include "collision.hpp"
#include "gameobject.hpp"


float x = 0, y = 126;
float xoud = x;
float youd = y;
bool playing = true;
int level = 0;
//TextureManager texture;
//Collision collision;
gameObject* player;
gameObject* ball1;
gameObject* ball2;


PSP_MODULE_INFO("world-hardest-game", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

//stops the game.
//this is just code that works, so dont change this. (upcoming 3 functions)
int exit_callback(int arg1, int arg2, void *common) {
    sceKernelExitGame();
    return 0;
}


int callbackthread(SceSize args, void *argp) {
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}


void setupcallbacks () {
    int thid = sceKernelCreateThread("update_thread", callbackthread, 0x11, 0xfa0, 0, NULL);
    if (thid >= 0) {
        sceKernelStartThread(thid, 0, NULL);
    }
}
//code to stop the game ends here.

void init() {
    player = new gameObject("assets/ricardo.png", 0, 126, 25, 25, 0);
    ball1 = new gameObject("assets/ricardo.png", 100, 5, 25, 25, 2);
    ball1->min = 5;
    ball1->max = 242;
    ball1 = new gameObject("assets/ricardo.png", 5, 242, 25, 25, 1);
    ball1->min = 5;
    ball1->max = 450;
}

/*oude code
int resetplayer() {
    //reset player
    x = 0; 
    y = 126;
    return 0;
}


int moveBalls() {
    if (ballup) {
        if (bally <= 5) {
            ballup = false;
        }
        bally--;
    }
    else if (!ballup) {
        if (bally >= 267) {
            ballup = true;
        }
        bally++;
    }
    texture.drawRect(ballx, bally, 20, 20, BLUE);
    return 0;
}

int finish() {
    playing = false;
    
    SceCtrlData ctrldata;
    pspDebugScreenInit();
    pspDebugScreenSetTextColor(0xFFFF0000);
    pspDebugScreenPrintf("je bent gefinished! druk op x om opnieuw te starten.");
    pspDebugScreenSetTextColor(0xFF0000FF);
    
    while (true) {
        sceCtrlReadBufferPositive(&ctrldata, 1);
        
        if (ctrldata.Buttons & PSP_CTRL_CROSS) {
            //reset player
            resetplayer();
            playing = true;
            return 0;
        }
    }
}

int finishcheck() {
    float playertop = y;
    float playerbottom = y + 20;
    float playerleft = x;
    float playerright = x + 20;


        if (playertop > 161 || playerright < 430 || playerbottom < 111 || playerleft > 480) {
            //not touching the finish, so do nothing.
        }
        else {       
            finish();
        }    
    
    return 0;
} 

//wall variables
int muurtop[8] = {47, 151, 0, 157, 0, 266, 6, 161};
int muurleft[8] = {45, 0, 0, 0, 6, 6, 474, 474};
int muurwidth[8] = {6, 43, 6, 6, 479, 479, 6, 6};
int muurheight[8] = {68, 1, 116, 115, 6, 6, 105, 161};

int drawwalls() {
    //draw the walls    
    for (int i = 0; i < 8; i++) {
        texture.drawRect(muurleft[i], muurtop[i], muurwidth[i], muurheight[i], WHITE);
    }
    
    //draw the finish
    texture.drawRect(430, 111, 50, 50, GREEN);

    return 0;
}

int drawstuff() {


    //draw stuff
    g2dClear(BLACK);

    drawwalls();
    moveBalls();     
    texture.drawRect(x, y, 20, 20, RED);
               
    g2dFlip(G2D_VSYNC);
    
    finishcheck();
    
    return 0;
    
}

int collision() {
    
    //0.1 difference so only collision on overlap
    float playertop = y;
    float playerbottom = y + 20;
    float playerleft = x;
    float playerright = x + 20;

    for (int i = 0; i < 8; i++) {

        int muur_top = muurtop[i];
        int muur_bottom = muurtop[i] + muurheight[i];
        int muur_left = muurleft[i];
        int muur_right = muurleft[i] + muurwidth[i];

        if (playertop > muur_bottom || playerright < muur_left || playerbottom < muur_top || playerleft > muur_right) {

        }
        else {
            //collision
            x = xoud;
            y = youd;
                
        }

    }
    drawstuff();
    return 0;
}*/
void update() {
    player->update();
    ball1->update();
    ball2->update();
}
void render() {
    g2dClear(BLACK);

    player->render();
    ball1->render();
    ball2->render();
    g2dFlip(G2D_VSYNC);
}


auto main() -> int {
    
    setupcallbacks();
    init();
    //player sprite
    

    //movement under here
   

    while(playing) {
            
            
              update();
              render();  
              
    }
    
}
