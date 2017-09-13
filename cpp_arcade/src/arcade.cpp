#include "Luncher.hh"

void printFrame(IGraph *graph,int xStart,int yStart,int xEnd,int yEnd)
{
  int i;
  /* up, down, left, right */
  graph->setBox(xStart, yStart, games::CORNER, games::UP);
  graph->setBox(xEnd, yStart, games::CORNER, games::LEFT);
  graph->setBox(xStart, yEnd, games::CORNER, games::DOWN);
  graph->setBox(xEnd, yEnd, games::CORNER, games::RIGHT);
  for (i=yStart+1;i < yEnd;i++)
  {
    graph->setBox(xStart,i, games::BORDER, games::LEFT);
    graph->setBox(xEnd,i, games::BORDER, games::RIGHT);
  }
  for (i=xStart+1 ;i < xEnd;i++)
  {
    graph->setBox(i,yStart, games::BORDER, games::UP);
    graph->setBox(i,yEnd, games::BORDER, games::DOWN);
  }
}

void printStringList(Luncher *arcade, int xStart, int yStart,bool listGames)
{
  IGraph *graph = arcade->getGraphic();
  std::vector<std::string>  list;
  unsigned int              itr;
  unsigned int              selected;

  list = (listGames) ? arcade->getListGames() : arcade->getListGraphic();
  selected = (listGames) ? arcade->getGamesSelected() : arcade->getGraphicSelected();
  for (itr = 0; itr < list.size(); itr++)
  {
    if (itr == selected)
      printFrame(graph, xStart, yStart+itr*4, xStart+list[itr].size()+2, yStart+itr*4+2);
    graph->printStr(xStart+1, yStart+itr*4+1, list[itr]);
  }
}

void printScreen(Luncher *arcade)
{
  unsigned int itr;

  arcade->getGraphic()->printStr(3, 2, "Graphiques Lib");
  for (itr = 0; itr < 14; itr++)
    arcade->getGraphic()->setBox(itr+3,3, games::BORDER, games::DOWN);
  arcade->getGraphic()->printStr(32, 2, "Games");
  for (itr = 0; itr < 5; itr++)
    arcade->getGraphic()->setBox(itr+32,3, games::BORDER, games::DOWN);
  for (itr = 0; itr <= 100; itr++)
    arcade->getGraphic()->setBox(itr, 96, games::BORDER, games::DOWN);
  arcade->getGraphic()->printStr(3, 98, "p: play    2: Prev Lib    3: Next Lib    4: Prev Game    5: Next Game    8: Restart    9: Back");
}

int main(int argc, char **argv)
{
    Luncher *arcade = new Luncher();

    if (argc < 2)
      {
        std::cerr << "USAGE:\n  argument graphic library path" << std::endl;
        return -1;
      }
    if (!arcade->setGraphic(argv[1]) ||
        !arcade->initLuncher())
      return -1;
    while (!arcade->quit)
    {
      printScreen(arcade);
      printStringList(arcade, 1, 7, true);
      printStringList(arcade, 31, 7, false);
      arcade->getGraphic()->checkEvent(arcade);
      arcade->getGraphic()->refreshScreen();
    }
    delete arcade;
    return 0;
}
