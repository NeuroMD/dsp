#ifndef FILTER_ALGORITHM_H
#define FILTER_ALGORITHM_H

namespace DSP {

template <typename PassbandType>
class ClassicFilterAlgorithm : private PassbandType{
    template <typename T>
    T filter(T&& sample){
        T V0 = x;
        for (auto i = Order; i > 0; i--) {
            V0 = V0 - Denominators[i] * V[i - 1];
        }
        T Y = V0 * Numerators[0] + V[0] * Numerators[1];
        for (auto i = Order; i > 1; i--) {
            Y = Y + Numerators[i] * V[i - 1];
            V[i - 1] = V[i - 2];
        }
        V[0] = V0;
        return Y;
    }
};

template <typename PassbandType>
class FilterSolutionAlgorithm : private PassbandType{
protected:
    template <typename T>
    T filter(T&& sample){
        T sumden = 0.0, sumnum = 0.0;
        for (decltype(this->order) i = 0; i < this->order; i++) {
            sumden += this->V[i] * this->Denominators[i];
            sumnum += this->V[i] * this->Numerators[i];
            if (i < this->order - 1) this->V[i] = this->V[i + 1];
        }
        this->V[this->order - 1] = invar - sumden;
        sumnum += this->V[this->order - 1] * this->Numerators[this->order];
        return sumnum;
    }
};

}

#endif // FILTER_ALGORITHM_H
