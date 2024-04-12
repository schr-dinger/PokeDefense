#pragma once
class Milotic : public Bloon
{
public:

	Milotic();
	~Milotic();

	// Bloon을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
};

