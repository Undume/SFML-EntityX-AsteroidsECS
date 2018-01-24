#include <State.hpp>
#include <StateStack.hpp>


State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts)
: window(&window)
, textures(&textures)
, fonts(&fonts)
{
}

State::State(StateStack& stack, Context context)
:_stack(&stack)
, _context(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
	_stack->pushState(stateID);
}

void State::requestStackPop()
{
	_stack->popState();
}

void State::requestStateClear()
{
	_stack->clearStates();
}

State::Context State::getContext() const
{
	return _context;
}

void State::onActivate()
{
    
}

void State::onDestroy()
{
    
}
void State::draw()
{
    
}
