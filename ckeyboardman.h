#ifndef __CKEYBOARDMAN_H__
#define __CKEYBOARDMAN_H__


class CKeyboardMan {
public:
   	~CKeyboardMan();
   	static CKeyboardMan& p();	//devuelve una instancia a esta clase, asi puedo consultar el atributo m_lastKeyPressed

	void update();				//Obtiene Tecla
   	char getLastKeyPressed();	//devuelve el atributo
   	void clear();				//vacia el buffer de teclado

private:
	CKeyboardMan();			//singleton, nadie de fuera puede crear un objeto de esta clase, se hace atraves del metodo p()
   	char m_lastKeyPressed;	//almacena la ultima tecla pulsada
};


#endif