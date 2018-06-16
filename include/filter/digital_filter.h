#ifndef DIGITAL_FILTER_H
#define DIGITAL_FILTER_H

#include <memory>

namespace DSP {

template <typename T>
class DigitalFilter{
public:
    virtual ~DigitalFilter(){}
    virtual T filter(const T &) = 0;
    virtual T filter(T &&) = 0;
};

template <typename T>
using DigitalFilterPtr = std::unique_ptr<DigitalFilter<T>>;

}

#endif //DIGITAL_FILTER_H
