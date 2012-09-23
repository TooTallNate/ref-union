#include <stdlib.h>
#include "v8.h"
#include "node.h"

#ifdef _WIN32
  #define __alignof__ __alignof
#endif

using namespace v8;
using namespace node;

namespace {

typedef union _test1 {
  char a;
  short b;
} test1;

typedef union _test2 {
  char a;
  int b;
} test2;

typedef union _test3 {
  char a;
  short b;
  int c;
} test3;

typedef union _test4 {
  struct {
    char a;
    short b;
    int c;
  } a;
  int b;
} test4;

typedef union _test5 {
  double a;
  char b;
} test5;

typedef union _test6 {
  test1 a;
  char b;
} test6;

typedef union _test7 {
  char a;
  char b[2];
  short c;
  char d;
} test7;


void Initialize(Handle<Object> target) {
  HandleScope scope;

  target->Set(String::NewSymbol("test1 sizeof"), Number::New(sizeof(test1)));
  target->Set(String::NewSymbol("test1 alignof"), Number::New(__alignof__(test1)));
  target->Set(String::NewSymbol("test1 offsetof a"), Number::New(offsetof(test1, a)));
  target->Set(String::NewSymbol("test1 offsetof b"), Number::New(offsetof(test1, b)));

  target->Set(String::NewSymbol("test2 sizeof"), Number::New(sizeof(test2)));
  target->Set(String::NewSymbol("test2 alignof"), Number::New(__alignof__(test2)));
  target->Set(String::NewSymbol("test2 offsetof a"), Number::New(offsetof(test2, a)));
  target->Set(String::NewSymbol("test2 offsetof b"), Number::New(offsetof(test2, b)));

  target->Set(String::NewSymbol("test3 sizeof"), Number::New(sizeof(test3)));
  target->Set(String::NewSymbol("test3 alignof"), Number::New(__alignof__(test3)));
  target->Set(String::NewSymbol("test3 offsetof a"), Number::New(offsetof(test3, a)));
  target->Set(String::NewSymbol("test3 offsetof b"), Number::New(offsetof(test3, b)));
  target->Set(String::NewSymbol("test3 offsetof c"), Number::New(offsetof(test3, c)));

  target->Set(String::NewSymbol("test4 sizeof"), Number::New(sizeof(test4)));
  target->Set(String::NewSymbol("test4 alignof"), Number::New(__alignof__(test4)));
  target->Set(String::NewSymbol("test4 offsetof a"), Number::New(offsetof(test4, a)));
  target->Set(String::NewSymbol("test4 offsetof b"), Number::New(offsetof(test4, b)));

  target->Set(String::NewSymbol("test5 sizeof"), Number::New(sizeof(test5)));
  target->Set(String::NewSymbol("test5 alignof"), Number::New(__alignof__(test5)));
  target->Set(String::NewSymbol("test5 offsetof a"), Number::New(offsetof(test5, a)));
  target->Set(String::NewSymbol("test5 offsetof b"), Number::New(offsetof(test5, b)));

  target->Set(String::NewSymbol("test6 sizeof"), Number::New(sizeof(test6)));
  target->Set(String::NewSymbol("test6 alignof"), Number::New(__alignof__(test6)));
  target->Set(String::NewSymbol("test6 offsetof a"), Number::New(offsetof(test6, a)));
  target->Set(String::NewSymbol("test6 offsetof b"), Number::New(offsetof(test6, b)));

  target->Set(String::NewSymbol("test7 sizeof"), Number::New(sizeof(test7)));
  target->Set(String::NewSymbol("test7 alignof"), Number::New(__alignof__(test7)));
  target->Set(String::NewSymbol("test7 offsetof a"), Number::New(offsetof(test7, a)));
  target->Set(String::NewSymbol("test7 offsetof b"), Number::New(offsetof(test7, b)));
  target->Set(String::NewSymbol("test7 offsetof c"), Number::New(offsetof(test7, c)));
  target->Set(String::NewSymbol("test7 offsetof d"), Number::New(offsetof(test7, d)));
}

} // anonymous namespace

NODE_MODULE(native_tests, Initialize);
