#include "model.h"

bool operator==(const Point& lhs, const Point& rhs) {
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

Point Random_point (Point size) {
	int x = (rand() % (size.x - 2)) + 2;
	int y = (rand() % (size.y - 2)) + 2;
	return {x, y};
}

Snake::Snake(Point size) {
	segments.push_back({size.x / 2, size.y / 2});
	segments.push_back({size.x / 2 - 1, size.y / 2});
	dir_ = Direction::UP;
}

void Snake::Move() {
	segments.pop_front();	
	switch(dir_) {
	case Direction::UP:
		segments.push_back({segments.back().x - 1, segments.back().y});
		break;
	case Direction::DOWN:
		segments.push_back({segments.back().x + 1, segments.back().y});
		break;
	case Direction::LEFT:
		segments.push_back({segments.back().x, segments.back().y - 1});
		break;
	case Direction::RIGHT:
		segments.push_back({segments.back().x, segments.back().y + 1});
		break;
	}
}

void Snake::Grow() {
	Point last = segments.front();
	Point prelast = *(++segments.begin());
	if (last.x == prelast.x)
		if (last.y < prelast.y)
			segments.push_front({last.x, last.y - 1});
		else
			segments.push_front({last.x, last.y + 1});
	else
		if (last.x < prelast.x)
			segments.push_front({last.x - 1, last.y});
		else
			segments.push_front({last.x + 1, last.y});
}

bool Game::Check_intersect() const {
	Point head = s_.Get_segments().back();
	if (head.x == 1 || head.x == size_.x || head.y == 1 || head.y == size_.y
		|| count(s_.Get_segments().begin(), s_.Get_segments().end(), head) > 1)
		return true;
	return false;
}

bool Game::Change() {
	if (Check_rabbit()) {
		s_.Grow();
		Add_rabbit();
	}
	s_.Move();
	if (Check_intersect())
		return true;
	return false;
}

void Game::Add_rabbit() {
	Point p = Random_point(size_);
	while (count(s_.Get_segments().begin(), s_.Get_segments().end(), p) > 0)
		p = Random_point(size_);
	r_.p_ = p;
}
