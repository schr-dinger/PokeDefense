#pragma once
class Rattata : public Bloon
{
public:
	Rattata();
	~Rattata();

	// Bloon을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

