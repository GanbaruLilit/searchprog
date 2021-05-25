#include "Pageloader.h"

#include <iostream>

int main()
{
    Pageloader loader;
    Loadresult res = loader.load("http://curl.se/libcurl/c/");
    std::cout << res.getstatus() << "\n";
    std::cout << *res.getbody().get();
}