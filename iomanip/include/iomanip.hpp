/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Cmarguer
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>

//<class char, class traits>
//decltype(auto) endm(std::basic_ostream<char>& os)
//{ endm manipulator

template <class charT, class traits>
decltype(auto) endm(std::basic_ostream<charT,traits>& os)
{
	char c[6] = {'[','e','o','l',']','\n'};
	for(int i = 0; i < 6; i++) 
		os.put(os.widen(c[i]));
	return (os.flush());
}
//}

//{ squares manipulator

class Hugs
{
	private:
		std::ostream* p_os;

	public:
		Hugs(std::ostream* os)
		{
			p_os = os;
		}
		template<typename T>
			std::ostream& operator<< (T str)
			{
				return (*p_os <<  "[" << str << "]");
			}
};

struct Squares
{
	public:
		friend Hugs operator<< (std::ostream& os, Squares)
		{
			return Hugs(&os);
		}
};
static const Squares squares;
//}

//{ add manipulator
template<typename T>
class Sum
{
	private:
		std::ostream* p_os;
		T p_left;
	public:
		Sum(std::ostream* os, T left)
		{
			p_os = os;
			p_left = left;
		}
		std::ostream& operator<< (const T& right)
		{
			return (*p_os << p_left + right);
		}
};

class Sum2
{
	private:
		std::ostream* p_os;
	public:
		Sum2(std::ostream* os)
		{
			p_os = os;
		}
		template<typename T>
			friend Sum<T> operator<< (Sum2 s2, const T& s1)
			{
				return Sum<T>(s2.p_os, s1);
			}	
};

struct Two_manip
{
	public:
		friend Sum2 operator<< (std::ostream& os, Two_manip)
		{
			return (Sum2(&os));
		}
};
static const Two_manip add;

//}

#endif // __IOMANIP_HPP__
