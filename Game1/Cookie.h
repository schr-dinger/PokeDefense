#pragma once
enum class CState
{
	RUN,
	JUMP,
	SLIDE
};

class Cookie
{
public:
	ObRect* col;
	ObImage* run;
	ObImage* slide;
	ObImage* jump;
	ObImage* landing;

	float gravity;

	CState state;
	bool isDoubleJump;
	bool isDamage;
	float timer;

public:
	Cookie();
	~Cookie();
	void Update();
	void Render();

	void Run();
	void Slide();
	void Jump();

	void TakeDamage();
};

