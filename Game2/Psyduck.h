#pragma once
class Psyduck : public Bloon
{
public:
	Psyduck();
	~Psyduck();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

