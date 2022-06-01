#include <iostream>
#include <array>
#include <vector>
#include <type_traits>


template <typename T>
struct has_id
{
    typedef char Yes[1];
    typedef char No[2];
    template <typename U>
    static Yes &test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::id)>::value, bool>::type = 0);
    template <typename U>
    static No &test(...);
    static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(Yes &);
};

template<typename T>
constexpr auto has_id_t = has_id<T>::value;

template <typename T>
struct has_name
{
    typedef char Yes[1];
    typedef char No[2];
    template <typename U>
    static Yes &test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::name)>::value, bool>::type = 0);
    template <typename U>
    static No &test(...);
    static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(Yes &);
};

template<typename T>
constexpr auto has_name_t = has_name<T>::value;


struct A
{
    auto id() const { return 42; }
};

struct B
{
    auto name() const { return "from struct B"; }
};

template <class T>
auto foo(T const &value, std::enable_if_t<has_id<T>::value> * = nullptr)
{
    return value.id();
}

template <class T>
auto foo(T const &value, std::enable_if_t<has_name<T>::value> * = nullptr)
{
    return value.name();
}

int main()
{
    static_assert(has_name_t<B> == true);
    static_assert(has_id_t<A> ==true);
    static_assert(has_name_t<A> == false);
    static_assert(has_id_t<B> ==false);

    std::cout << foo(A{}) <<std::endl<< foo(B{}) << std::endl;
}
