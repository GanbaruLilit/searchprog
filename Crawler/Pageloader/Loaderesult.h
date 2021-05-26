#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H

#include <string>
#include <memory>

class Loadresult
{
private:
    /**
     * stores the response body
     */
    std::shared_ptr<std::string> body;
    /**
     * stores the response status
     * */
    int status;
public:
      Loaderesult(std::shared_ptr<std::string> body, int status);
      std::shared_ptr<std::string> getbody() const;
      long getstatus() const;  
};

#endif
