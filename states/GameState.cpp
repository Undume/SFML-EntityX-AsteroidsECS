#include <GameState.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include "RenderSystem.hpp"
#include "InputPlayerSystem.hpp"
#include "MeteorSpawnerSystem.hpp"
#include "MovementSystem.hpp"
#include "ShootingSystem.hpp"
#include "BoundariesCheckingSystem.hpp"
#include "CollisionSystem.hpp"
#include "ImpactsController.hpp"
#include "Utility.hpp"

static sf::Int32 MS_PER_UPDATE = 10.0;

GameState::GameState(StateStack& stack, Context context)
: State(stack, context),
_eventManager(),
_entityManager(_eventManager),
_systemManager(_entityManager, _eventManager),
_bulletPoolBuilder(30, _entityManager),
_asteroidPoolBuilder(100,50,20, _entityManager),
_shipBuilder(),
_lag(0)
{
    createEntities();
    createSystems();
}


bool GameState::update(sf::Time dt)
{
    systemsUpdate();
	return true;
}

void GameState::systemsUpdate()
{
    _systemManager.update<MeteorSpawnerSystem>(MS_PER_UPDATE);
	_systemManager.update<InputPlayerSystem>(MS_PER_UPDATE);
    _systemManager.update<ShootingSystem>(MS_PER_UPDATE);
    _systemManager.update<MovementSystem>(MS_PER_UPDATE);
    _systemManager.update<BoundariesCheckingSystem>(MS_PER_UPDATE);
    _systemManager.update<CollisionSystem>(MS_PER_UPDATE);
    _systemManager.update<RenderSystem>(MS_PER_UPDATE);
}

bool GameState::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            _keyHandler.updateKey(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            _keyHandler.updateKey(event.key.code, false);
            break;
        default:
            break;
    }
    return true;
}

void GameState::createSystems()
{
    _systemManager.add<RenderSystem>(getContext().window);
    _systemManager.add<InputPlayerSystem>(&_keyHandler);
	_systemManager.add<MeteorSpawnerSystem>(&_asteroidPoolBuilder);
    _systemManager.add<MovementSystem>();
    _systemManager.add<ShootingSystem>(&_bulletPoolBuilder);
    _systemManager.add<BoundariesCheckingSystem>();
    sf::Vector2u screenSize =getContext().window->getSize();
    _systemManager.add<CollisionSystem>(&_entityManager,&screenSize);
    _systemManager.configure();
}

void GameState::createEntities()
{
    _shipBuilder.buildShip(pew::ShipControllerType::PLAYER, sf::Vector2f(80.f,40.f), sf::Color::Green, sf::Vector2f(pew::ScreenSize::width*0.5f, pew::ScreenSize::height*0.9f), 0, _entityManager);
    _shipBuilder.buildShip(pew::ShipControllerType::AI_OPPONENT, sf::Vector2f(80.f,40.f), sf::Color::Red, sf::Vector2f(pew::ScreenSize::width*0.5f, pew::ScreenSize::height*0.1f), 180, _entityManager);
    _meteorSpawnerBuilder.spawnMeteorSpawner(sf::Vector2f(pew::ScreenSize::width * -0.1f, pew::ScreenSize::height*0.8f), 315, 3*1000., _entityManager);
    _meteorSpawnerBuilder.spawnMeteorSpawner(sf::Vector2f(pew::ScreenSize::width * 1.1f, pew::ScreenSize::height*0.8f), 225, 3*1000., _entityManager);
    _meteorSpawnerBuilder.spawnMeteorSpawner(sf::Vector2f(pew::ScreenSize::width * -0.1f, pew::ScreenSize::height*0.2f), 45, 3*1000., _entityManager);
    _meteorSpawnerBuilder.spawnMeteorSpawner(sf::Vector2f(pew::ScreenSize::width * 1.1, pew::ScreenSize::height*0.2f), 135, 3*1000., _entityManager);
}
