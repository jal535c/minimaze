#include "ckeyboardman.h"
//#include "StdPijo.h"
#include "crendererman.h"
#include "crenderer.h"


CKeyboardMan::CKeyboardMan() {}


CKeyboardMan::~CKeyboardMan() {}


CKeyboardMan& CKeyboardMan::p() {      
	static CKeyboardMan instance;       //crea instancia statica de la clase
	return instance;                    //devuelve el objeto por referencia
}


void CKeyboardMan::update() {
	m_lastKeyPressed = CRendererMan::p().renderer().getKey();
}


char CKeyboardMan::getLastKeyPressed() { 
	return m_lastKeyPressed; 
}


void CKeyboardMan::clear() {
	while (CRendererMan::p().renderer().getKey() > -1);     //borra el buffer de teclado
}

