/**********************************************************************
 * @file   FITKRadiossEquationOfStatePolynomialAdaptor.h
 * @brief  线性多项式状态方程适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-11-03
 *********************************************************************/
#ifndef FITKRadiossEquationOfStatePolynomialAdaptor_H
#define FITKRadiossEquationOfStatePolynomialAdaptor_H

#include "FITKRadiossDataHDF5Adaptor.h"
#include "FITKRadiossDataIOHDF5API.h"
#include "FITK_Kernel/FITKAdaptor/FITKIOAdaptorFactory.h"

namespace Radioss
{
    class FITKEquationOfStatePolynomial;
}
namespace Interface
{
    /**
     * @brief  线性多项式状态方程适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-11-03
     */
    class FITKRadiossDataIOHDF5API FITKRadiossEquationOfStatePolynomialAdaptor : public FITKRadiossDataHDF5Adaptor
    {
    public:
        explicit FITKRadiossEquationOfStatePolynomialAdaptor() = default;
        ~FITKRadiossEquationOfStatePolynomialAdaptor() = default;

        virtual bool adaptR() override;
        virtual bool adaptW() override;
    private:

    private:
        /**
         * @brief  线性多项式状态方程数据
         * @author guqingtao (15598887859@163.com)
         * @date   2025-11-03
         */
        Radioss::FITKEquationOfStatePolynomial* _data{};
    };
    Register2FITKIOAdaptorFactory(HDF5, Radioss::FITKEquationOfStatePolynomial, FITKRadiossEquationOfStatePolynomialAdaptor)
}

#endif 

