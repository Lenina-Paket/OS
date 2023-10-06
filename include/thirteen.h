#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class Thirteen { 
public:

   Thirteen();
   Thirteen(const size_t &n, unsigned char t = 0);
   Thirteen(const std::initializer_list< unsigned char> &t);
   Thirteen(const std::string &t);
   Thirteen(const Thirteen& other);
   Thirteen(Thirteen&& other) noexcept;
   virtual ~Thirteen() noexcept;

   bool operator> (const Thirteen &other) const;
   bool operator== (const Thirteen &other) const;
   bool operator!= (const Thirteen &other) const;
   bool operator>= (const Thirteen &other) const;
   bool operator< (const Thirteen &other) const;
   bool operator<= (const Thirteen &other) const;

   Thirteen operator+ (const Thirteen &other) const;
   Thirteen operator- (const Thirteen &other) const;
   Thirteen operator=(const Thirteen &other);
   Thirteen operator+= (const Thirteen &other);
   Thirteen operator-= (const Thirteen &other);

   friend std::ostream& operator<< (std::ostream &os, const Thirteen &obj);

   size_t getsize() const noexcept;
   unsigned char* getarray() const noexcept;
   

private:
    const int BASE = 13;
    size_t _size;
    unsigned char* _array;
    bool isThirtSyst (unsigned char c) const;
    
};

unsigned char ToUnsChar(char c);
char ToChar(unsigned char c);
