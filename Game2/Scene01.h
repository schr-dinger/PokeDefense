#pragma once

#include "Entity.h"


#include "Bloon.h"

#include "Magby.h"
#include "Bellsprout.h"
#include "Psyduck.h"
#include "Rattata.h"
#include "Purugly.h"
#include "Skuntank.h"
#include "Magmator.h"
#include "Victreebel.h"
#include "Golduck.h"
#include "Crobat.h"
#include "Ninetails.h"
#include "Roserade.h"
#include "Milotic.h"
#include "Togekiss.h"
#include "Garchomp.h"


#include "Tower.h"

#include "Turtwig.h"
#include "Piplup.h"
#include "Chimchar.h"
#include "Charmander.h"
#include "Bulbasaur.h"
#include "Squirtle.h"
#include "Caterpie.h"
#include "Happiny.h"
#include "Delibird.h"

#include "Ui.h"
#include "TextBar.h"
#include "Cursor.h"


#define MaxN 10
#define MaxTN 9
#define MaxBN 78


enum class WAVE
{
	wave0,
	wave1,
	wave2,
	wave3,
	wave4,
	wave5,
	wave6,
	wave7,
	wave8,
	wave9,
	wave10
};
class Scene01 : public Scene
{
private:
	ObTileMap* map;
	Int2 tile;
	bool Placing = false;

	//길찾기용 변수
	//vector<Tile*> PlWay;
	////이동시킬 위치
	//Vector2 plDest;
	//Vector2 plSour;
	//비율
	float   g;
	//
	Vector2 OgCam;

	//Tower
	Tower* towers[MaxTN];

	//Bloon
	Bloon* bloons[MaxBN];


	ObImage* RealMap;
	ObImage* RealMap2;

	Vector2 StartP = Vector2(285.0f, 385.0f);
	Vector2 EndP= Vector2(445.0f, 46.0f);

	WAVE wave;
	int WaveNum;

	bool GameStart = false;

	bool Waving = false;
	//Ui
	Ui* ui = new Ui;

	TextBar* text = new TextBar;

	ObImage* IceFloor;

	Cursor* mouse;



public:
	float WaveTimer = 0.0f;
	float ResetTimer = 0.0f;

	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;

	//void Wave0();
	//void Wave1();
	//void Wave2();
	//bool CheckDead();

};

