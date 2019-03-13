#include "cwallNormal.h"
//#include "StdPijo.h"

#include "crendererman.h"
#include "crenderer.h"


CWallNormal::CWallNormal() {
}


void CWallNormal::update() {	//la pared no hace nada, no hay que actualizar su posicion (no se mueve)
}


void CWallNormal::draw() {
	CRendererMan::p().renderer().drawWallNormal(m_x, m_y);
}


CWallNormal::~CWallNormal() {
}