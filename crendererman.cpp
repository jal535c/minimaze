#include "crendererman.h"
#include "crenderer.h"
#include "crendererstdp.h"
#include "crendererstdp2.h"


CRendererMan::CRendererMan() {
	m_renderer = new CRendererSTDP();
}


CRendererMan::~CRendererMan() {
	delete m_renderer;
}


CRendererMan& CRendererMan::p() {		//singleton
	static CRendererMan instance;
	return instance;
}


CRenderer& CRendererMan::renderer() {	//para usar una instancia de esta clase
	return *m_renderer;
}


void CRendererMan::switchRenderer() {		//cambia al otro renderer
	delete m_renderer;

	switch (m_selected) {
		case TRenderer::STDP: {
			m_renderer = new CRendererSTDP2();
			m_selected = TRenderer::STDP2;
			break;
		} 
		
		case TRenderer::STDP2: {
			m_renderer = new CRendererSTDP();
			m_selected = TRenderer::STDP;
			break;
		} 
	}
}

