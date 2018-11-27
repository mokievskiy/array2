 
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iosfwd>
#include <algorithm>
  class Array
  {
  public:
	  Array(); //default constructor
	  ~Array(); //default destructor
	  Array(const Array & a); // copy constructor
	  Array(const double *a, const size_t l); //constructor by set and length
	  size_t length() const; //lenght of array
	  Array & operator= (const Array & a); //appropriation of array
	  Array & operator+= (const double a); //adding element in the end
	  Array & operator-= (const int i); //removing element by it's index
	  Array operator+ (const Array & a); //addition of 2 arrays
	  double &operator[] (size_t i); //element by it's index
	  const double &operator[] (size_t i) const; //const element by it's index
	  friend std:: ostream& operator<<(std:: ostream& out, const Array& a); //print all array
      void sorti(); // sortirovka
  private:
	  void resize(size_t l); //resize
      double *_arr;
      size_t _len;
  };
  void test(int T);
  int comp (const void *a, const void *b);

#endif
