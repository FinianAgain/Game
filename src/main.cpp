#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

auto window = sf::RenderWindow{ { 1920u, 1080u }, "2D Game" };  // Where everything gets rendered to

class EventHandler {
    // Contains all the logic for handling input, etc
public:
    static void handleInput(sf::Event event) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
};

class Creature {
    // general creature class
public:
    int health;
    sf::Vector2f position;
    Vector2f spriteOrigin;
    Vector2f spriteScale;
    Texture creatureSprite;
    Sprite creature;

    void initialize(int init_health, Vector2f init_pos, Vector2f origin, Vector2f scale,string textures) {
        // initialize all the variables for the creature
        cout << "Player initializing...";
        health = init_health;
        position = init_pos;
        spriteOrigin = origin;
        spriteScale = scale;
        textures = textures;
        creatureSprite.loadFromFile(textures);
        creature.setTexture(creatureSprite);
        creature.setOrigin(spriteOrigin);
        creature.setScale(spriteScale);
        creature.setPosition(position);

    }
    void move(Vector2f displacement) {
        position += displacement;
    }
    void updateHealth(int amount) {
        health += amount;
    }
    void update() {
        creature.setPosition(position);
    }
    Sprite getSprite() const {
        return creature;
    }
};

class Player : public Creature {
    // Player class...not quite sure what needs to go here yet
public:
    Player() = default;
};

int main() {
    // Initialization
    window.setFramerateLimit(144);
    Player player;
    player.initialize(100, Vector2f(500, 500), Vector2f(6, 26),Vector2f(10.f,10.f), R"(C:\Users\Finn\CLionProjects\Game\sprites\base_clothed.png)");

    // Game loop
    while (window.isOpen()) {
        // Input handling
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            EventHandler::handleInput(event);
        }

        // Rendering and Updates
        window.clear();
        player.move(Vector2f(1.,1.));
        player.update();
        window.draw(player.getSprite());
        window.display();
    }
}