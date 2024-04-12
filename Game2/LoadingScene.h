#pragma once
class LoadingScene : public Scene
{
public:
	ObImage* pika;
	ObImage* bg;

	ObRect* bar;

	thread* th;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

