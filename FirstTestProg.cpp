#include <iostream>
using namespace std;

class TestProg
{
  public:
    Print()
    {
      std::cout << "Hello World" << std::endl;
    };
};

int main(int argc, const char * argv[])
{
  TestProg testPrintObj;
  testPrintObj.Print();  // Should print "Hello world" without quotes.
  return 0;
}
