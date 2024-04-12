#pragma once
class Bellsprout : public Bloon
{
public:

	Bellsprout();
	~Bellsprout();

	// Bloon을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

