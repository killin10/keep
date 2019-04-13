/*
 * @file auto_ptr.h
 * @brief significance of auto_ptr_ref
 *
 * @version 1.0
 * @date Mon Dec 10 21:17:48 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>

template <typename Y>
struct auto_ptr_ref {
    Y *yp;
    auto_ptr_ref(Y *rhs) :
        yp(rhs) {
        std::cout << "auto_ptr_ref(Y *rhs)" << std::endl;
    }
};

template <typename T>
class auto_ptr
{
private:
    T *_ap;

public:
    typedef T element_type;

    // constructor
    explicit auto_ptr(T *ptr = 0) throw() :
        _ap(ptr) {
        std::cout << "auto_ptr(T *ptr) throw()" << std::endl;
    }

    // copy constructor
    auto_ptr(auto_ptr &rhs) throw() :
        _ap(rhs.release()) {
        std::cout << "auto_ptr(auto_ptr &rhs) throw()" << std::endl;
    }

    template <typename Y>
    auto_ptr(auto_ptr<Y> &rhs) throw() :
        _ap(rhs.release()) {
        std::cout << "auto_ptr(auto_ptr<Y> &rhs) throw()" << std::endl;
    }

    // assignments
    auto_ptr &operator=(auto_ptr &rhs) throw() {
        std::cout << "auto_ptr& operator=(auto_ptr &rhs) throw()" << std::endl;
        reset(rhs.release());
        return *this;
    }

    template <typename Y>
    auto_ptr &operator=(auto_ptr<Y> &rhs) throw() {
        std::cout << "auto_ptr& operator=(auto_ptr<Y> &rhs) throw()" << std::endl;
        reset(rhs.release());
        return *this;
    }

    // destructor
    ~auto_ptr() throw() {
        std::cout << "~auto_ptr() throw()" << std::endl;
        delete _ap;
    }

    // value access
    T *get() const throw() {
        return _ap;
    }

    T &operator*() const throw() {
        return *_ap;
    }

    T *operator->() const throw() {
        return _ap;
    }

    // release ownership
    T *release() throw() {
        T *tmp(_ap);
        _ap = 0;
        return tmp;
    }

    // reset value
    void reset(T *ptr = 0) throw() {
        if (_ap != ptr) {
            delete _ap;
            _ap = ptr;
        }
    }

    // special conversions with auxiliary type to enable copies and assignments
    auto_ptr(auto_ptr_ref<T> rhs) throw() :
        _ap(rhs.yp) {
        std::cout << "auto_ptr(auto_ptr_ref<T> rhs) throw()" << std::endl;
    }

    auto_ptr &operator=(auto_ptr_ref<T> rhs) throw() {
        std::cout << "auto_ptr& operator=(auto_ptr_ref<T> rhs) throw()"
                  << std::endl;
        reset(rhs.yp);
        return *this;
    }

    template <typename Y>
    operator auto_ptr_ref<Y>() throw() {
        std::cout << "operator auto_ptr_ref<Y>() throw()" << std::endl;
        return auto_ptr_ref<Y>(release());
    }

    //template <typename Y>
    //operator auto_ptr<Y>() throw() {
        //std::cout << "operator auto_ptr<Y>() throw()" << std::endl;
        //return auto_ptr<Y>(release());
    //}
};

