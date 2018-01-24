#ifndef BOOK_STATE_HPP
#define BOOK_STATE_HPP

#include <StateIdentifiers.hpp>
#include <ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
	class RenderWindow;
}

class StateStack;

class State
{
	public:
		typedef std::unique_ptr<State> Ptr;

		struct Context
		{
								Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts);

			sf::RenderWindow*	window;
			TextureHolder*		textures;
			FontHolder*			fonts;
		};


	public:
							State(StateStack& stack, Context context);
		virtual				~State();

		virtual void		draw();
		virtual bool		update(sf::Time dt) = 0;
		virtual bool		handleEvent(const sf::Event& event) = 0;
        virtual void        onActivate();
        virtual void        onDestroy();


	protected:
		void				requestStackPush(States::ID stateID);
		void				requestStackPop();
		void				requestStateClear();

		Context				getContext() const;


	private:
		StateStack*			_stack;
		Context				_context;
};

#endif // BOOK_STATE_HPP
