#ifndef __CWALLNORMAL_H__
#define __CWALLNORMAL_H__


#include "cwall.h"


class CWallNormal : public CWall {
public:
	CWallNormal();
	virtual ~CWallNormal();

	virtual void update();		
	virtual void draw();		

	virtual bool isPlayer() { return false; };		//no hace falta, ya está en cwall.h, o bien poner el padre virtual puro
	virtual bool isMortal() { return false; };		

private:

};


#endif