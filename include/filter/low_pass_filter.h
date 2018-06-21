#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include <array>

namespace DSP {

template<std::size_t CutoffFreq, std::size_t FilterOrder, std::size_t SamplingFreq>
class LowPass;

template<>
class LowPass<27, 5, 125>{
protected:
    static constexpr std::size_t Order = 5;
    std::array<double, Order - 1> Denominators{{
        6.615274550600441e-03,
        4.458424700748903e-02,
        .3215750886494999,
        .4594254726138241}};
    std::array<double, Order> Numerators{{
        .1145125051763383,
        .4580500207053534,
        .68707503105803,
        .4580500207053534,
        .1145125051763383}};
    std::array<double, Order> V;
};

template<>
class LowPass<1, 3, 125>{
protected:
    static constexpr std::size_t Order = 3;
    std::array<double, Order - 1> Denominators{{
        0.8951411342166644,
        -1.891269258889966}};
    std::array<double, Order> Numerators{{
        9.679688316745671e-04,
        1.935937663349134e-03,
        9.679688316745671e-04}};
    std::array<double, Order> V;
};

}

#endif // LOW_PASS_FILTER_H
