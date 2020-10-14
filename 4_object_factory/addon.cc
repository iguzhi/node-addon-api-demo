#include <napi.h>

Napi::Object CreateObject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Object obj = Napi::Object::New(env); // 创建对象
  obj.Set(Napi::String::New(env, "msg"), info[0].ToString()); // 函数参数转字符串 info[0].ToString()；给对象设置属性msg

  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return Napi::Function::New(env, CreateObject);
}

NODE_API_MODULE(addon, Init)
