#pragma once

#include "D3DBitmap.h"
#include "..\D3DSys.h"
#include "..\D3DInput.h"
#include "..\D3DShaderManager.h"
#include "..\D3DText.h"

class D3DUI
{
public:
	//
	D3DUI();
	~D3DUI();

	bool Init(D3DSys* d3d, int scrWidth, int scrHeight, int chatWidth, int chatHeight, const XMMATRIX &baseView, int posY, int posX);
	bool InitChat(D3DSys* d3d);

	void SetPosition(int x, int y);
	bool Render(D3DSys* d3d, D3DShaderManager* sMgr, XMMATRIX &orthoMatrix);
	void KeyPressUpdate(int key);
	bool UpdateChatBar();
	void CheckForChatMessage(char* message, bool &newMessage);
	bool AddChatMessageFromServer(char* message, int ID);
	//void KeyPressUpdate

private:

	bool AddChatMessage();
	void AddChatMessageForServer();

	int m_WindowXPos, m_WindowYPos;
	D3DBitmap* m_ChatWindowBackground;
	D3DBitmap* m_RocketLauncher;
	ID3D11DeviceContext* m_context;
	XMMATRIX m_baseViewMatrix;
	D3DText* m_Text;
	int m_TextEntryAreaPos;

	char m_chatBarString[50];
	char m_chatString1[50];
	char m_chatString2[50];
	char m_chatString3[50];
	char m_chatString4[50];
	char m_chatString5[50];
	char m_chatString6[50];
	char m_chatString7[50];
	bool m_newMessage;
	char m_serverMessage[50];

};

 // !D3DUI_H