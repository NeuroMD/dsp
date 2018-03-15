#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include "signal_filter.h"
#include <memory>

enum class CallibriFilter: unsigned int{
    ECG_LPF_27_HZ,
    ECG_LPF_1_HZ,
    ECG_HPF_5_HZ,
    ECG_HPF_3_HZ,
    ECG_HPF_11_HZ,
    ECG_LPF_5_HZ,
    ECG_LPF_15_HZ,
    EEG_LPF_40_HZ,
    EEG_LPF_30_HZ,
    EEG_LPF_2_HZ,
    EEG_HPF_3_HZ,
    EEG_HPF_2_HZ,
    EEG_BPF_3_40_HZ,
    EEG_BS_50_HZ,
    EEG_BS_25_HZ
};

template <CallibriFilter Filter>
constexpr std::initializer_list<double> getCallibriFilterNumerators();

template <CallibriFilter Filter>
constexpr std::initializer_list<double> getCallibriFilterDenominators();

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_LPF_30_HZ>(){
    return {
            0.027859766117136031,
            0.055719532234272062,
            0.027859766117136031};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_LPF_30_HZ>(){
    return {
            0.58691950806119031,
            -1.4754804435926461};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_HPF_2_HZ>(){
    return {
            0.96508098634473405,
            -1.9301619726894681,
            0.96508098634473405 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_HPF_2_HZ>(){
    return {
            0.93138168212690264,
            -1.9289422632520334
            };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_BS_25_HZ>(){
    return {
            .915,
            -2.961,
            4.225,
            -2.961,
            .915 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_BS_25_HZ>(){
    return {
            .8372,
            -2.829,
            4.218,
            -3.093};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_BS_50_HZ>(){
    return {
            0.8370891905663449,
            -1.0429229013534211,
            1.9990207606620285,
            -1.0429229013534211,
            0.8370891905663449 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_BS_50_HZ>(){
    return {
            0.7008967811884026,
            -0.94976030879978701,
            1.9723023606063141,
            -1.136085493907057};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_BPF_3_40_HZ>(){
    return {
            -4.683e-03,
            0.0,
            2.341e-02,
            0.0,
            -4.683e-02,
            0.0,
            4.683e-02,
            0.0,
            -2.341e-02,
            0.0,
            4.683e-03 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_BPF_3_40_HZ>(){
    return {
            5.601e-02,
            -.6881,
            3.869,
            -13.14,
            29.87,
            -47.46,
            53.44,
            -42.07,
            22.11,
            -6.98};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_HPF_3_HZ>(){
    return {
            -.9274,
            2.782,
            -2.782,
            .9274 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_HPF_3_HZ>(){
    return {
            -.8601,
            2.71,
            -2.849};
}


template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_LPF_40_HZ>(){
    return {
            2.287e-02,
            9.148e-02,
            .1372,
            9.148e-02,
            2.287e-02 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_LPF_40_HZ>(){
    return {
            6.321e-02,
            -.4081,
            1.123,
            -1.412};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::EEG_LPF_2_HZ>(){
    return {
            1.511e-05,
            4.532e-05,
            4.532e-05,
            1.511e-05  };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::EEG_LPF_2_HZ>(){
    return { -.9043,
             2.804,
             -2.899};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_LPF_27_HZ>(){
    return {
            .1145125051763383,
            .4580500207053534,
            .68707503105803,
            .4580500207053534,
            .1145125051763383 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_LPF_27_HZ>(){
    return { 6.615274550600441e-03,
             4.458424700748903e-02,
             .3215750886494999,
             .4594254726138241   };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_LPF_1_HZ>(){
    return {9.679688316745671e-04,
            1.935937663349134e-03,
            9.679688316745671e-04};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_LPF_1_HZ>(){
    return {
            0.8951411342166644,
            -1.891269258889966};
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_HPF_5_HZ>(){
    return {
            -.7772465214002014,
            2.331739564200604,
            -2.331739564200604,
            .7772465214002014 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_HPF_5_HZ>(){
    return {
            -.6041096995072748,
            2.115254127003159,
            -2.498608344691178  };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_HPF_3_HZ>(){
    return {
            .931378858122982,
            -1.862757716245964,
            .931378858122982 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_HPF_3_HZ>(){
    return {
            .8674721337916686,
            -1.858043298700259  };
}


template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_HPF_11_HZ>(){
    return {
            -.571007068698226,
            1.713021206094678,
            -1.713021206094678,
            .571007068698226 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_HPF_11_HZ>(){
    return {
            -.3258789841198803,
            1.336195449676777,
            -1.905982115789151  };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_LPF_5_HZ>(){
    return {
            1.567010350588269e-03,
            4.701031051764807e-03,
            4.701031051764807e-03,
            1.567010350588269e-03 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_LPF_5_HZ>(){
    return {
            -.6041096995072748,
            2.115254127003159,
            -2.498608344691178  };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterNumerators<CallibriFilter::ECG_LPF_15_HZ>(){
    return {
            8.91445723946302e-03,
            3.565782895785208e-02,
            5.348674343677812e-02,
            3.565782895785208e-02,
            8.91445723946302e-03 };
}

template <>
constexpr std::initializer_list<double>
getCallibriFilterDenominators<CallibriFilter::ECG_LPF_15_HZ>(){
    return {
            .1316807150386918,
            -.7824401031209367,
            1.841785841678163,
            -2.048395137764509  };
}



template <typename FilterImplementation, CallibriFilter FilterType>
class BuiltInFilterCreator{
public:
    std::unique_ptr<FilterImplementation> Create() {

        return std::unique_ptr<FilterImplementation>(new FilterImplementation(getCallibriFilterDenominators<FilterType>(),
                                                    getCallibriFilterNumerators<FilterType>()));
    }
};

template <class CreationPolicy>
class FilterCreator: public CreationPolicy{};

#endif //FILTER_FACTORY_H
