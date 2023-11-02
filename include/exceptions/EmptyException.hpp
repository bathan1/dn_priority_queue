#ifndef EMPTY_EXCEPTION
#define EMPTY_EXCEPTION

#include <exception>
#include <string>
class EmptyException : public std::exception {
  private:
    std::string message;

  public:
    EmptyException() {}
    EmptyException(const std::string& message): message(message) {}
    const char* what() const noexcept override;
};
#endif