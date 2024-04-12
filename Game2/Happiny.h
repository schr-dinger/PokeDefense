#pragma once
class Happiny : public Tower
{
public:
	float BuffTimer = 0.0f;
	ObRect* FullBuffBar;

	ObRect* RealBuffBar;

	Happiny();
	~Happiny();

	// Tower을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

