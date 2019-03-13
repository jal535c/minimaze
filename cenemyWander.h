#ifndef __CENEMYWANDER_H__
#define __CENEMYWANDER_H__


#include "cenemy.h"


class CEnemyWander : public CEnemy {
public:
	struct TMoveDir {
		int8_t dx, dy, step;	//dir x, dir y, pasos aleatorios de 1 a 10 que se mueve en esa dir (el atributo m_step es uint8_t ?)
	};

	CEnemyWander();
	virtual ~CEnemyWander();
	virtual void update();		//override?
	virtual void draw();		//override?

	virtual bool isPlayer() { return false; };		//const override?
	virtual bool isMortal() { return true; };		//const override?

private:
	uint8_t  m_di;		//direction index, indice del vector de direccion en la k me voy a mover
	uint8_t  m_step;	//step number, para llevar la cuenta de los pasos movidos
	TMoveDir m_dirs[4];	//direction vector (up, down, left, right), vector las 4 direcciones pero no sé el orden ni los pasos k me muevo en cada una de ellas 

	void initMovementVector();		//inicializar vector de movimientos
};


#endif