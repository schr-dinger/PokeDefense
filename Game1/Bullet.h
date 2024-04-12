#pragma once
class Bullet
{
public:
	ObRect arrow;
	float scalar;

	Vector2 fireDir;

	float gravity;

public:
	Bullet();
	~Bullet();
	void Update(ObRect rc);
	void LateUpdate();
	void Render();

	bool Shoot(ObRect rc, float scalar, Vector2 firePos);
};

