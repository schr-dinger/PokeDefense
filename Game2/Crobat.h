#pragma once
class Crobat : public Bloon
{
public:
	ObImage* Absorb;



	Crobat();
	~Crobat();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

