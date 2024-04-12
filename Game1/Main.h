#pragma once
#define FMAX 14
#define JMAX 20
class Main : public Scene
{
private:
	ObImage* floors[FMAX];
	ObImage* jelly[JMAX];
	Cookie* sparkle;

	ObImage* bg1;
	ObImage* bg2;

	float test;
	float timer;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
