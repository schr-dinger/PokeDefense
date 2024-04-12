#pragma once
class TextBar
{
public:
	ObImage* TextBase;

	ObImage* Professor;
	ObImage* Cynthia;
	ObImage* Mars;
	ObImage* Jupiter;
	ObImage* Cyrus;


	ObImage* HomeButton;

	int TurnN = -1;

	wstring battleMes;
	int mesIndex;
	float mesTime;

	ObImage* Arrow[2];

	ObImage* Giratina;
	ObImage* GiraEnter;
	ObImage* Lucas;
	float GiraTimer = 0.0f;

	ObImage* Orb;
	ObImage* OrbBase;
	
	ObImage* Ending;


	TextBar();
	~TextBar();
	void Release();
	void Update();
	void LateUpdate();
	void Render();

};

