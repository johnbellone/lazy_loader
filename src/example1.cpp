#include <thunk/lazyloader.hpp>

/**
 * @brief An example application object which contains lazyloaded
 * parameters. 
 */
class Application
{
public:
  /**
   * @brief Destructor.
   */
  ~Application();

  /**
   * @brief Default constructor.
   */
  Application()
    : m_square()
  {

  }

  /**
   * @brief Copy constructor.
   */
  Application(const Application& app)
  {

  }
private:
  thunk::LazyLoader<Square> m_square;
};

int main(int argc, char* argv[])
{


  return 0;
}
