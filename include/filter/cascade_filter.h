#ifndef CASCADE_FILTER_H
#define CASCADE_FILTER_H

#include "digital_filter.h"
#include <utility>

namespace DSP {

template <
	typename T, 
	template <typename, typename...> typename FilterContainer,
	template <typename...> typename SmartPtr
>
class CascadeFilter : public DigitalFilter<T> {
public:
	using ContainerType = FilterContainer<SmartPtr<DigitalFilter<T>>>;

	template <typename FilterPointerInputIterator>
	CascadeFilter(FilterPointerInputIterator begin, FilterPointerInputIterator end) :
		mFilterCollection(begin, end)
	{}

	explicit CascadeFilter(const ContainerType &filter_collection) :
		mFilterCollection(std::move(filter_collection))
	{}

	explicit CascadeFilter(ContainerType &&filter_collection) :
		mFilterCollection(std::move(filter_collection))
	{}

	T filter(T sample) override {
		for (const auto& filter : mFilterCollection) {
			sample = filter->filter(sample);
		}
		return sample;
	}
private:
	ContainerType mFilterCollection;
};

template <
	typename T,
	template <typename...> typename SmartPtr,
	template <typename, typename...> typename Container,
	typename ContainerElement = SmartPtr<DigitalFilter<T>>,
	typename... ContainerArgs
>
auto make_cascade_filter(Container<ContainerElement, ContainerArgs...>&& collection) {
	return CascadeFilter<T, Container, SmartPtr>(std::forward<Container<ContainerElement, ContainerArgs...>>(collection));
}

}
#endif // CASCADE_FILTER_H
