#ifndef __CRENDERER_H__
#define __CRENDERER_H__


#include <cstdint>


class CRenderer {
public:
	virtual ~CRenderer() = default;			//destructor por defecto pero virtual, sino tendré un memory leak

	virtual void clearScreen() const = 0;
	virtual void refresh() const = 0;

	virtual void drawEnemyLR(uint8_t x, uint8_t y) const = 0;
	virtual void drawEnemyWander(uint8_t x, uint8_t y) const = 0;
	virtual void drawPlayer(uint8_t x, uint8_t y) const = 0;
	virtual void drawWallNormal(uint8_t x, uint8_t y) const = 0;
	virtual void drawWallMortal(uint8_t x, uint8_t y) const = 0;
	virtual void drawGameOver(uint8_t x, uint8_t y) const = 0;

	virtual char getKey() const = 0;
	
private:

};


#endif