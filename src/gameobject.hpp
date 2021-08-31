#include "glib2d.h"

class gameObject {

public:
	gameObject(char* texturesheet, float x, float y, int w, int h, int Type);
	~gameObject();

	void update();
	void render();

	float xpos;
	float ypos;
	int width;
	int height;
    int type;
	float xoud;
	float youd;
	float max = 0;
	float min = 0;
	bool movestate = false;

private:
	g2dTexture* objTexture;
	
};