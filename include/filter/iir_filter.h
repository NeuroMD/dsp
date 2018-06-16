#ifndef IIR_FILTER_H
#define IIR_FILTER_H

#include "digital_filter.h"
#include "direction_strategy.h"

namespace DSP {

template <typename T, typename PassbandType, template <class> DirectionStrategy = ForwardFiltering>
class IIRFilter : public DigitalFilter<T>, private DirectionStrategy<PassbandType> {
public:
    template <typename S=T>
    S filter(S&& sample) override{
        performFiltering(std::forward<T>(sample));
    }
};

}

#endif // IIR_FILTER_H
