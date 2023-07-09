#pragma once
#include "../NonCopyable.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
constexpr int kMaxPoolSize = 10;
template <typename T> class ObjectPool : NonCopyable {
    template <typename... Args> using Constructor = std::function<std::shared_ptr<T>(Args...)>;

public:
    template <typename... Args> void init(size_t num, Args&&... args)
    {
        if (num <= 0 || num > kMaxPoolSize)
            throw std::logic_error("object num out of range.");
        auto constructName = typeid(Constructor<Args...>).name();
        std::cout << __func__ << " " << constructName << std::endl;
        for (size_t i = 0; i < num; ++i)
            m_objectMap.emplace(constructName,
                std::shared_ptr<T>(new T(std::forward<Args>(args)...), [this, constructName](T* p) {
                    m_objectMap.emplace(std::move(constructName), std::shared_ptr<T>(p));
                }));
    }
    template <typename... Args> std::shared_ptr<T> get()
    {
        std::string constructName = typeid(Constructor<Args...>).name();
        auto range = m_objectMap.equal_range(constructName);
        for (auto it = range.first; it != range.second; ++it) {
            auto ptr = it->second;
            m_objectMap.erase(it);
            return ptr;
        }
        return nullptr;
    }

private:
    std::multimap<std::string, std::shared_ptr<T>> m_objectMap;
};