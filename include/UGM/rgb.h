#pragma once

#include "Interfaces/ILinear.h"
#include "Interfaces/IArray/IArrayLinear.h"
#include "Interfaces/IArray/IArrayHadamardProduct.h"
#include "Interfaces/IArray/IArray1D_Util.h"

namespace Ubpa {
	template<typename T>
	struct rgb : SIIT_CRTP<TemplateList<IArray1D_Util, IArrayHadamardProduct, IArrayLinear>, rgb<T>,
		TypeList<TypeList<T, Size<3>>, T>>
	{
		using SIIT_CRTP<TemplateList<IArray1D_Util, IArrayHadamardProduct, IArrayLinear>, rgb<T>,
			TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;
		T illumination() const noexcept {
			return static_cast<T>(0.2126)* (*this)[0]
				+ static_cast<T>(0.7152)* (*this)[1]
				+ static_cast<T>(0.0722)* (*this)[2];
		}

		T gray() const noexcept {
			return
				(*this)[0] * static_cast<T>(0.299)
				+ (*this)[1] * static_cast<T>(0.587)
				+ (*this)[2] * static_cast<T>(0.114);
		}
	};

	using rgbf = rgb<float>;
}
