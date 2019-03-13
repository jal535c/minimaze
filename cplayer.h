#ifndef __CPLAYER_H__
#define __CPLAYER_H__


#include "cgameobject.h"	//lo necesita ya que la clase CPlayer deriva de CGameObject
class CKeyboardMan;			//forward declaration


class CPlayer : public CGameObject {
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void update();
	virtual void draw();

	virtual bool isPlayer() { return true; };	//cuando hay colisiones necesito saber si uno de ellos es jugador
	virtual bool isMortal() { return false; };
	
private:
	CKeyboardMan* m_KeyMan;		//referencia al manager de teclas, para preguntar si se ha pulsado alguna tecla
};


#endif