#pragma once
class Tower : public Entity
{
public:
	enum class NEWS
	{
		E,
		NE,
		N,
		NW,
		W,
		SW,
		S,
		SE
	};

	enum class TYPE
	{
		FireAttack,
		GrassAttack,
		WaterAttack
	};

	ObImage* MoveS[8];
	ObImage* AttackS[8];
	ObImage* MoveL[8];
	ObImage* AttackL[8];


	NEWS state;
	TYPE AtType;
	//GameObject* Cen;
	ObCircle* Range;
	ObCircle* Select;
	bool isShooting = false;
	float ratio = 1.0f;
	bool Evolved = false;
	float range;
	

	//Attack
	ObCircle* FireHit;
	ObImage* FireA;
	ObImage* GrassA;
	ObImage* WaterA;
	float AtTimer;
	float AtSp;
	float NormalSp;
	float FastSp;
	float SlowSp;


	int AtPw;
	Vector2 distance;
	Vector2 dir;
	queue<Bloon*> Target;

	bool Placed = false;
	bool Holding = false;

	ObImage* PowerUp;
	bool PowerUped = false;
	float PowerUpTimer = 0.0f;
	float PowerMulti = 1.0f;


	//ObTileMap* mapT;
	//Int2 tile;
	bool RangeCheck = false;



	Tower();
	~Tower();

	virtual void Release()=0;
	virtual void Update()=0;
	virtual void LateUpdate()=0;
	virtual void Render()=0;

	void E();
	void NE();
	void N();
	void NW();
	void W();
	void SW();
	void S();
	void SE();

	bool ShootFire();
	bool ShootGrass();
	bool ShootWater();

};

