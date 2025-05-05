#pragma once

#include <any>
#include <functional>
#include <memory>

class FunctionWrapperBase {
public:
    FunctionWrapperBase() = default;
    virtual ~FunctionWrapperBase() = default;
};

template<typename R, typename... Args>
class FunctionWrapper : public FunctionWrapperBase {
public:
    std::function<R(Args...)> func;
}; 

class Handler {
public:
    Handler() : func(nullptr) {}

    // Delete copy constructor and copy assignment operator
    Handler(const Handler& other) = delete;
    Handler& operator=(const Handler& other) = delete;

    // Implement move constructor
    Handler(Handler&& other) noexcept : func(std::move(other.func)) {}

    // Implement move assignment operator
    Handler& operator=(Handler&& other) noexcept {
        if (this != &other) {
            func = std::move(other.func);
        }
        return *this;
    }

    template<typename R, typename... Args>
    R Invoke(Args... args) {
        auto* funcWrapper = dynamic_cast<FunctionWrapper<R, Args...>*>(func.get());
        if (funcWrapper && funcWrapper->func) {
            return funcWrapper->func(std::forward<Args>(args)...);
        } else {
            throw std::runtime_error("Function not set or invalid cast");
        }
    }

    template<typename... Args>
    std::any Invoke(Args... args) {
        auto* funcWrapper = dynamic_cast<FunctionWrapper<std::any, Args...>*>(func.get());
        std::any result;
        if (funcWrapper) {
            result = funcWrapper->func(std::forward<Args>(args)...);
        } else {
            throw std::runtime_error("Function not set");
        }
        return result;
    }

    std::unique_ptr<FunctionWrapperBase> func;
};

