#include "app.h"


int main( int, char** )
{
  App& app = App::Instance();

  app.init("Ray Tracing", 520, 520);
  app.run();
  app.end();

  return 0;
}