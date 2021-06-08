#pragma once
#include <iostream>

namespace gab
{
	struct complex
	{
		double r; // real part
		double i; // image part

		complex() {
			r = 0;
			i = 0;
		}

		template <typename anyType_1, typename anyType_2>
		complex(anyType_1 r, anyType_2 i) {
			this->r = static_cast<double>(r);
			this->i = static_cast<double>(i);
		}

		void print() const
		{
			if (i < 0)  std::cout << r << i << "i";
			else std::cout << r << "+" << i << "i";
		}

		friend std::ostream& operator << (std::ostream& out, const complex& num);
	};

	
	inline std::ostream& operator << (std::ostream& out, const complex& num)
	{
		if (num.i < 0)  out << num.r << num.i << "i";
		else out << num.r << "+" << num.i << "i";
		return out;
	}

	inline complex operator + (complex& A, complex& B)
	{
		complex C;
		C.r = A.r + B.r;
		C.i = A.i + B.i;
		return C;
	}

	inline complex operator - (complex& A, complex& B)
	{
		complex C;
		C.r = A.r - B.r;
		C.i = A.i - B.i;
		return C;
	}

	inline complex operator * (complex& A, complex& B)
	{
		complex C;
		C.r = A.r * B.r - A.i * B.i;
		C.i = A.r * B.i + B.r * A.i;
		return C;
	}

	inline complex operator / (complex& A, complex& B)
	{
		complex C;
		C.r = (A.r * B.r + A.i * B.i) / (B.r * B.r + B.i * B.i);
		C.i = (B.r * A.i - A.r * B.i) / (B.r * B.r + B.i * B.i);
		return C;
	}
}
