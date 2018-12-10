#ifndef Cunit_H
#define Cunit_H

#include <GL/glut.h>

#include "Shape.hpp"

class unit: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceColor[6][3];
	GLfloat faceNormal[6][3];
	GLuint textureID[6];

public:
	unit();
	void draw();
	void setTextureID(int index, int textureid);

private:
	void drawFace(int);
	bool isFrontface(int faceindex, Camera camera);
};

#endif
