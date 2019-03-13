#include "cgame.h"
#include "ckeyboardman.h"	//ahora necesito incluir el .h del anterior forward declaration
#include "cscene.h"
//#include "StdPijo.h"	
#include <unistd.h>		//para usleep(ms) y sleep(seg)
#include <iostream>		
#include "cmazefactEasy.h"
//#include "cmazefactHard.h"

#include "crendererman.h"
#include "crenderer.h"


CGame::CGame() {
	CRendererMan::p();		//inicia el render

	m_KeyMan = &CKeyboardMan::p();	//obtiene referencia al teclado
	m_KeyMan->clear();

	m_scene = new CScene();		//creo la escena
	CMazeFactEasy f;			//creo una fabrica de un determinado tipo (de nivel facil o dificil)
	//CMazeFactHard f;
	m_scene->initialize(f);		//inicializa la escena pasandole la fabrica
}


void CGame::update() {
	m_KeyMan->update();		//actualiza teclado para ver como está (se consulta desde el bucle de run())
	m_scene->update();		//actualiza la escena
}


void CGame::draw() {
	CRendererMan::p().renderer().clearScreen();
	m_scene->draw();
	CRendererMan::p().renderer().refresh();
}


void CGame::timeWait() {		
	static long   t = clock();	//clock() devuelve el numero de ticks (cte) desde k el programa empezó
	const float fps = 30.0f;	

	long toWait = t + CLOCKS_PER_SEC / fps - clock();	//CLOCKS_PER_SEC constante 1000
	if (toWait > 0)
		usleep(toWait);			//espera los milisec indicados

	t = clock();				//t es static, actualizo su valor
}


void CGame::run() {
	do {
		update();	
		draw();		
		timeWait();
		if (m_KeyMan->getLastKeyPressed() == 'n')
			CRendererMan::p().switchRenderer();
	} while ( m_KeyMan->getLastKeyPressed() != 'q'
			&& m_scene->thereIsAPlayer() );
}


CGame::~CGame() {
	CRendererMan::p().renderer().drawGameOver(2, 6);
	
	delete m_scene;
	
	CRendererMan::p().renderer().refresh();		//para ver el texto de game over
	sleep(2);				//espera 2 seg
}

