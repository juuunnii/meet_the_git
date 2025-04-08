#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

// Абстрактный класс для раскопок
class Excavation {
protected:
    std::string name;       // Название экспедиции
    std::string terrainType; // Тип местности
    int cost;               // Стоимость экспедиции

public:
    Excavation(std::string n, std::string t, int c) : name(n), terrainType(t), cost(c) {}

    // Чисто виртуальные методы
    virtual std::string excavate() = 0; // Раскопки
    virtual void effect() = 0; // Эффект при раскопках
    virtual void printText() = 0; // Текст при раскопках

    std::string getName() const { return name; }
    std::string getTerrainType() const { return terrainType; }
    int getCost() const { return cost; }
};

// Конкретный класс для подводных раскопок
class ExcavationUnderWater : public Excavation {
public:
    ExcavationUnderWater() : Excavation("Underwater Expedition", "Underwater", 100) {}

    std::string excavate() override {
        int chance = rand() % 100;
        if (chance < 30) {
            return "Ammonite";
        }
        else if (chance < 60) {
            return "Coral Fossil";
        }
        else {
            return "Sea Shell";
        }
    }

    void effect() override {
        std::cout << "Water pressure makes it harder to dig!\n";
    }

    void printText() override {
        std::cout << "You're tired, but you have to work!\n";
    }
};

// Конкретный класс для раскопок в пещере
class ExcavationCave : public Excavation {
public:
    ExcavationCave() : Excavation("Cave Expedition", "Cave", 150) {}

    std::string excavate() override {
        int chance = rand() % 100;
        if (chance < 40) {
            return "Dinosaur Bone";
        }
        else if (chance < 70) {
            return "Cave Painting";
        }
        else {
            return "Ancient Tool";
        }
    }

    void effect() override {
        std::cout << "Darkness slows you down!\n";
    }

    void printText() override {
        std::cout << "It's spooky in here!\n";
    }
};

// Класс игрока
class Player {
private:
    int money;
    int food;
    std::vector<std::string> equipment;
    std::vector<std::string> loot;

public:
    Player() : money(500), food(10) {
        equipment.push_back("Brush");
    }

    void addMoney(int amount) { money += amount; }
    void spendMoney(int amount) { money -= amount; }
    void addFood(int amount) { food += amount; }
    void consumeFood() { food--; }
    void addEquipment(std::string item) { equipment.push_back(item); }
    void addLoot(std::string item) { loot.push_back(item); }

    int getMoney() const { return money; }
    int getFood() const { return food; }
    std::vector<std::string> getEquipment() const { return equipment; }
    std::vector<std::string> getLoot() const { return loot; }

    void clearLoot() { loot.clear(); }
};

// Класс базы
class Base {
public:
    void visitShop(Player& player) {
        std::cout << "Welcome to the shop!\n";
        std::cout << "1. Buy Shovel (50 money)\n";
        std::cout << "2. Buy Pickaxe (100 money)\n";
        std::cout << "3. Buy Food (10 money)\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (player.getMoney() >= 50) {
                player.spendMoney(50);
                player.addEquipment("Shovel");
                std::cout << "Shovel purchased!\n";
            }
            else {
                std::cout << "Not enough money!\n";
            }
            break;
        case 2:
            if (player.getMoney() >= 100) {
                player.spendMoney(100);
                player.addEquipment("Pickaxe");
                std::cout << "Pickaxe purchased!\n";
            }
            else {
                std::cout << "Not enough money!\n";
            }
            break;
        case 3:
            if (player.getMoney() >= 10) {
                player.spendMoney(10);
                player.addFood(1);
                std::cout << "Food purchased!\n";
            }
            else {
                std::cout << "Not enough money!\n";
            }
            break;
        default:
            std::cout << "Exiting shop.\n";
            break;
        }
    }

    void visitMuseum(const Player& player) {
        std::cout << "Welcome to the museum!\n";
        std::cout << "Your loot:\n";
        for (const auto& item : player.getLoot()) {
            std::cout << "- " << item << "\n";
        }
    }

    void sellLoot(Player& player) {
        int total = 0;
        for (const auto& item : player.getLoot()) {
            total += 50; // Каждый лут стоит 50 денег
        }
        player.addMoney(total);
        player.clearLoot();
        std::cout << "Sold all loot for " << total << " money!\n";
    }
};

