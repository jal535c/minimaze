#ifndef __CWALLMORTAL_H__
#define __CWALLMORTAL_H__


#include "cwall.h"


class CWallMortal : public CWall {
public:
	CWallMortal();
	virtual ~CWallMortal();

	virtual void update();
	virtual void draw();

	virtual bool isPlayer() { return false; };
	virtual bool isMortal() { return true; };		//tocar la pared mata, solo doy informacion (la logica de colisiones está en la scene)

private:

};


#endif