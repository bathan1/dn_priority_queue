#include <exceptions/EmptyException.hpp>

const char* EmptyException::what() const noexcept {
  return message.c_str();  
}