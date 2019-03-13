#ifndef __CSCENE_H__
#define __CSCENE_H__


#include <vector>			//para la clase vector de la libreria STL
#include "cgameobject.h"
class CMazeFact;		//forward declaration


class CScene : public CGameObject {		//implementa todo lo k vemos en pantalla
public:
	typedef std::vector<CGameObject*> TObjVec;		//define un tipo vector de punteros, tendrá todos los items de la escena

	CScene();
	~CScene();
	
	virtual void update();		//override?
	virtual void draw();		//override?

	void initialize(CMazeFact &f);			//se inicializa con la fabrica por referencia
	void addGameObject(CGameObject* o, uint8_t x, uint8_t y);	
	void removeGameObject(CGameObject* o);		
	void moveGameObject(CGameObject *g);		

	bool thereIsAPlayer() { return m_thereIsAPlayer; }	//const?
	
	bool isPlayer()       { return false; }		//const override?
	bool isMortal()       { return false; }		//const override?

private:
	TObjVec		 m_gameObjects;			//vector con los 43 items (entidades: 40 muros, 2 enemigos, 1 player) de la scene
	CGameObject* m_objMatrix[13][13];	//matriz con punteros a gameobject, objetos de cada casilla, para las colisiones
	bool         m_thereIsAPlayer;		//condicion de salida del loop, si no hay jugador termina juego
};


#endif