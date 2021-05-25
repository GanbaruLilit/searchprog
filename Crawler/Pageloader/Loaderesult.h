#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H

#include <string>


class Loadresult
{
private:
    /**
     * stores the response body
     */
    std::string body;
    /**
     * stores the response status
     * */
    int status;
public:
      Loaderesult(const std::string& body, int status);
      std::string getbody() const;
      long getstatus() const;
};

#endif
