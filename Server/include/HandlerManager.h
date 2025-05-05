#pragma once

#include "Handler.h"

#include <map>
#include <string>
#include <functional>

class HandlerManager {
public:
    HandlerManager() = default;
    ~HandlerManager() = default;
    
    template<typename R, typename... Args>
    void RegisterHandler(std::string path, std::function<R(Args...)> func);

    std::shared_ptr<Handler> GetHandler(std::string path);
private:
    std::map<std::string, Handler> handlers;
};

template<typename R, typename... Args>
void HandlerManager::RegisterHandler(std::string path, std::function<R(Args...)> func) {
    Handler handler;
    handler.func = std::make_unique<FunctionWrapper<R, Args...>>();
    auto funcWrapper = dynamic_cast<FunctionWrapper<R, Args...>*>(handler.func.get());
    if (funcWrapper) {
        funcWrapper->func = func;
    } else {
        throw std::bad_cast();
    }
    handlers[path] = std::move(handler);
}