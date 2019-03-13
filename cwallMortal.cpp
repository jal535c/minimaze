#include "cwallMortal.h"
//#include "StdPijo.h"

#include "crendererman.h"
#include "crenderer.h"


CWallMortal::CWallMortal() {
}


void CWallMortal::update() {
}


void CWallMortal::draw() {
	CRendererMan::p().renderer().drawWallMortal(m_x, m_y);
}


CWallMortal::~CWallMortal() {
}