#include "myobject.h"
#include <napi.h>
#include <uv.h>

// 这篇涉及的接口比较多 有点难以消化
/**
 * DefineClass
 * InstanceMethod
 * Napi::FunctionReference
 * Napi::Persistent
 * env.SetInstanceData
 * Napi::EscapableHandleScope scope(env);
 * scope.Escape(napi_value(obj)).ToObject()
 **/

using namespace Napi;

Napi::Object MyObject::Init(Napi::Env env, Napi::Object exports) {

  Napi::Function func = DefineClass(
      env, "MyObject", {InstanceMethod("plusOne", &MyObject::PlusOne)});

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("MyObject", func);
  return exports;
}

MyObject::MyObject(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<MyObject>(info) {

  this->counter_ = info[0].As<Napi::Number>().DoubleValue();
};

Napi::Object MyObject::NewInstance(Napi::Env env, Napi::Value arg) {
  Napi::EscapableHandleScope scope(env);
  Napi::Object obj = env.GetInstanceData<Napi::FunctionReference>()->New({arg});
  return scope.Escape(napi_value(obj)).ToObject();
}

Napi::Value MyObject::PlusOne(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->counter_ = this->counter_ + 1;

  return Napi::Number::New(env, this->counter_);
}
