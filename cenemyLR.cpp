#include "cenemyLR.h"
//#include "StdPijo.h"

#include "crendererman.h"
#include "crenderer.h"


CEnemyLR::CEnemyLR() : m_dir(1) {	//inicializa el atributo a 1 (derecha)
}


void CEnemyLR::update() {	//si son diferentes es porke no se ha movido la ultima vez (habia pared), entonces cambio dir
	if (m_x != m_nx) {		//la primera vez m_nx no está inicializado, por tanto son diferentes, entrando y cambiando m_dir (izquierda)
		m_dir = -m_dir;
	}

	setNextMovement(m_dir, 0);		//metodo de CGameObject (desplaza +1 o -1 en eje X, y 0 en eje Y), siempre pide moverse pero scene decide
}


void CEnemyLR::draw() {
	CRendererMan::p().renderer().drawEnemyLR(m_x, m_y);
}


CEnemyLR::~CEnemyLR() {

}