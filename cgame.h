#ifndef __CGAME_H__
#define __CGAME_H__


//#include <vector>

//class CGameObject;
class CKeyboardMan;		//forward declarations, solo necesito saber k existe (solo uso un puntero)
class CScene;


class CGame {
public:
	CGame();	//crea escena (pantalla de juego). Tambien podria ser privado para k nadie cree, solo el metodo run()
	~CGame();

	void run();		//llamado desde el main, tiene el game loop

	void update();	//metodos de un game loop clasico
	void draw();	
private:
	CKeyboardMan* m_KeyMan;		//referencia al manager de teclas. Los objetos k consulten teclas (CGame para q, CPlayer para w-a-s-d ) deben hacerlo así
	CScene*       m_scene;		//puntero a la scena

	void timeWait();	//para esperar entre fotogramas y que no vaya acelerado. Calcula delta time
};


#endif