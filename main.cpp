#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "glib2d.h"
#include <stdlib.h>


float x = 12.5, y = 136;
bool input = false;
float xoud = x;
float youd = y;
bool playing = true;
int ballx = 200;
int bally = 5;
bool ballup = false;



PSP_MODULE_INFO("game-test", 0, 1, 1);
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

int moveBalls() {
    if (ballup) {
        if (bally <= 5) {
            ballup = false;
        }
    }
    else if (!ballup) {
        if (bally >= 267) {
            ballup = true;
        }
    }
    g2dBeginRects(NULL); // No texture
    g2dSetColor(BLUE);
    g2dSetScaleWH(25,25);
    g2dSetCoordXY(ballx,bally);
    g2dAdd();
    g2dEnd();
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
            
            playing = true;
            return 0;
        }
    }
}

int finishcheck() {
    float playertop = y - 12.4;
    float playerbottom = y + 12.4;
    float playerleft = x - 12.4;
    float playerright = x + 12.4;


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
    for (int j = 0; j < 8; j++) {
        g2dBeginRects(NULL); // No texture
        g2dSetColor(WHITE);
        g2dSetScaleWH(muurwidth[j],muurheight[j]);
        g2dSetCoordXY(muurleft[j],muurtop[j]);
        g2dAdd();
        g2dEnd();
    
    }
    
    //draw the finish
    g2dBeginRects(NULL); // No texture
    g2dSetColor(GREEN);
    g2dSetScaleWH(50,50);
    g2dSetCoordXY(430,111);
    g2dAdd();
    g2dEnd();

    return 0;
}

int drawstuff() {


    //draw stuff
    g2dClear(BLACK);

    drawwalls();       

    g2dBeginRects(NULL); // No texture
    g2dSetColor(RED);
    g2dSetScaleWH(25,25);
    g2dSetCoordXY(x,y);
    g2dAdd();
    g2dEnd();
               
    g2dFlip(G2D_VSYNC);
    
    finishcheck();
    
    return 0;
    
}

int collision() {
    
    //0.1 difference so only collision on overlap
        float playertop = y + 0.1;
        float playerbottom = y + 3.9;
        float playerleft = x + 0.1;
        float playerright = x + 3.9;

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
}



auto main() -> int {
    
    setupcallbacks();

    //player sprite
    

    //movement under here
    SceCtrlData ctrldata;
    while(playing) {
            
            sceCtrlReadBufferPositive(&ctrldata, 1);

                xoud = x;
                youd = y;
        

                if (ctrldata.Buttons & PSP_CTRL_UP) { 
                    y -= 0.5;
                }

                if (ctrldata.Buttons & PSP_CTRL_DOWN) {
                    y += 0.5;
                }

                if (ctrldata.Buttons & PSP_CTRL_RIGHT) {                  
                    x += 0.5;
                }

                if (ctrldata.Buttons & PSP_CTRL_LEFT) {                   
                        x -= 0.5; 
                }
                              
                else {
                    
                }
        
                collision();
              
    }
    
}
