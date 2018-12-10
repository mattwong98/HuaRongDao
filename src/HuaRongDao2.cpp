//============================================================================
// Name        : Huarong.cpp
// Author      : Matthew Wong, Fangjian Lei, Huai Yao Hu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "GL/glaux.h"
#include "World.hpp"
#include "Camera.hpp"

// global variables
GLint winWidth = 800, winHeight = 800;
//GLint xbegin = 0;     // x coordinate of mouse clik
//GLint coordinate = 1; // coordinate system selection : 1 for MC, 2 for WC, 3 for CV
//GLint option = 4;     // transform option
GLint objIndex;       // index of selected object

GLint move = 0;

World myWorld;
Camera myCamera;

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Hua Rong Dao");
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set display-window color to black
	glEnable(GL_DEPTH_TEST);
	myCamera.setProjectionMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.draw();
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}
void mouseAction(int button, int action, int x, int y) {

}

void keyAction(unsigned char key, int x, int y){
	int selectIndex = objIndex;
	int i;
	switch (key) {
	case 'w':
		if (myWorld.list[selectIndex]->movable(0, myWorld.wbp)) {
			myWorld.list[selectIndex]->translate(0, 0, -1);
			for (i = 4; i > 0; i--) {
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						0;
				myWorld.list[selectIndex]->setBP(
						myWorld.list[selectIndex]->bp[i][0],
						myWorld.list[selectIndex]->bp[i][1] - 1, i);
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						1;
			}
		}
		break;
	case 'a':
		if (myWorld.list[selectIndex]->movable(1, myWorld.wbp)) {
			myWorld.list[selectIndex]->translate(-1, 0, 0);
			for (i = 0; i < 4; i++) {
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						0;
				myWorld.list[selectIndex]->setBP(
						myWorld.list[selectIndex]->bp[i][0] - 1,
						myWorld.list[selectIndex]->bp[i][1], i);
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						1;
			}
		}
		break;
	case 's':
		if (myWorld.list[selectIndex]->movable(2, myWorld.wbp)) {
			myWorld.list[selectIndex]->translate(0, 0, 1);
			for (i = 0; i < 4; i++) {
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						0;
				myWorld.list[selectIndex]->setBP(
						myWorld.list[selectIndex]->bp[i][0],
						myWorld.list[selectIndex]->bp[i][1] + 1, i);
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						1;
			}
		}
		break;
	case 'd':
		if (myWorld.list[selectIndex]->movable(3, myWorld.wbp)) {
			myWorld.list[selectIndex]->translate(1, 0, 0);
			for (i = 4; i > 0; i--) {
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						0;
				myWorld.list[selectIndex]->setBP(
						myWorld.list[selectIndex]->bp[i][0] + 1,
						myWorld.list[selectIndex]->bp[i][1], i);
				myWorld.wbp[myWorld.list[selectIndex]->bp[i][0]][myWorld.list[selectIndex]->bp[i][1]] =
						1;
			}
		}
		break;
	}
	myWorld.draw();
}
void mainMenu(GLint transOption) {
	switch (transOption) {
	case 1:
		myWorld.reset();
		break;
	case 2:
		exit(1);
		break;
	}
	glutPostRedisplay();
}
void ObjSubMenu(GLint objectOption) {
	objIndex = objectOption;
	glutPostRedisplay();
}
void Menu() {
	GLint Object_Menu = glutCreateMenu(ObjSubMenu);
	glutAddMenuEntry("unit1 ", 0);
	glutAddMenuEntry("unit2 ", 1);
	glutAddMenuEntry("unit3 ", 2);
	glutAddMenuEntry("unit4 ", 3);
	glutAddMenuEntry("guard ", 4);
	glutAddMenuEntry("general1 ", 5);
	glutAddMenuEntry("general2 ", 6);
	glutAddMenuEntry("general3 ", 7);
	glutAddMenuEntry("general4 ", 8);
	glutAddMenuEntry("king ", 9);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry("Reset ", 1);
	glutAddSubMenu("Object Selection ", Object_Menu);

	glutAddMenuEntry("Quit", 2);

}
int main(int argc, char** argv) {

	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);

	init();
	Menu();
	glutDisplayFunc(display);
	glutMouseFunc(mouseAction);
	glutKeyboardFunc(keyAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
