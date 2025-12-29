/**********************************************************************
 * @file   FITKFailureModelJOHNSON.h
 * @brief  失效模型JOHNSON
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-11-10
 *********************************************************************/
#ifndef FITK_FailureModel_JOHNSON_H
#define FITK_FailureModel_JOHNSON_H

#include "FITKAbstractFailureModel.h"

namespace Radioss
{
    /**
     * @brief  失效模型JOHNSON(/FAIL/JOHNSON)
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-11-10
     */
    class FITKRadiossDataAPI FITKFailureModelJOHNSON : public FITKAbstractFailureModel
    {
        Q_OBJECT
        FITKCLASS(Radioss, FITKFailureModelJOHNSON); //!< FITK类标识
        RadiossKeyWord(FITKFailureModelJOHNSON, /FAIL/JOHNSON) //!< Radioss关键字标识
    public:
        explicit FITKFailureModelJOHNSON();
        virtual ~FITKFailureModelJOHNSON();
        /**
         * @brief    获取失效模型类型
         * @return   FailureModelType
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-10
         */
        FailureModelType getFailureModelType();

        void setD1(const double value);
        double getD1() const;
        void setD2(const double value);
        double getD2() const;
        void setD3(const double value);
        double getD3() const;
        void setD4(const double value);
        double getD4() const;
        void setD5(const double value);
        double getD5() const;
        void setEps0(const double value);
        double getEps0() const;
        void setIfailsh(const int flag);
        int getIfailsh() const;
        void setIfailso(const int flag);
        int getIfailso() const;
        void setDadv(const double value);
        double getDadv() const;
        void setIxfem(const int flag);
        int getIxfem() const;

    private:
        /**
         * @brief  1th parameter
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_d1{ 0.0 };
        /**
         * @brief  2th parameter
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_d2{ 0.0 };
        /**
         * @brief  3th parameter
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_d3{ 0.0 };
        /**
         * @brief  4th parameter
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_d4{ 0.0 };
        /**
         * @brief  5th parameter
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_d5{ 0.0 };
        /**
         * @brief  Shell failure flag
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_eps_0{ 0.0 };
        /**
         * @brief  Shell failure flag
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        int m_Ifail_sh{ 1 };
        /**
         * @brief  Solid failure flag
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        int m_Ifail_so{ 1 };
        /**
         * @brief  Criterion for the crack advancement (Only active if with Ixfem =1). between 0 and 1
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_Dadv{ 1 };
        /**
         * @brief  	XFEM flag
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        int m_Ixfem{ 0 };
    };
    
} // namespace Radioss

#endif // FITK_ABSTRACT_BCS_H
