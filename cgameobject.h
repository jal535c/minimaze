#ifndef __CGAMEOBJECT_H__
#define __CGAMEOBJECT_H__


#include <cstdint>		//para los tipos uint8_t, int8_t
//#include <string>		//no lo necesito


class CGameObject {		//clase abstracta: tiene metodos sin implementar (virtuales puros)
public:					
	virtual void setLocation(uint8_t x, uint8_t y);		//metodos genericos relativos a la posicion para todos los items, ...
	virtual void setNextMovement(int8_t dx, int8_t dy);	//a donde me quiero mover, le paso un desplazamiento

	virtual void update() = 0;	//interfaz del gameobject, metodos virtuales puro, obligan a que una subclase los implemente
	virtual void draw()   = 0;

	virtual bool isPlayer() = 0;	//cuando hay colisiones necesito saber si uno de ellos es jugador
	virtual bool isMortal() = 0;	//para saber si la entidad puede matar (enemigo si, player no, pared depende del nivel)

	uint8_t getX()     { return m_x; }
	uint8_t getY()     { return m_y; }
	uint8_t getNextX() { return m_nx; }
	uint8_t getNextY() { return m_ny; }
	bool wantsToMove() { return m_wantToMove; }

protected:
	uint8_t m_x, m_y;	//coordenadas actuales de cada entidad hija (scene, enemy, player, wall)
	bool m_wantToMove;	//indica si la entidad se quiere mover o no
	int8_t m_nx, m_ny;	//coordenadas de la posicion siguiente donde kiere ir la entidad
};


#endif