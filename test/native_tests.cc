#include <stdlib.h>
#include "nan.h"

#ifdef _WIN32
  #define __alignof__ __alignof
#endif

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

typedef union _test8 {
  int a;
  double b;
  int c;
} test8;


void Initialize(v8::Handle<v8::Object> target) {
  NanScope();

  target->Set(NanNew<v8::String>("test1 sizeof"), NanNew<v8::Number>(sizeof(test1)));
  target->Set(NanNew<v8::String>("test1 alignof"), NanNew<v8::Number>(__alignof__(test1)));
  target->Set(NanNew<v8::String>("test1 offsetof a"), NanNew<v8::Number>(offsetof(test1, a)));
  target->Set(NanNew<v8::String>("test1 offsetof b"), NanNew<v8::Number>(offsetof(test1, b)));

  target->Set(NanNew<v8::String>("test2 sizeof"), NanNew<v8::Number>(sizeof(test2)));
  target->Set(NanNew<v8::String>("test2 alignof"), NanNew<v8::Number>(__alignof__(test2)));
  target->Set(NanNew<v8::String>("test2 offsetof a"), NanNew<v8::Number>(offsetof(test2, a)));
  target->Set(NanNew<v8::String>("test2 offsetof b"), NanNew<v8::Number>(offsetof(test2, b)));

  target->Set(NanNew<v8::String>("test3 sizeof"), NanNew<v8::Number>(sizeof(test3)));
  target->Set(NanNew<v8::String>("test3 alignof"), NanNew<v8::Number>(__alignof__(test3)));
  target->Set(NanNew<v8::String>("test3 offsetof a"), NanNew<v8::Number>(offsetof(test3, a)));
  target->Set(NanNew<v8::String>("test3 offsetof b"), NanNew<v8::Number>(offsetof(test3, b)));
  target->Set(NanNew<v8::String>("test3 offsetof c"), NanNew<v8::Number>(offsetof(test3, c)));

  target->Set(NanNew<v8::String>("test4 sizeof"), NanNew<v8::Number>(sizeof(test4)));
  target->Set(NanNew<v8::String>("test4 alignof"), NanNew<v8::Number>(__alignof__(test4)));
  target->Set(NanNew<v8::String>("test4 offsetof a"), NanNew<v8::Number>(offsetof(test4, a)));
  target->Set(NanNew<v8::String>("test4 offsetof b"), NanNew<v8::Number>(offsetof(test4, b)));

  target->Set(NanNew<v8::String>("test5 sizeof"), NanNew<v8::Number>(sizeof(test5)));
  target->Set(NanNew<v8::String>("test5 alignof"), NanNew<v8::Number>(__alignof__(test5)));
  target->Set(NanNew<v8::String>("test5 offsetof a"), NanNew<v8::Number>(offsetof(test5, a)));
  target->Set(NanNew<v8::String>("test5 offsetof b"), NanNew<v8::Number>(offsetof(test5, b)));

  target->Set(NanNew<v8::String>("test6 sizeof"), NanNew<v8::Number>(sizeof(test6)));
  target->Set(NanNew<v8::String>("test6 alignof"), NanNew<v8::Number>(__alignof__(test6)));
  target->Set(NanNew<v8::String>("test6 offsetof a"), NanNew<v8::Number>(offsetof(test6, a)));
  target->Set(NanNew<v8::String>("test6 offsetof b"), NanNew<v8::Number>(offsetof(test6, b)));

  target->Set(NanNew<v8::String>("test7 sizeof"), NanNew<v8::Number>(sizeof(test7)));
  target->Set(NanNew<v8::String>("test7 alignof"), NanNew<v8::Number>(__alignof__(test7)));
  target->Set(NanNew<v8::String>("test7 offsetof a"), NanNew<v8::Number>(offsetof(test7, a)));
  target->Set(NanNew<v8::String>("test7 offsetof b"), NanNew<v8::Number>(offsetof(test7, b)));
  target->Set(NanNew<v8::String>("test7 offsetof c"), NanNew<v8::Number>(offsetof(test7, c)));
  target->Set(NanNew<v8::String>("test7 offsetof d"), NanNew<v8::Number>(offsetof(test7, d)));

  target->Set(NanNew<v8::String>("test8 sizeof"), NanNew<v8::Number>(sizeof(test8)));
  target->Set(NanNew<v8::String>("test8 alignof"), NanNew<v8::Number>(__alignof__(test8)));
  target->Set(NanNew<v8::String>("test8 offsetof a"), NanNew<v8::Number>(offsetof(test8, a)));
  target->Set(NanNew<v8::String>("test8 offsetof b"), NanNew<v8::Number>(offsetof(test8, b)));
  target->Set(NanNew<v8::String>("test8 offsetof c"), NanNew<v8::Number>(offsetof(test8, c)));
}

} // anonymous namespace

NODE_MODULE(native_tests, Initialize);
