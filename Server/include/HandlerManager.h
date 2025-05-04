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
        void RegisterHandler(std::string path, std::function<R, Args...> func);

        Handler& GetHandler(std::string path);
    private:
        std::map<std::string, Handler> handlers;
    };
