#include "cmazefactEasy.h"
#include "cenemyLR.h"
#include "cwallNormal.h"
#include "cplayer.h"


CMazeFactEasy::CMazeFactEasy() {
}


CEnemy* CMazeFactEasy::createEnemy(uint8_t x, uint8_t y) {
	CEnemyLR* e = new CEnemyLR();		//tambien vale si pongo CEnemy* e
	e->setLocation(x, y);
	return e;		//lo devolvemos como CEnemy, ya que es la interfaz generica que hemos creado (polimorfismo)
}


CWall* CMazeFactEasy::createWall(uint8_t x, uint8_t y) {
	CWallNormal* w = new CWallNormal();
	w->setLocation(x, y);
	return w;		//aunque w sea CWallNormal*, devuelve un CWall*
}


CPlayer* CMazeFactEasy::createPlayer(uint8_t x, uint8_t y) {
	CPlayer* p = new CPlayer();
	p->setLocation(x, y);
	return p;
}