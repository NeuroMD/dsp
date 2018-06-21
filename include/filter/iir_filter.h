#ifndef IIR_FILTER_H
#define IIR_FILTER_H

#include "digital_filter.h"
#include "direction_strategy.h"
#include "filter_algorithm.h"

namespace DSP {

template <typename T, typename Passband, template <class> class Algorithm, template <class> class DirectionStrategy = ForwardFiltering>
class IIRFilter : public DigitalFilter<T>, private DirectionStrategy<Algorithm<Passband>> {
public:
    T filter(const T &sample) override{
        return this->performFiltering(sample);
    }

    T filter(T&& sample) override{
        return this->performFiltering(std::move(sample));
    }
};

template <class Passband>
using IIRForwardFilter = IIRFilter<double, Passband, FilterSolutionAlgorithm>;

template <class Passband>
using IIRReverseFilter = IIRFilter<double, Passband, FilterSolutionAlgorithm, ReverseFiltering>;

}

#endif // IIR_FILTER_H
