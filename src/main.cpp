#include <lazyloader/lazyloader.hpp>
#include <square.hpp>

/**
 * @brief An example application object which contains lazyloaded
 * parameters. 
 */
class Application
{
public:
  ~Application() { }
  Application() : m_square() { }

  Application(const Application& r) : m_square(r.m_square) { }

  void init() { }

  void run() { }

private:
  thunk::lazy_loader<Square> m_square;
};

int main(int argc, char* argv[])
{
  Application app;

  app.init();
  
  return 0;
}
