#include <napi.h>

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"), // 设置函数名位hello
              Napi::Function::New(env, Method)); // 函数hello函数指向的实际函数
  return exports;
}

NODE_API_MODULE(hello, Init)
