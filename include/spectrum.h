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

#ifndef SPECTRUM_H
#define SPECTRUM_H

#include <vector>
#include <string>
#include "signal/circular_buffer.h"

class Spectrum
{
public:

    std::vector<double> calculateChannelSpectrum(std::size_t offset, std::size_t length);

    /**
     * Asynchronous call of spectrum calculation
     */
    void calculateChannelSpectrumAsync(std::size_t offset, std::size_t length);

    /**
     * Sets size of spectrum buffer
     * Must be power of 2
     * If @spectrum_size parameter is not a power of 2
     * method will set up buffer size to nearest bigger power of 2 value
     * Returns actually set value of buffer size
     */
    int setSpectrumSize(int spectrum_size);

    int getSpectrumSize() const;

private:
    bool checkPowerOfTwo(int number);
    int getNearestBiggerPowerOfTwo(int number);
    int _spectrumSize;
};

template <typename T>
struct SpectrumData{
    SpectrumData() = default;
    SpectrumData(std::vector<T> data, double step):spectrum(data), frequencyStep(step){}
    SpectrumData(const SpectrumData &) = default;
    SpectrumData& operator=(const SpectrumData &) = default;
    SpectrumData(SpectrumData &&) = default;
    SpectrumData& operator=(SpectrumData &&) = default;

    std::vector<T> spectrum;
    double frequencyStep;
};

#endif //SPECTRUM_H