// Функция для сохранения прогресса
void saveProgress(const Player& player) {
    std::ofstream file("save.txt");
    if (file.is_open()) {
        file << player.getMoney() << "\n";
        file << player.getFood() << "\n";
        for (const auto& item : player.getEquipment()) {
            file << item << "\n";
        }
        file << "###\n"; // Разделитель
        for (const auto& item : player.getLoot()) {
            file << item << "\n";
        }
        file.close();
        std::cout << "Progress saved!\n";
    }
    else {
        std::cout << "Unable to save progress!\n";
    }
}

// Функция для загрузки прогресса
void loadProgress(Player& player) {
    std::ifstream file("save.txt");
    if (file.is_open()) {
        int money, food;
        file >> money >> food;
        player = Player();
        player.addMoney(money - 500); // Изначально у игрока 500 денег
        player.addFood(food - 10);    // Изначально у игрока 10 еды

        std::string line;
        while (std::getline(file, line)) {
            if (line == "###") break;
            if (!line.empty()) player.addEquipment(line);
        }
        while (std::getline(file, line)) {
            if (!line.empty()) player.addLoot(line);
        }
        file.close();
        std::cout << "Progress loaded!\n";
    }
    else {
        std::cout << "No save file found!\n";
    }
}

// Основная функция
int main() {
    srand(static_cast<unsigned>(time(0)));
    Player player;
    Base base;
    loadProgress(player);

    while (true) {
        std::cout << "\n1. Go on an expedition\n";
        std::cout << "2. Visit shop\n";
        std::cout << "3. Visit museum\n";
        std::cout << "4. Sell loot\n";
        std::cout << "5. Save and exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Choose expedition type:\n";
            std::cout << "1. Underwater\n";
            std::cout << "2. Cave\n";
            std::cout << "Choose: ";

            int expChoice;
            std::cin >> expChoice;

            Excavation* expedition = nullptr;
            if (expChoice == 1) {
                ExcavationUnderWater underwaterExpedition;
                expedition = &underwaterExpedition;
            }
            else if (expChoice == 2) {
                ExcavationCave caveExpedition;
                expedition = &caveExpedition;
            }
            else {
                std::cout << "Invalid choice!\n";
                continue;
            }

            if (player.getMoney() < expedition->getCost()) {
                std::cout << "Not enough money for the expedition!\n";
                continue;
            }

            player.spendMoney(expedition->getCost());
            std::cout << "Starting " << expedition->getName() << "!\n";

            while (player.getFood() > 0) {
                std::cout << "\nFood left: " << player.getFood() << "\n";
                std::cout << "1. Dig\n";
                std::cout << "2. Return to base\n";
                std::cout << "Choose: ";

                int digChoice;
                std::cin >> digChoice;

                if (digChoice == 1) {
                    player.consumeFood();
                    expedition->printText();
                    expedition->effect();
                    std::string foundItem = expedition->excavate();
                    player.addLoot(foundItem);
                    std::cout << "You found: " << foundItem << "\n";
                }
                else {
                    break;
                }
            }

            if (player.getFood() == 0) {
                std::cout << "Out of food! Returning to base.\n";
            }
        }
        else if (choice == 2) {
            base.visitShop(player);
        }
        else if (choice == 3) {
            base.visitMuseum(player);
        }
        else if (choice == 4) {
            base.sellLoot(player);
        }
        else if (choice == 5) {
            saveProgress(player);
            break;
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}