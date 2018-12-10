#ifndef CSHAPE_H
#define CSHAPE_H

#include <stdlib.h>
#include <iostream>
#include <math.h>

#include <GL/glut.h>

#include "Matrix.hpp"
#include "Camera.hpp"

using namespace std;

/**
 * Shape class the common class that will be inherited model object class
 */
class Shape {
protected:
	Matrix mc; // the Model coordinate system in (X, Y, Z, O)
	Matrix *pmc; // parent mc pointer
	GLfloat s; // scale factor
	float distance;
	GLint tcounter; // rotation transform counter
	//board position [position index][x or y]

public:
	bool bp[4][2];
	Shape();           // constructor
	virtual ~Shape();  // destructor
	Matrix getMC();   // Matrix
	void setBP(int x, int y, int index); //mutator for bp
	bool movable(int direction, bool wbp[6][7]);
	void setParentMC(Matrix *pm);
	void calcDistance(GLfloat x, GLfloat y, GLfloat z);
	void ctmMultiply();          // function to do the CTM * MC
	void scaleChange(GLfloat x); // to change the scale factor
	void translate(GLfloat tx, GLfloat ty, GLfloat tz); //translate the MC origin
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);      // rotate object in WC
	void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);// just rotate the origin of object in WC
	void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);    // to rotate in MC
	void rotateRelative(GLfloat x0, GLfloat  y0, GLfloat  z0, GLfloat  rx, GLfloat  ry, GLfloat rz, GLfloat  angle);
	void reset();   // a function that resets the shape transformation matrix
	virtual void draw() = 0; // draw function must be overwritten
};

#endif
