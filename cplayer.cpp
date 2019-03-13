#include "cplayer.h"
#include "ckeyboardman.h"
//#include "StdPijo.h"

#include "crendererman.h"
#include "crenderer.h"


CPlayer::CPlayer() {
	m_KeyMan = &CKeyboardMan::p();
}


void CPlayer::update() {
	switch (m_KeyMan->getLastKeyPressed()) {
		case 'a': setNextMovement(-1,  0); break;    //pone coordenadas futuras una posicion a la izquierda, pide moverse
		case 'w': setNextMovement( 0, -1); break;    //pone coordenadas futuras una posicion arriba, pide moverse
		case 's': setNextMovement( 0,  1); break;    //pone coordenadas futuras una posicion abajo, pide moverse
		case 'd': setNextMovement( 1,  0); break;    //pone coordenadas futuras una posicion a la derecha, pide moverse
		default: break;
	}
}


void CPlayer::draw() {
	CRendererMan::p().renderer().drawPlayer(m_x, m_y);
}


CPlayer::~CPlayer() {

}
