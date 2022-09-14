#include <iostream>
#include <random>
#include <string>

int getRandomInt(int min, int max) {
    std::random_device os_seed;
    uint_least32_t seed = os_seed();

    std::mt19937 generator(seed);
    std::uniform_int_distribution<uint_least32_t> distribute(min, max);

    return (int)distribute(generator);
}

void clearConsole() {
    #if defined _WIN32
    system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    system("clear");
    #endif
}

void say(std::string message)
{
    std::cout << message << std::endl;
}

int main()
{
    int money = 5;
    int goal = 7;

    while (true)
    {
        clearConsole();
        int dice1 = getRandomInt(1, 6);
        int dice2 = getRandomInt(1, 6);
        int total = dice1 + dice2;
        
        say("Money: " + std::to_string(money) + "$");
        say("You need more than " + std::to_string(goal) + "with two dices of 6 in order to double your money");
        say(" You have to roll 2 dices " + std::to_string(dice1) + " + " + std::to_string(dice2) + " = " + std::to_string(total)); 
            

        if (total > goal)
        {
            money *= 2; // money = money * 2;
            goal = total;
        say("You win !");
        }
        else
        {
            money = 5;
            goal = 7;
            say("You lose !");
        }
        say("Press Enter to continue or any other key to stop.");
        if (std::cin.peek() != '\n') {
                break;
                return 0;
            }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
