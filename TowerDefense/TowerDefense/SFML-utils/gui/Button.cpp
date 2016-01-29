#include <SFML-utils/gui/Button.hpp>

namespace sfutils
{
    namespace gui
    {
        Button::Button(Widget* parent) : Widget(parent), _status(0)
        {
        }

        Button::~Button()
        {
        }

        void Button::click()
        {
            emit(event::ButtonPressed(*this));
            emit(event::ButtonReleased(*this));
        }

        bool Button::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)
        {
            bool res = false;
            if(event.type == sf::Event::MouseButtonPressed or event.type == sf::Event::MouseButtonReleased)
            {
                const sf::Vector2f pos = _position + parent_pos;
                const sf::Vector2f size = getSize();
                sf::FloatRect rect;

                rect.left = pos.x;
                rect.top = pos.y;
                rect.width = size.x;
                rect.height = size.y;

                if(rect.contains(event.mouseButton.x,event.mouseButton.y))
                {
                    if(event.type == sf::Event::MouseButtonPressed)
                    {
                        emit(event::ButtonPressed(*this));
                    }
                    else
                    {
                        emit(event::ButtonReleased(*this));
                    }
                    res = true;
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                const sf::Vector2f pos = _position + parent_pos;
                const sf::Vector2f size = getSize();
                sf::FloatRect rect;

                rect.left = pos.x;
                rect.top = pos.y;
                rect.width = size.x;
                rect.height = size.y;

                int old_status = _status;
                _status = 0;

                const sf::Vector2f mouse_pos(event.mouseMove.x,event.mouseMove.y);
                if(rect.contains(mouse_pos))
                {
                    _status|=Status::Hover;
                }

                if((old_status & Status::Hover) and not (_status & Status::Hover))
                    onMouseLeft();
                else if(not (old_status & Status::Hover) and (_status & Status::Hover))
                    onMouseEntered();

            }
            return res;
        }

        void Button::onMouseEntered()
        {
        }

        void Button::onMouseLeft()
        {
        }
    }
}
