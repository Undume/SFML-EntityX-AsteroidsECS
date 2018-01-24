#ifndef BOOK_APPLICATION_HPP
#define BOOK_APPLICATION_HPP

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <StateStack.hpp>
#include <KeyHandler.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
public:
    void					run();
    Application();

private:
    void					processInput();
    void					update(sf::Time dt);
	void					render();

	void					updateStatistics(sf::Time dt);
	void					registerStates();


private:
    
    static const sf::Time	TimePerFrame;

    sf::RenderWindow		mWindow;
    TextureHolder			mTextures;
    FontHolder				mFonts;
    
    StateStack				mStateStack;
    KeyHandler              keyHandler;
    
    sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
};

#endif // BOOK_APPLICATION_HPP
