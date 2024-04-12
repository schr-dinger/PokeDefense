#pragma once

#define MaxT 9
class Ui
{
public:
	ObImage* BaseUi;
	//ObImage* Roar;

	ObRect* SelectUi[3];
	ObCircle* UiHit[MaxT];
	ObImage* TowerUi[MaxT];
	ObImage* TowerUiBase[3];

	Vector4 uvbase = Vector4(0.0f, 0.0f, 0.5f, 1.0f);
	Vector4 uvevolved = Vector4(0.5f, 0.0f, 1.0f, 1.0f);




	Vector2 First = Vector2(-app.GetHalfWidth() + 177.8f + 355.0f-200.0f, 0.0f);
	Vector2 Second = Vector2(-app.GetHalfWidth() + 177.8f + 355.0f , 0.0f);
	Vector2 Third = Vector2(-app.GetHalfWidth() + 177.8f + 355.0f+200.0f, 0.0f);

	Vector2 SelectedPos[6];

	vector<int> Selectable;
	vector<int> TempSelected;
	vector<int> Selected;

	int k = -1;

	bool Firstturn = true;

	bool isChoosing = false;

	ObRect* NextWave;

	GameObject* CandyCen;
	ObRect* CandyHit;
	ObImage* Candy;
	int CandyN = 0;


	//
	int Life = 5;
	ObImage* Heart;
	ObImage* uiCandy;

	Ui();
	~Ui();
	void Release();
	void Update();
	void LateUpdate();
	void Render();

	void TempSelection();
	int MouseSelect();
};

