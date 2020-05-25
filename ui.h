#pragma once

#include "model.h"

using namespace std;

class Ui {
	virtual Point Getsize() const = 0;
	virtual void Draw_boarder() const = 0;
	virtual void Draw(const Rabbit& r) const = 0;
	virtual void Draw(const Snake& s) const = 0;
	virtual void Draw(const Game& g) const = 0;
	virtual char Get_key() = 0;
};
