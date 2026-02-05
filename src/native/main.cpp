#include <napi.h>
#include <vector>
#include <numeric>

Napi::Value IntensiveCompute(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    // Продвинутая работа с памятью напрямую
    Napi::Float64Array input = info[0].As<Napi::Float64Array>();
    double sum = 0;
    for (size_t i = 0; i < input.ElementLength(); i++) {
        sum += input[i] * 1.000001; // Имитация сложной логики
    }
    return Napi::Number::New(env, sum);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("compute", Napi::Function::New(env, IntensiveCompute));
    return exports;
}

NODE_API_MODULE(addon, Init)
