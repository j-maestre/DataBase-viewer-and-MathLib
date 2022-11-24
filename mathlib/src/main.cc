#include "app.h"


int main( int, char** )
{
  App& app = App::Instance();

  app.init("Hola como estas", 920, 920);
  app.run();
  app.end();

  return 0;
}