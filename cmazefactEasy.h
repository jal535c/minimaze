#ifndef __CMAZEFACTEASY_H__
#define __CMAZEFACTEASY_H__


#include "cmazefact.h"


class CMazeFactEasy : public CMazeFact {	//tiene los 3 metodos virtuales del padre mas el constructor (ya es un objeto concreto)
public:
	CMazeFactEasy();
	virtual CEnemy* createEnemy(uint8_t x, uint8_t y);
	virtual CWall* createWall(uint8_t x, uint8_t y);
	virtual CPlayer* createPlayer(uint8_t x, uint8_t y);

protected:	

};


#endif