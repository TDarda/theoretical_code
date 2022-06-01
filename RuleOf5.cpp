#include <iostream>
#include <vector>

class RuleOfFive
{
public:
    int *_n;
    std::vector<int> _vec;
    RuleOfFive(int *n, std::vector<int> vec) : _vec(vec), _n(n) {}
    ~RuleOfFive()
    {
        delete _n;
        _n = nullptr;
    }
    RuleOfFive(const RuleOfFive &RuleOfFive)
    {
        _n = new int();
        *(_n) = *(RuleOfFive._n);
        this->_vec = RuleOfFive._vec;
    }
    RuleOfFive &operator=(const RuleOfFive &RuleOfFive)
    {
        _n = new int();
        *(_n) = *(RuleOfFive._n);
        this->_vec = RuleOfFive._vec;
        return *this;
    }
    RuleOfFive(RuleOfFive &&RuleOfFive)
    {
        _n = new int();
        *(_n) = *(RuleOfFive._n);
        this->_vec = RuleOfFive._vec;
        RuleOfFive._n = nullptr;
        RuleOfFive._vec.clear();
    }
    RuleOfFive &operator=(RuleOfFive &&RuleOfFive)
    {
        if (this == &RuleOfFive)
            return *this;
        _n = new int();
        *(_n) = *(RuleOfFive._n);
        this->_vec = RuleOfFive._vec;
        RuleOfFive._n = nullptr;
        RuleOfFive._vec.clear();
        return *this;
    }
};

int main()
{
    RuleOfFive obj(new int{1}, std::vector<int>{1, 2, 3});
    RuleOfFive obj2(new int{2}, std::vector<int>{3, 4, 5});
    RuleOfFive obj3 = obj;
    if (not(obj3._n == obj._n))
    {
        std::cout << "it's fine!" << std::endl;
    }
    else
    {
        std::cout << "it's wrong!" << std::endl;
    }
       obj3 = std::move(obj2);
    if ((obj2._n == nullptr))
    {
        std::cout << "it's fine!" << std::endl;
    }
    else
    {
        std::cout << "it's wrong!" << std::endl;
    }
}