#include "stdafx.h"

Entity::Entity()
{
	EntityManager::GetInstance()->entities.push_back(this);
}

Entity::~Entity()
{
	SafeDelete(Cen);
}
