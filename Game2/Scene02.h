#pragma once

#include "Cursor.h"

class Scene02 : public Scene
{
public:
	ObImage* Town1;
	ObImage* Town2;
	ObImage* Lab;
	ObImage* ProfessorOW;
	ObImage* PlayerS;
	ObImage* PlayerN;
	ObImage* CynthiaS;
	ObImage* CynthiaN;

	ObImage* TextB;
	ObImage* Professor;
	ObImage* Cynthia;

	ObImage* Bang;
	ObImage* Ques;


	ObRect* TextH;
	ObRect* LabH;
	ObRect* GameH;

	int TextN = -1;
	bool inLab = false;


	wstring battleMes;
	int mesIndex;
	float mesTime;

	ObImage* Arrow[2];

	Cursor* mouse;

	ObImage* Orb;
	ObImage* OrbBase;



public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

