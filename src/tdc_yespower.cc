#include <napi.h>
#include "yespower-1.0.0/yespower.h"

using namespace Napi;

Napi::Value hash(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  void* argp = NULL;
  size_t length = info.Length();

  if (length > 1) {
       Napi::Error::New(env, "hash only accepts 1 argument").
       ThrowAsJavaScriptException();
   return Number();
  }

  if(info[0].IsBuffer()) {
    argp = info[0].As<Napi::Buffer<unsigned char>>().Data();
  } else {
     Napi::Error::New(env, "Argument Must be a Buffer").
       ThrowAsJavaScriptException();
     return Number();
  }

  char output[32];

  yespower_hash((char *)argp, output);

  std::vector<char> v(output, output+32);

  return Napi::Buffer<char>::Copy(env, v.data(), v.size());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "yespower"),
              Napi::Function::New(env, hash));
  return exports;
}

NODE_API_MODULE(addon, Init)
