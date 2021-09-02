#include "collision.hpp"


int muurtop[8] = {47, 151, 0, 157, 0, 266, 6, 161};
int muurleft[8] = {45, 0, 0, 0, 6, 6, 474, 474};
int muurwidth[8] = {6, 43, 6, 6, 479, 479, 6, 6};
int muurheight[8] = {68, 1, 116, 115, 6, 6, 105, 161};

bool Collision::wallcol(gameObject* Player, int level) {
    gameObject* player = Player;
    for (int i = 0; i < 8; i++) {

        int muur_top = muurtop[level][i];
        int muur_bottom = muurtop[level][i] + muurheight[level][i];
        int muur_left = muurleft[level][i];
        int muur_right = muurleft[level][i] + muurwidth[level][i];

        if (player->ypos > muur_bottom || player->xpos + player->width < muur_left || player->ypos + player->height < muur_top || player->xpos > muur_right) {

        }
        else {
            //collision
            return true;
                
        }

    }
    return false;
}
bool Collision::diecol(gameObject* Player, gameObject* Enemy) {
    gameObject* player = Player;
    gameObject* enemy = Enemy;
    if (player->ypos > enemy->ypos + enemy->width || player->xpos + player->width < enemy->xpos || player->ypos + player->height < enemy->ypos || player->xpos > enemy->xpos + enemy->width) {

    }
    else {
        //collision
        return true;
                
    }
    return false;
}