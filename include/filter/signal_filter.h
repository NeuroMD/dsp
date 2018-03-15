/*
 * Copyright 2016 - 2017 Neurotech MRC. http://neurotech.ru/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SIGNAL_FILTER_H
#define SIGNAL_FILTER_H

#include <vector>
#include <stdexcept>
#include "circular_buffer.h"

template <typename T>
class DigitalFilter{
public:
    virtual ~DigitalFilter(){};
    virtual T filter(T) = 0;
    virtual void reset() = 0;
};

template <typename T>
class IIRFilter: public DigitalFilter<T>{
public:
    IIRFilter(std::initializer_list<T> d, std::initializer_list<T> n):
            order(d.size()),
            Denominators(d),
            Numerators(n),
            V(order, 0){

        //if (Denominators.size()!=Numerators.size())
        //    throw std::runtime_error("Filter numerator and denominator are not of the same order");
    }

    virtual ~IIRFilter(){}

    virtual T filter(T x){
        T V0 = x;

        for (auto i = order; i > 0; i--) {
            V0 = V0 - Denominators[i] * V[i - 1];
        }

        T Y = V0 * Numerators[0] + V[0] * Numerators[1];
        for (auto i = order; i > 1; i--) {
            Y = Y + Numerators[i] * V[i - 1];
            V[i - 1] = V[i - 2];
        }
        V[0] = V0;
        return Y;
    }

    std::size_t getOrder() const{
        return order;
    }

    void reset() {
        std::fill(V.begin(), V.end(), 0);
    }
protected:
    std::size_t order;
    std::vector<T> Denominators;
    std::vector<T> Numerators;
    std::vector<T> V;
};

template <typename T>
class BesselFilter: public IIRFilter<T>{
public:
    BesselFilter(std::initializer_list<T> d, std::initializer_list<T> n):IIRFilter<T>(d, n){}
    ~BesselFilter(){}

    T filter(T invar){
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

#endif //SIGNAL_FILTER_H
