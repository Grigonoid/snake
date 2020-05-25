#include "model.h"

void Handle_key(Game& g, char key)
{
	Direction current_dir = g.s_.dir_;
	switch(key) {
	case 'w':
		g.s_.dir_ = (current_dir == Direction::DOWN) ? current_dir : Direction::UP;
		break;
	case 's':
		g.s_.dir_ = (current_dir == Direction::UP) ? current_dir : Direction::DOWN;
		break;
	case 'a':
		g.s_.dir_ = (current_dir == Direction::RIGHT) ? current_dir : Direction::LEFT;
		break;
	case 'd':
		g.s_.dir_ = (current_dir == Direction::LEFT) ? current_dir : Direction::RIGHT;
		break;
	default:
		return;
	}
}
