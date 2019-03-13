#ifndef __CRENDERERMAN_H__
#define __CRENDERERMAN_H__


class CRenderer;
enum class TRenderer { STDP, STDP2 };


class CRendererMan {
public:
	~CRendererMan();

	static CRendererMan& p();
	CRenderer& renderer();
	void switchRenderer();

private:
	CRendererMan();

	CRenderer* m_renderer = nullptr;
	TRenderer m_selected = TRenderer::STDP;
};


#endif
