#pragma once
class Entity
{
public:
	Entity();
	virtual ~Entity();
	GameObject* Cen;

	virtual void Render() {};
};

class EntityManager : public Singleton<EntityManager>
{
public:
	list<Entity*> entities;

	static bool Compare(Entity* entity1, Entity* entity2)
	{
		return entity1->Cen->GetWorldPos().y > entity2->Cen->GetWorldPos().y ? true : false;
	}

	void Sort()
	{
		entities.sort(Compare);
	}

	void Render()
	{
		for (auto& entity : entities)
		{
			entity->Render();
		}
	}
};

