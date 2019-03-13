#include "cenemyWander.h"
//#include "StdPijo.h"
#include <cstdlib>		//para rand()
#include <algorithm>  	//para random_shuffle()

#include "crendererman.h"
#include "crenderer.h"


CEnemyWander::CEnemyWander() {
	initMovementVector();

	m_di   = 0;		//el primer movimiento es el del elemento 0 del vector
	m_step = 0;		
}


void CEnemyWander::initMovementVector() {
	m_dirs[0] = { 1, 0, static_cast<int8_t>(1 + rand() % 10) };		//derecha, de 1 a 10 pasos. Casting del valor devuelto por rand a int8_t
	m_dirs[1] = { 0, 1, static_cast<int8_t>(1 + rand() % 10) };		//arriba
	m_dirs[2] = {-1, 0, static_cast<int8_t>(1 + rand() % 10) };		//izquierda
	m_dirs[3] = { 0,-1, static_cast<int8_t>(1 + rand() % 10) };		//abajo
	std::random_shuffle(m_dirs + 0, m_dirs + 3);		//mezclar aleatoriamente los elementos del vector

	//m_di = 0;
}


void CEnemyWander::update() {
	TMoveDir& move = m_dirs[m_di];
	setNextMovement(move.dx, move.dy);		//pide moverse

	++m_step;
	if (m_step > move.step) {		//si ha llegao al final de pasos del elemento 0, pasa al elemento 1
		++m_di;
		if (m_di > 3) {				//si ha terminado el elemento 3, reinicia todo
			initMovementVector();
			m_di   = 0;
			m_step = 0;
		}
	}
}


void CEnemyWander::draw() {
	CRendererMan::p().renderer().drawEnemyWander(m_x, m_y);
}


CEnemyWander::~CEnemyWander() {

}

