#include "cscene.h"
#include "cenemy.h"			//no debe conocer los tipos concretos LR y wander, solo la interfaz, lo cual evita acoplamiento
//#include "cenemyLR.h"			
//#include <cenemyWander.h>
#include "cwall.h"
//#include "cwallNormal.h"		
//#include <cwallMortal.h>
#include "cplayer.h"
#include <string>			//para los string de los errores
#include <stdexcept>		//para throw
#include <algorithm>		//para find()


CScene::CScene() {
	for (uint8_t i = 0; i < 13; i++) {
		for (uint8_t j = 0; j < 13; j++) {
			m_objMatrix[i][j] = nullptr;	//se usará para comparar colisiones
		}
	}
}


#include "cmazefact.h"		//aunque el .h lleve el forward declaration, aquí si necesito incluir el fichero .h


void CScene::initialize(CMazeFact &f) {		//recibo una fabrica, ya no necesita saber el nivel
	for (uint8_t i = 2; i < 12; ++i) {
		CWall *wt = f.createWall( i,  1);		//top, para las paredes
		CWall *wd = f.createWall( i, 12);		//down
		CWall *wl = f.createWall( 1,  i);		//left
		CWall *wr = f.createWall(12,  i);		//right
		addGameObject(wt,  i,  1);
		addGameObject(wd,  i, 12);
		addGameObject(wl,  1,  i);
		addGameObject(wr, 12,  i);
	}

	CEnemy *e1 = f.createEnemy(3, 3);
	CEnemy *e2 = f.createEnemy(5, 6);
	CPlayer *p = f.createPlayer(2, 2);
	addGameObject(e1, 3, 3);
	addGameObject(e2, 5, 6);
	addGameObject(p, 2, 2);
	
	m_thereIsAPlayer = true;
}


void CScene::addGameObject(CGameObject* o, uint8_t x, uint8_t y)  {
	if (x > 12 || y > 12) {
		throw std::out_of_range( static_cast<std::string>("out of scene matrix (" ) + std::to_string(x) + "," + std::to_string(y) + ")" );
	} else if (m_objMatrix[x][y] != nullptr) {
		throw std::logic_error( static_cast<std::string>("duplicated object at (" ) + std::to_string(x) + "," + std::to_string(y) + ")" );
	}

	m_objMatrix[x][y] = o;			//mete el objeto en el mapa para las colisiones
	o->setLocation(x, y);			//posiciona el objeto
	m_gameObjects.push_back(o);		//lo mete en el vector
}


void CScene::update() {
	size_t s = m_gameObjects.size();

	for (size_t i=0; i < s; i++) {
		CGameObject *g = m_gameObjects[i];
		g->update();			//voy actualizando cada GameObject
		moveGameObject(g);		//los objetos dicen Me kiero mover, la scena decide si los mueve
		
		if (m_gameObjects.size() != s) {
			s = m_gameObjects.size();		//si quito el 5º, el tamaño cambia, pero el siguiente a mirar es de nuevo el 5º
			--i;
		}
	}
}


void CScene::draw() {
	for (CGameObject* g : m_gameObjects) {
		g->draw();
	}
}


CScene::~CScene() {  
	for(CGameObject* g : m_gameObjects) {
		delete g;			//para los new de CMazeFactEasy
	}
	m_gameObjects.clear();		//limpia el vector
}


#include "StdPijo.h"


void CScene::removeGameObject(CGameObject *g) {
	TObjVec::iterator it;
	it = std::find(m_gameObjects.begin(), m_gameObjects.end(), g);	//busca g en el vector
	if ( it == m_gameObjects.end() )
		throw std::logic_error("Not found while removing object");  
	m_gameObjects.erase(it);


	uint32_t x = g->getX();
	uint32_t y = g->getY();
	if ( m_objMatrix[x][y] != g )
		throw std::logic_error("Not located in the Object Matrix");
	m_objMatrix[x][y] = nullptr;


	if (g->isPlayer())				//si g (lo k elimino) es jugador, toma nota
		m_thereIsAPlayer = false;		//condicion de salida del game loop

	STDP::sout << "Hi\n";
	STDP::Refrescar();

   
	delete g;				//borra el gameObject en cuestion de la mem dinamica

	STDP::sout << "Hi\n";
	STDP::Refrescar();
}


void CScene::moveGameObject(CGameObject *g) {
	if (g->wantsToMove()) {		//los enemigos siempre piden moverse, los wall no
		uint8_t x  = g->getX();
		uint8_t y  = g->getY();
		uint8_t nx = g->getNextX();
		uint8_t ny = g->getNextY();
	  

		CGameObject *gdest = m_objMatrix[nx][ny];
		if (gdest == nullptr) {					//si el destino está vacio, se añade al mapa, y al final se mueve
			m_objMatrix[x][y]   = nullptr;
			m_objMatrix[nx][ny] = g;
		} else if ( g->isPlayer() && gdest->isMortal() ) {	//chocan jugador y enemigo, eliminando al jugador
			removeGameObject(g);
			return;             
		} else if ( g->isMortal() && gdest->isPlayer() ) {
			removeGameObject(gdest);
			return;             
		} else {				//si no hay destino vacio, iguala las coordenadas, evitando que se mueva
			nx = x; 
			ny = y;
		}
	
		g->setLocation(nx, ny);
	}
}

