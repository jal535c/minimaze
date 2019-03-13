#include "crendererstdp.h"
#include <cstdint>
#include "StdPijo.h"


CRendererSTDP::CRendererSTDP() {
	STDP::Inicializar();	//inicia el modo ncurses
	clearScreen();
}


CRendererSTDP::~CRendererSTDP() {
	STDP::Terminar();		//termina el modo ncurses
}


void CRendererSTDP::clearScreen() const {
	STDP::BorraPantalla();
}


void CRendererSTDP::refresh() const {
	STDP::Refrescar();
}


void CRendererSTDP::drawEnemyLR(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);	//pone el caracter de rojo sobre fondo negro
	STDP::PonCursor(x, y);		//posiciona cursor
	STDP::sout << "E";			//el enemigo se representa con la letra E
}


void CRendererSTDP::drawEnemyWander(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_MAGENTA, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "W";
}


void CRendererSTDP::drawPlayer(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_AMARILLO, STDP_C_NEGRO); //pone color amarillo sobre negro
   	STDP::PonCursor(x, y);    	//posiciona cursor
	STDP::sout << "P";          //pinta el caracter P (representa al jugador)
}


void CRendererSTDP::drawWallNormal(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_VERDE, STDP_C_NEGRO);	//pongo color verde sobre fondo negro
	STDP::PonCursor(x, y);			//posiciono cursor
	STDP::sout << "#";				//pinta el caracter # (representa la pared)
}


void CRendererSTDP::drawWallMortal(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);	
	STDP::PonCursor(x, y);
	STDP::sout << "*";
}


void CRendererSTDP::drawGameOver(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_BLANCO, STDP_C_ROJO);
	STDP::PonCursor(x, y);			
	STDP::sout << "GAME  OVER";	
}


char CRendererSTDP::getKey() const {
	return STDP::ObtenTecla();
}

