#include "Luncher.hh"

int main(int argc, char **argv)
{
    Luncher *arcade = new Luncher();

    if (argc < 3 || !arcade->setGraphic(argv[1]) ||
        !arcade->setGame(argv[2]))
      return -1;
    arcade->runGame();
    delete arcade;
    return 0;
}
