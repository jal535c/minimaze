#ifndef __CENEMY_H__
#define __CENEMY_H__


#include "cgameobject.h"


class CEnemy : public CGameObject {		//clase abstracta, no se puede implementar un objeto de ella por tener metodos virtuales puros
public:
	virtual void update() = 0;		//estos metodos dependen de cada tipo de enemigo
	virtual void draw()   = 0;

	virtual bool isPlayer() { return false; };	//todos los enemigos son mortales (matan), y ninguno es el jugador, const override?
	virtual bool isMortal() { return true; };	// por eso se implementa aki, lo tendran todas las subclases

private:

};


#endif