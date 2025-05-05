#include "HandlerManager.h"


std::shared_ptr<Handler> HandlerManager::GetHandler(std::string path) {
    auto handler = std::make_shared<Handler>();
    auto it = handlers.find(path);
    if (it != handlers.end()) {
        handler = std::make_shared<Handler>(std::move(it->second));
    }
    return handler;
}