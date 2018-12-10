
#include "World.hpp"

extern GLint selected;

extern GLint isAll;

extern Camera myCamera;

World::World() {
	counter = 10;
	int i, j;
	for(i = 0; i < 4; i++){
		list[i] = new unit();
	}

	for(i; i < 9; i++){
		list[i] = new general();

	}
	list[9] = new king();

	list[0]->setBP(1, 5, 0);
	list[0]->setBP(1, 5, 1);
	list[0]->setBP(1, 5, 2);
	list[0]->setBP(1, 5, 3);
	list[0]->translate(-1.5, 0, 2);

	list[1]->setBP(2, 4, 0);
	list[1]->setBP(2, 4, 1);
	list[1]->setBP(2, 4, 2);
	list[1]->setBP(2, 4, 3);
	list[1]->translate(-0.5, 0, 1);

	list[2]->setBP(3, 4, 0);
	list[2]->setBP(3, 4, 1);
	list[2]->setBP(3, 4, 2);
	list[2]->setBP(3, 4, 3);
	list[2]->translate(0.5, 0, 1);

	list[3]->setBP(4, 5, 0);
	list[3]->setBP(4, 5, 1);
	list[3]->setBP(4, 5, 2);
	list[3]->setBP(4, 5, 3);
	list[3]->translate(1.5, 0, 2);

	list[4]->setBP(2, 3, 0);
	list[4]->setBP(3, 3, 1);
	list[4]->setBP(2, 3, 2);
	list[4]->setBP(3, 3, 3);
	list[4]->rotateMC(list[4]->getMC().mat[0][1], list[4]->getMC().mat[1][1],
			list[4]->getMC().mat[2][1], 270);

	list[5]->setBP(1, 4, 0);
	list[5]->setBP(1, 4, 1);
	list[5]->setBP(1, 3, 2);
	list[5]->setBP(1, 3, 3);
	list[5]->translate(-1.5, 0, 0.5);

	list[6]->setBP(4, 4, 0);
	list[6]->setBP(4, 4, 1);
	list[6]->setBP(4, 3, 2);
	list[6]->setBP(4, 3, 3);
	list[6]->translate(1.5, 0, 0.5);

	list[7]->setBP(1, 2, 0);
	list[7]->setBP(1, 2, 1);
	list[7]->setBP(1, 1, 2);
	list[7]->setBP(1, 1, 3);
	list[7]->translate(-1.5, 0, -1.5);

	list[8]->setBP(4, 2, 0);
	list[8]->setBP(4, 2, 1);
	list[8]->setBP(4, 1, 2);
	list[8]->setBP(4, 1, 3);
	list[8]->translate(1.5, 0, -1.5);

	list[9]->setBP(2, 2, 0);
	list[9]->setBP(3, 2, 1);
	list[9]->setBP(2, 1, 2);
	list[9]->setBP(3, 1, 3);
	list[9]->translate(0, 0, -1.5);

//	for(i= 0; i < 9; i++){
//		list[i]->scaleChange(0.45);
//	}

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			wbp[i][j] = 1;
		}
	}

	wbp[2][5] = 0;
	wbp[3][5] = 0;
}


World::~World(){
	for (int i=0; i < counter; i++)
		delete list[i];
}


void World::draw() {

	for (int i = 0; i < counter; i++)
		list[i]->draw();
}


void World::reset(){
	list[0]->reset();
	list[1]->reset();
	list[2]->reset();
}

