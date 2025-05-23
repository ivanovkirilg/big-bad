#ifndef SRC_PRINTER
#define SRC_PRINTER

#include <string>
class Printer
{
public:
    void print(const char* file_str);
    void readASCII();
    void transformUppercase();
    void transformLowercase();
    void limitWidthLineInput();
};

#endif // SRC_PRINTER
