#pragma once
class Togekiss : public Bloon
{
public:
	ObImage* Shadow;


	Togekiss();
	~Togekiss();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

};

