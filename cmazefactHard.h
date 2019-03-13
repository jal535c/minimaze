#ifndef __CMAZEFACTHARD_H__
#define __CMAZEFACTHARD_H__


#include "cmazefact.h"


class CMazeFactHard : public CMazeFact {
public:
	CMazeFactHard();
	virtual CEnemy* createEnemy(uint8_t x, uint8_t y);		//le paso la posicion
	virtual CWall* createWall(uint8_t x, uint8_t y);
	virtual CPlayer* createPlayer(uint8_t x, uint8_t y);

protected:

};


#endif