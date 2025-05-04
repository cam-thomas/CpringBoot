#pragma once

#include <functional>
#include <memory>

class FunctionWrapperBase {
public:
    FunctionWrapperBase() = default;
    FunctionWrapperBase(const FunctionWrapperBase&) = delete;
    FunctionWrapperBase& operator=(const FunctionWrapperBase&) = delete;
    FunctionWrapperBase(FunctionWrapperBase&&) = default;
    FunctionWrapperBase& operator=(FunctionWrapperBase&&) = default;
    virtual ~FunctionWrapperBase() = default;
};

template<typename R, typename... Args>
class FunctionWrapper : public FunctionWrapperBase {
public:
    std::function<R(Args...)> func;

}; 

class Handler {
public:
    template<typename R, typename... Args>
    R operator() (Args... args) {
        FunctionWrapper<R, Args...> * funcWrapper = dynamic_cast<FunctionWrapper<R, Args...>>(func.get());

        if (funcWrapper) {
            return funcWrapper->func(std::forward<Args>(args)...);
        } else {
            throw std::bad_cast();
        }
    }
    std::unique_ptr<FunctionWrapperBase> func;
};

