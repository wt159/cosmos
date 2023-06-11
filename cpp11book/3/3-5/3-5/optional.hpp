#ifndef _OPTIONAL_HPP_
#define _OPTIONAL_HPP_

#include <exception>
#include <type_traits>
#include <utility>

template <typename T>
class optional {
    using data_t = typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type;
    // typedef typename std::aligned_storage<sizeof(T),
    //                       std::alignment_of<T>::value>::type data_t;  //这种方式也可以啦
public:
    optional() { }

    optional(const T& v)
    {
        create(v);
    }

    optional(T&& v)
    {
        create(std::move(v));
    }

    ~optional()
    {
        destroy();
    }

    optional(const optional& other)
    {
        if (other.has_value())
            assign(other);
    }

    optional(optional&& other)
    {
        if (other.has_value()) {
            assign(std::move(other));
            other.destroy();
        }
    }

    optional& operator=(optional&& other)
    {
        assign(std::move(other));
        return *this;
    }

    optional& operator=(const optional& other)
    {
        assign(other);
        return *this;
    }

    template <class... Args>
    void emplace(Args&&... args)
    {
        destroy();
        create(std::forward<Args>(args)...);
    }

    void reset()
    {
        destroy();
    }

    void swap(optional& other)
    {
        if ((has_value() == true) && (other.has_value() == true)) {
            std::swap(**this, *other);
        } else if ((has_value() == false) && (other.has_value() == true)) {
            create(std::move(*other));
            other.destroy();
        } else if ((has_value() == true) && (other.has_value() == false)) {
            other.create(std::move(**this));
            destroy();
        }
    }

    bool has_value() const { return m_hasValue; }

    explicit operator bool() const
    {
        return has_value();
    }

    T& operator*()
    {
        return *((T*)(&m_data));
    }

    T const& operator*() const
    {
        if (has_value()) {
            return *((T*)(&m_data));
        }

        throw std::exception("");
    }

    T* operator->()
    {
        return ((T*)(&m_data));
    }

    const T* operator->() const
    {
        return ((T*)(&m_data));
    }

    T& value()
    {
        if (has_value()) {
            return *((T*)(&m_data));
        }

        throw std::exception("");
    }

    const T& value() const
    {
        if (has_value()) {
            return *((T*)(&m_data));
        }

        throw std::exception("");
    }

    bool operator==(const optional<T>& rhs) const
    {
        return (!bool(*this)) != (!rhs) ? false : (!bool(*this) ? true : (*(*this)) == (*rhs));
    }

    bool operator<(const optional<T>& rhs) const
    {
        return !rhs ? false : (!bool(*this) ? true : (*(*this) < (*rhs)));
    }

    bool operator>(const optional<T>& rhs) const
    {
        return (rhs < *this) && !(*this == rhs);
    }

    bool operator!=(const optional<T>& rhs)
    {
        return !(*this == (rhs));
    }

private:
    template <class... Args>
    void create(Args&&... args)
    {
        new (&m_data) T(std::forward<Args>(args)...);
        m_hasValue = true;
    }

    void destroy()
    {
        if (m_hasValue) {
            m_hasValue = false;
            ((T*)(&m_data))->~T();
        }
    }

    void assign(const optional& other)
    {
        if (other.has_value()) {
            copy(other.m_data);
            m_hasValue = true;
        } else {
            destroy();
        }
    }

    void assign(optional&& other)
    {
        if (other.has_value()) {
            move(std::move(other.m_data));
            m_hasValue = true;
            other.destroy();
        } else {
            destroy();
        }
    }

    void move(data_t&& val)
    {
        destroy();
        new (&m_data) T(std::move(*((T*)(&val))));
    }

    void copy(const data_t& val)
    {
        destroy();
        new (&m_data) T(*((T*)(&val)));
    }

private:
    bool m_hasValue = false;
    data_t m_data;
};

#endif
