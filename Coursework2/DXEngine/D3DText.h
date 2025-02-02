#pragma once

#include "Defines.h"
#include "D3DSys.h"
#include "Objects/D3DFont.h"
#include "Shaders/D3DFontShader.h"

const int MAX_SENTENCES = 20;

class D3DText
{
public:

	D3DText();
	D3DText(const D3DText&){}
	~D3DText();

	bool Init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, HWND hwnd, int screenWidth, int screenHeight, const XMMATRIX &baseViewMatrix);
	bool Render(ID3D11DeviceContext* deviceContext, const XMMATRIX &orthoMatrix);
	bool CreateSentence(D3DSys* d3d, int ID, int maxLength, char* text, int posX, int posY, float r, float g, float b);
	bool UpdateSentence(int ID, char*, int, int, float, float, float, ID3D11DeviceContext*);
	
	//bool SetMousePosition(int, int, ID3D11DeviceContext*);
	//bool SetFPS(int, ID3D11DeviceContext*);
	//bool SetCPU(int, ID3D11DeviceContext*);
	
private:

	struct SentanceType
	{
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		int vertexCount, indexCount, maxLength;
		float r,g,b;
		bool active;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

	bool InitSentence(int ID, int, ID3D11Device*);

	void ReleaseSentence(int ID);
	bool RenderSentence(ID3D11DeviceContext* deviceContext, int ID, const XMMATRIX &orthoMatrix);

	D3DFont* m_Font;
	D3DFontShader* m_FontShader;
	int m_screenWidth, m_screenHeight;
	XMMATRIX m_baseViewMatrix;
	XMMATRIX m_worldMatrix;

	SentanceType* m_sentenceArray;

	SentanceType* m_sentence1;
	SentanceType* m_sentence2;

	SentanceType* CPUText;
	SentanceType* FPSText;
};

