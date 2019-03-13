#ifndef __CRENDERERSTDP2_H__
#define __CRENDERERSTDP2_H__


#include "crenderer.h"
#include <cstdint>


class CRendererSTDP2 : public CRenderer {
public:
	CRendererSTDP2();
	~CRendererSTDP2();

	void clearScreen() const;
	void refresh() const;

	void drawEnemyLR(uint8_t x, uint8_t y) const;
	void drawEnemyWander(uint8_t x, uint8_t y) const;
	void drawPlayer(uint8_t x, uint8_t y) const;
	void drawWallNormal(uint8_t x, uint8_t y) const;
	void drawWallMortal(uint8_t x, uint8_t y) const;
	void drawGameOver(uint8_t x, uint8_t y) const;

	char getKey() const;

private:

};


#endif