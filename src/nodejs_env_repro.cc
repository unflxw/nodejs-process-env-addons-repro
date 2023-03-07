#include <napi.h>
#include <cstdlib>

using namespace Napi;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string output("");

  output.append("NODEJS_ENV_REPRO_BEFORE");
  if (const char* env_p = std::getenv("NODEJS_ENV_REPRO_BEFORE")) {
    output.append("=");
    output.append(env_p);
  } else {
    output.append(" not found");
  }

  output.append("; ");
  output.append("NODEJS_ENV_REPRO");
  if (const char* env_p = std::getenv("NODEJS_ENV_REPRO")) {
    output.append("=");
    output.append(env_p);
  } else {
    output.append(" not found");
  }

  return Napi::String::New(env, output);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "NodejsEnvRepro"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(addon, Init)
