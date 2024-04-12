#pragma once
class Magmator : public Bloon
{
public:

	Magmator();
	~Magmator();

	// Bloon을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

