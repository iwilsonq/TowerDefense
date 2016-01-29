#include <SFML-utils/Map.hpp>
#include <SFML-Book/Game.hpp>
#include <SFML-Book/ActionMap.hpp>

#include <SFML-Book/Configuration.hpp>

int main(int argc,char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(1600,900),"Example Tile");
    sfutils::VMap* map = sfutils::VMap::createMapFromFile("./map.json");
    sfutils::MapViewer viewer(window,*map);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)   // Close window : exit
                window.close();
        }
        window.clear();
        viewer.processEvents();
        viewer.update(clock.restart().asSeconds());
        viewer.draw();
        window.display();
    }
    return 0;
}

