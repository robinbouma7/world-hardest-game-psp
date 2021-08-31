#include "TextureManager.hpp"

g2dTexture* TextureManager::loadTexture(char* texture) {
	g2dTexture* tex = g2dTexLoad(texture, G2D_SWIZZLE);

	return tex;
}
void TextureManager::drawTexture(float x, float y, int w, int h, g2dTexture* texture) {
    g2dBeginRects(texture);
    if (texture == NULL) {
        g2dSetColor(RED);
    }
    g2dSetCoordMode(G2D_UP_LEFT);
    g2dSetAlpha(255);
    g2dSetScaleWH(w,h);
    g2dSetCoordXY(x,y);
    g2dSetRotation(0);
    g2dAdd();
    g2dEnd();
}
void TextureManager::drawRect(float x, float y, int w, int h, g2dColor color) {
    g2dBeginRects(NULL); // No texture
    g2dSetCoordMode(G2D_UP_LEFT);
    g2dSetColor(color);
    g2dSetScaleWH(w,h);
    g2dSetCoordXY(x,y);
    g2dAdd();
    g2dEnd();
}