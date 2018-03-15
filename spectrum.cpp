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

#include "spectrum.h"


bool Spectrum::checkPowerOfTwo(int number)
{
    return number && !(number & (number - 1));
}

int Spectrum::getNearestBiggerPowerOfTwo(int number)
{
    // Divide by 2^k for consecutive doublings of k up to 32 and or the results
    number--;
    number |= number >> 1;
    number |= number >> 2;
    number |= number >> 4;
    number |= number >> 8;
    number |= number >> 16;
    number++;
    return number;
}

int Spectrum::setSpectrumSize(int spectrum_size)
{
    if (!checkPowerOfTwo(spectrum_size))
        _spectrumSize = getNearestBiggerPowerOfTwo(spectrum_size);
    else
        _spectrumSize = spectrum_size;
    return _spectrumSize;
}

int Spectrum::getSpectrumSize() const
{
    return _spectrumSize;
}

std::vector<double> Spectrum::calculateChannelSpectrum(std::size_t offset, std::size_t length)
{
   /* auto data = readRawData(time, duration);

    auto dataLength = data.size();


    vector<SignalSample> spectrum(_spectrumSize, 0.0);

    //If count of data is less then spectrum calculation window
    //than just append zeros to the end of data vector to fit its size
    //to window size
    if (dataLength <= _spectrumSize)
    {
        data.insert(data.end(), _spectrumSize - dataLength, 0.0);
        CommonAlgorithms::FFTAnalysis(&data[0], &spectrum[0], _spectrumSize,
                                      _spectrumSize);
    }
        //if
    else if (dataLength > _spectrumSize)
    {
        auto step_count = dataLength / _spectrumSize;
        if (dataLength % _spectrumSize != 0)
        {
            ++step_count;
            data.insert(data.end(), _spectrumSize * step_count - dataLength, 0.0);
        }
        uint32_t start_index = 0;
        for (auto step = 0; step < step_count; ++step)
        {
            vector<SignalSample> step_spectrum(_spectrumSize);
            CommonAlgorithms::FFTAnalysis(&data[start_index], &step_spectrum[0], _spectrumSize,
                                          _spectrumSize);

            start_index+=_spectrumSize;

            for (auto i = 0; i < _spectrumSize; ++i)
            {
                spectrum[i] += step_spectrum[i]/step_count;
            }
        }
    }

    return spectrum;*/
    return std::vector<double>();
}

void Spectrum::calculateChannelSpectrumAsync(std::size_t offset, std::size_t length)
{
   /* thread spectrumThread([=]
                          {
                              auto spectrum = calculateChannelSpectrum(time,
                                                                       duration);
                              callbackFunc(_name, spectrum);
                          });
    spectrumThread.detach();*/
}
