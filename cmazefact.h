#ifndef __CMAZEFACT_H__
#define __CMAZEFACT_H__


#include <cstdint>		//para los tipos uint8_t
class CEnemy;
class CWall;
class CPlayer;


class CMazeFact {	//trabaja con la interfaz generica (CEnemy o CWall), no con tipos concretos (CEnemyLR o CWallMortal)
public:
	virtual CEnemy* createEnemy(uint8_t x, uint8_t y) = 0;	//le paso la posicion
	virtual CWall* createWall(uint8_t x, uint8_t y) = 0;
	virtual CPlayer* createPlayer(uint8_t x, uint8_t y) = 0;
};


#endif