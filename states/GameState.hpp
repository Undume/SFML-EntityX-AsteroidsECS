#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "entityx/System.h"

#include "KeyHandler.hpp"
#include "State.hpp"

#include "AsteroidPoolBuilder.hpp"
#include "BulletPoolBuilder.hpp"
#include "MeteorSpawnerBuilder.hpp"
#include "ShipBuilder.hpp"

class GameState : public State
{
public:
    GameState(StateStack& stack, Context context);
    
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);

private:
	void systemsUpdate();

    void createSystems();
    void createEntities();
    
    entityx::EventManager _eventManager;
    entityx::EntityManager _entityManager;
    entityx::SystemManager _systemManager;

    sf::Int32 _lag;

    KeyHandler _keyHandler;
    pew::AsteroidPoolBuilder _asteroidPoolBuilder;
    pew::BulletPoolBuilder _bulletPoolBuilder;
    pew::MeteorSpawnerBuilder _meteorSpawnerBuilder;
    pew::ShipBuilder _shipBuilder;
    
};

#endif // BOOK_GAMESTATE_HPP
