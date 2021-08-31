#include "collision.hpp"
int muurtop[8] = {47, 151, 0, 157, 0, 266, 6, 161};
int muurleft[8] = {45, 0, 0, 0, 6, 6, 474, 474};
int muurwidth[8] = {6, 43, 6, 6, 479, 479, 6, 6};
int muurheight[8] = {68, 1, 116, 115, 6, 6, 105, 161};

bool Collision::wallcol(float x, float y, int w, int h, int level) {
    for (int i = 0; i < 8; i++) {

        int muur_top = muurtop[level][i];
        int muur_bottom = muurtop[level][i] + muurheight[level][i];
        int muur_left = muurleft[level][i];
        int muur_right = muurleft[level][i] + muurwidth[level][i];

        if (y > muur_bottom || x + w < muur_left || y + h < muur_top || x > muur_right) {

        }
        else {
            //collision
            return true;
                
        }

    }
    return false;
}