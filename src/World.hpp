/*
 * HBF
 */
#ifndef CWORLD_HPP
#define CWORLD_HPP

#include <iostream>
#include <list>
#include <vector>
#include "unit.hpp"
#include "general.hpp"
#include "king.hpp"

class World {

public:
	bool wbp[6][7]; //world board position
	GLint counter;
	Shape *list[11];
	World();
	~World();
	void draw();  // draw all objects in the world
	void reset(); //resets all objects
};

#endif
