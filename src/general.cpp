/*
 * general.cpp
 *
 *  Created on: Nov. 27, 2018
 *      Author: LinLand
 */

#include "general.hpp"

extern bool isShading;

extern bool isTexture;
extern Camera myCamera;

general::general() {
	vertex[0][0] = -1; vertex[0][1] = -1; vertex[0][2] = -2;
	vertex[1][0] = -1;
	vertex[1][1] = 1;
	vertex[1][2] = -2;
	vertex[2][0] = 1; vertex[2][1] = 1; vertex[2][2] = -2;
	vertex[3][0] = 1; vertex[3][1] = -1; vertex[3][2] = -2;
	vertex[4][0] = -1; vertex[4][1] = -1; vertex[4][2] = 2;
	vertex[5][0] = -1; vertex[5][1] = 1; vertex[5][2] = 2;
	vertex[6][0] = 1; vertex[6][1] = 1; vertex[6][2] = 2;
	vertex[7][0] = 1; vertex[7][1] = -1; vertex[7][2] = 2;

	face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
	face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
	face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
	face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
	face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
	face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;

	faceColor[0][0] = 1.0, faceColor[0][1] = 0.0; faceColor[0][2] = 0.0;
	faceColor[1][0] = 0.0, faceColor[1][1] = 1.0; faceColor[1][2] = 0.0;
	faceColor[2][0] = 0.0, faceColor[2][1] = 0.0; faceColor[2][2] = 1.0;
	faceColor[3][0] = 1.0, faceColor[3][1] = 1.0; faceColor[3][2] = 0.0;
	faceColor[4][0] = 1.0, faceColor[4][1] = 0.0; faceColor[4][2] = 1.0;
	faceColor[5][0] = 0.0, faceColor[5][1] = 1.0; faceColor[5][2] = 1.0;

	faceNormal[0][0] = 0.0,faceNormal[0][1] = 0.0,faceNormal[0][2] = -1.0,
	faceNormal[1][0] = 0.0, faceNormal[1][1] = 0.0, faceNormal[1][2] = 1.0;
	faceNormal[2][0] = -1.0, faceNormal[2][1] = 0.0, faceNormal[2][2] = 0.0;
	faceNormal[3][0] = 0.0, faceNormal[3][1] = 1.0, faceNormal[3][2] = 0.0;
	faceNormal[4][0] = 1.0, faceNormal[4][1] = 0.0, faceNormal[4][2] = 0.0;
	faceNormal[5][0] = 0.0, faceNormal[5][1] = -1.0, faceNormal[5][2] = 0.0;

}


void general::drawFace(int i)
{
	glColor3f(faceColor[i][0], faceColor[i][1], faceColor[i][2]);
	glBegin(GL_POLYGON);
	glVertex3fv(vertex[face[i][0]]);
	glVertex3fv(vertex[face[i][1]]);
	glVertex3fv(vertex[face[i][2]]);
	glVertex3fv(vertex[face[i][3]]);
	glEnd();

}


void general::draw()
{
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);

	for (int i = 0; i < 6; i++) {
		if (isFrontface(i, myCamera))
			drawFace(i);
	}

	glPopMatrix();
}


bool general::isFrontface(int faceindex, Camera camera) {
	GLfloat v[4];
	v[0] = faceNormal[faceindex][0];
	v[1] = faceNormal[faceindex][1];
	v[2] = faceNormal[faceindex][2];
	v[3] = 0.0;

	mc.multiplyVector(v);

	if (pmc != NULL) {
		pmc->multiplyVector(v);
		return  (pmc->mat[0][3]-camera.eye.x) * v[0] + (pmc->mat[1][3]-camera.eye.y) * v[1] +  (pmc->mat[2][3]-camera.eye.z) * v[2] < 0;
	} else

		return  (mc.mat[0][3]-camera.eye.x) * v[0] + (mc.mat[1][3]-camera.eye.y) * v[1] +  (mc.mat[2][3]-camera.eye.z) * v[2] < 0;
}


