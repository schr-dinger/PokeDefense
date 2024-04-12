#pragma once
class Roserade : public Bloon
{
public:

	Roserade();
	~Roserade();

	// Bloon을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
};

