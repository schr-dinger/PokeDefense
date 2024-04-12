#pragma once
class Piplup : public Tower
{
public:
	//ObImage* IceFloor;
	ObImage* IceParticle;

	ObCircle* IceHit;

	Piplup();
	~Piplup();
	// Tower을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

