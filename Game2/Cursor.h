#pragma once

enum class Mstate
{
	D,
	G,
	L
};

class Cursor
{
public:
	GameObject* Mouse;
	ObImage* Default;
	ObImage* Grab;
	ObImage* Letgo;
	Mstate mstate;
	float GrabTimer = 0.0f;

	Cursor();
	~Cursor();
	void Release();
	void Update();
	void LateUpdate();
	void Render();


	void D();
	void G();
	void L();
};

