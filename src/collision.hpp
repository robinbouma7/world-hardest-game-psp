#include "glib2d.h"
#include <stdlib.h>
#include "game.hpp"

class Collision {
public:
    bool wallcol(gameObject* Player, int level);
    bool diecol(gameObject* Player, gameObject* Enemy);
private:
    int muurtop[1][8] = {47, 151, 0, 157, 0, 266, 6, 161};
    int muurleft[1][8] = {45, 0, 0, 0, 6, 6, 474, 474};
    int muurwidth[1][8] = {6, 43, 6, 6, 479, 479, 6, 6};
    int muurheight[1][8] = {68, 1, 116, 115, 6, 6, 105, 161};
};