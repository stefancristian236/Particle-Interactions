#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

int main () {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopMode, "Particles Interaction", sf::Style::Fullscreen);
    bool isFullscreen = true; 

    sf::RectangleShape rectangle({750.0f, 550.0f});
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(2.5f);


    sf::View view(sf::FloatRect(0, 0, 1080, 1920)); 
    window.setView(view);

    auto updateView = [&](const sf::Vector2u& windowSize) {
        float targetAspectRatio = 1080.0f / 1920.0f; 
        float windowAspectRatio = static_cast<float>(windowSize.x) / windowSize.y;

        sf::View newView(sf::FloatRect(0, 0, 1080, 1920)); 

        if (windowAspectRatio > targetAspectRatio) {
            float viewportWidth = targetAspectRatio / windowAspectRatio;
            float viewportLeft = (1.0f - viewportWidth) / 2.0f;
            newView.setViewport(sf::FloatRect(viewportLeft, 0.0f, viewportWidth, 1.0f));
        } else if (windowAspectRatio < targetAspectRatio) {          
            float viewportHeight = windowAspectRatio / targetAspectRatio;
            float viewportTop = (1.0f - viewportHeight) / 2.0f;
            newView.setViewport(sf::FloatRect(0.0f, viewportTop, 1.0f, viewportHeight));
        }
        window.setView(newView);

        rectangle.setSize({
            newView.getSize().x * 0.7f,
            newView.getSize().y * 0.7f
        });
        rectangle.setPosition(
            (newView.getSize().x - rectangle.getSize().x) / 2.0f,
            (newView.getSize().y - rectangle.getSize().y) / 2.0f
        );
    };

    updateView(window.getSize()); 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {
                updateView(window.getSize());
            }
        }

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }
    return 0;
}