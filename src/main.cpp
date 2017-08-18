#include <cassert>
#include <memory>
#include <ctime>

#include "app/Game.hpp"

int main(int /* argc */, char * /* argv */[])
{
  assert(MAX_START_COUNT <= (GAMEBOARD_COLS * GAMEBOARD_ROWS));

  // Init random
  std::srand(std::time(0));

  std::shared_ptr<Game> g(new Game());

  while (true)
  {
    g->drawGameBoard();

    g->update();
    // system("clear");

    if (g->getKey() == 'q')
    {
      std::string ans;
      std::cout << "Do you want to exit game? [y/n] ";
      while(std::cin >> ans)
      {
        std::cout << "[y/n]: ";
        if ((ans == "y") || (ans == "n"))
        {
          break;
        }
      }
      if (ans == "y")
      {
        break;
      }
    }
  }

  return 0;
}

