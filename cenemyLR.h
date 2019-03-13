#ifndef __CENEMYLR_H__
#define __CENEMYLR_H__


#include "cenemy.h"
//falta #include <cstdint>, para int8_t (ya está incluido en cgameobject.h)


class CEnemyLR : public CEnemy {
public:
	CEnemyLR();
	virtual ~CEnemyLR();
	
	virtual void update();	//override?
	virtual void draw();	//override?

	virtual bool isPlayer() { return false; };		//const override?	//repetido??
	virtual bool isMortal() { return true; };		//const override?

private:
	int8_t m_dir;	//direccion o sentido del enemigo, izquierda (-1) o derecha (1), despues se pasa como desplazamiento
};


#endif