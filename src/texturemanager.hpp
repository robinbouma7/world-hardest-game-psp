#include "glib2d.h"
#include <stdlib.h>

class TextureManager {

public:
	static g2dTexture* loadTexture(char* filename);
    void drawTexture(float x, float y, int w, int h, g2dTexture* texture);
    void drawRect(float x, float y, int w, int h, g2dColor color);
};