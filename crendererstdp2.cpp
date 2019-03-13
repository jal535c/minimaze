#include "crendererstdp2.h"
#include <cstdint>
#include "StdPijo.h"


CRendererSTDP2::CRendererSTDP2() {
	STDP::Inicializar();	//inicia el modo ncurses
	clearScreen();
}


CRendererSTDP2::~CRendererSTDP2() {
	STDP::Terminar();		//termina el modo ncurses
}


void CRendererSTDP2::clearScreen() const {
	STDP::BorraPantalla();
}


void CRendererSTDP2::refresh() const {
	STDP::Refrescar();
}


void CRendererSTDP2::drawEnemyLR(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);	//caracter de rojo sobre fondo negro
	STDP::PonCursor(2*x, 2*y);	
	STDP::sout << "EE";			
	STDP::PonCursor(2*x, 2*y+1);	
	STDP::sout << "EE";			
}


void CRendererSTDP2::drawEnemyWander(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_MAGENTA, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "WW";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "WW";
}


void CRendererSTDP2::drawPlayer(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_AMARILLO, STDP_C_NEGRO); //pone color amarillo sobre negro
   	STDP::PonCursor(2*x, 2*y);    
   	STDP::sout << "PP";            
   	STDP::PonCursor(2*x, 2*y+1);    
   	STDP::sout << "PP";            
}


void CRendererSTDP2::drawWallNormal(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_VERDE, STDP_C_NEGRO);	//pongo color verde sobre fondo negro
	STDP::PonCursor(2*x, 2*y);		
	STDP::sout << "##";				
	STDP::PonCursor(2*x, 2*y+1);		
	STDP::sout << "##";				
}


void CRendererSTDP2::drawWallMortal(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_ROJO, STDP_C_NEGRO);		//rojo sobre negro
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "**";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "**";
}


void CRendererSTDP2::drawGameOver(uint8_t x, uint8_t y) const {
	STDP::CambiaColor(STDP_A_NEGRITA, STDP_C_BLANCO, STDP_C_ROJO);
	STDP::PonCursor(2*x, 2*y);			
	STDP::sout << "GGAAMMEE    OOVVEERR";		
	STDP::PonCursor(2*x, 2*y+1);			
	STDP::sout << "GGAAMMEE    OOVVEERR";	
}


char CRendererSTDP2::getKey() const {
	return STDP::ObtenTecla();
}

