#pragma once
class Bellsprout : public Bloon
{
public:

	Bellsprout();
	~Bellsprout();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

