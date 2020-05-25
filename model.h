#pragma once

#include <list>
#include <algorithm>
#include <cstdlib> //for rand
#include <ctime>    //and srand

using namespace std;

enum class Direction {
	UP, DOWN, LEFT, RIGHT
};

struct Point {
	int x, y;
};

bool operator==(const Point& lhs, const Point& rhs);
Point Random_point (Point size);

struct Rabbit {
	Rabbit(Point size) {p_ = Random_point(size);}
	Point p_;
};

class Snake {
public:
	Snake(Point size);
	const list<Point>& Get_segments() const {return segments;}
	void Move();
	void Grow();

	Direction dir_;
private:
	list<Point> segments;
}; 

class Game {
public:
	Game(Point size) : s_(size), r_(size), size_(size) {
		srand(static_cast<unsigned int>(time(0)));
	}
	bool Check_rabbit() const {return (s_.Get_segments().back() == r_.p_);}
	void Add_rabbit();
	bool Check_intersect() const;
	bool Change();
	Snake s_;
	Rabbit r_;
	Point size_;
};
