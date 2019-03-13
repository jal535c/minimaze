#include "cmazefactHard.h"
#include "cenemyWander.h"
#include "cwallMortal.h"
#include "cplayer.h"


CMazeFactHard::CMazeFactHard() {
}


CEnemy* CMazeFactHard::createEnemy(uint8_t x, uint8_t y) {
	CEnemy* e = new CEnemyWander();
	e->setLocation(x, y);
	return e;
}


CWall* CMazeFactHard::createWall(uint8_t x, uint8_t y) {
	CWall* w = new CWallMortal();
	w->setLocation(x, y);
	return w;
}


CPlayer* CMazeFactHard::createPlayer(uint8_t x, uint8_t y) {
	CPlayer* p = new CPlayer();
	p->setLocation(x, y);
	return p;
}