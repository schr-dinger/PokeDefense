#pragma once
#define RayN 36
class Bulbasaur : public Tower
{
public:
	ObTileMap* map;

	bool Casted = false;

	Vector2 Flowerpos[RayN];
	ObCircle* FlowerH[RayN];
	ObImage* Vines[RayN];
	ObImage* Flowers[RayN];

	Bulbasaur();
	~Bulbasaur();

	// Tower을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	void castRays(int NumRays );
	void castRay(Vector2 pos, float rayDX, float rayDY ,int j);
};

