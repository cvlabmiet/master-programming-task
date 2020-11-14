//PoddubnaiaM PM-31
#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__
#include <algorithm>
#include <type_traits>
#include <vector>
#include <utility>
#include <boost/iterator/iterator_adaptor.hpp>
template<class Iterator>
class image_iterator : public boost::iterator_adaptor<image_iterator<Iterator>, Iterator>
{public:
image_iterator(Iterator iterator, size_t width, size_t stride, size_t shift = 0, size_t current_height = 0)
: boost::iterator_adaptor<image_iterator<Iterator>, Iterator>(iterator)
{w = width;
st = stride;
sh = shift;
c = current_height;
out = stride - width;}
void increment()
{advance(1);}
void decrement()
{advance(-1);}
void advance(const typename boost::iterator_adaptor<image_iterator<Iterator>, Iterator>::difference_type k)
{if (k == 0) { return; }
if (k > 0)
{for (size_t i = 0; i < static_cast<size_t>(k); i++)
{if (sh < w - 1)
{this->base_reference() = this->base_reference() + 1;
sh = sh + 1;}
else
{sh = 0;
c = c + 1;
this->base_reference() += out + 1;}}}
else
{for (size_t i = 0; i < static_cast<std::size_t>(-k); i++)
{if (sh > 0)
{sh = sh - 1;
this->base_reference() = this->base_reference() - 1;}
else
{sh = w - 1;
c = c - 1;
this->base_reference() -= out + 1;}}}}
typename boost::iterator_adaptor<image_iterator<Iterator>, Iterator>::difference_type distance_to(const image_iterator& iterator) const
{return (iterator.c - c) * w + (iterator.sh - sh);}
private:
size_t w;
size_t st;
size_t out;
size_t sh;
size_t c;};
template<class Container = std::vector<uint8_t>>
class image
{public:
image(size_t width, size_t height, size_t stride) :
data(stride * height),
width_(width),
stride_(stride) {}
auto begin()
{return image_iterator(data.begin(), width_, stride_);}
auto end()
{return image_iterator(data.end(), width_, stride_, 0, data.size() / stride_);}
auto begin() const
{return image_iterator(data.begin(), width_, stride_);}
auto end() const
{return image_iterator(data.end(), width_, stride_, 0, data.size() / stride_);}
private:
Container data; // image data including strides. Access by (x, y): data[y * stride_ + x]
size_t width_;
size_t stride_;
};
#endif // __ITERATOR_HPP__
