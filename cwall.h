#ifndef __CWALL_H__
#define __CWALL_H__


#include "cgameobject.h"


class CWall : public CGameObject {
public:
	virtual void update() = 0;
	virtual void draw()   = 0;

	virtual bool isPlayer() { return false; }	//sigue siendo virtual, por si un hijo la implementa de otra manera
	virtual bool isMortal() { return false; }

private:

};


#endif