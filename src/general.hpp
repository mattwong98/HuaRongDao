/*
 * general.hpp
 *
 *  Created on: Nov. 27, 2018
 *      Author: LinLand
 */

#ifndef GENERAL_HPP_
#define GENERAL_HPP_

#include <GL/glut.h>

#include "Shape.hpp"
#include "Camera.hpp"

class general: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat faceColor[6][3];
	GLfloat faceNormal[6][3];
	GLuint textureID[6];

public:
	general();
	void draw();
	void setTextureID(int index, int textureid);

private:
	void drawFace(int);
	bool isFrontface(int faceindex, Camera camera);
};

#endif /* GENERAL_HPP_ */
