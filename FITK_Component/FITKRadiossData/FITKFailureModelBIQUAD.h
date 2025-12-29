/**********************************************************************
 * @file   FITKFailureModelBIQUAD.h
 * @brief  失效模型BIQUAD类声明
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-11-10
 *********************************************************************/
#ifndef FITK_FailureModel_BIQUAD_H
#define FITK_FailureModel_BIQUAD_H

#include "FITKAbstractFailureModel.h"

namespace Radioss
{
    /**
     * @brief  失效模型BIQUAD(/FAIL/BIQUAD)
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-11-10
     */
    class FITKRadiossDataAPI FITKFailureModelBIQUAD : public FITKAbstractFailureModel
    {
        Q_OBJECT
        FITKCLASS(Radioss, FITKFailureModelBIQUAD); //!< FITK类标识
        RadiossKeyWord(FITKFailureModelBIQUAD, /FAIL/BIQUAD) //!< Radioss关键字标识

    public:
        explicit FITKFailureModelBIQUAD();
        virtual ~FITKFailureModelBIQUAD();
        /**
         * @brief    获取失效模型类型
         * @return   FailureModelType
         * @author   liuzhonghua (liuzhonghuaszch@163.com)
         * @date     2025-11-10
         */
        FailureModelType getFailureModelType();

        void setC1(const double value);
        double getC1() const;
        void setC2(const double value);
        double getC2() const;
        void setC3(const double value);
        double getC3() const;
        void setC4(const double value);
        double getC4() const;
        void setC5(const double value);
        double getC5() const;
        void setPthickfail(const double value);
        double getPthickfail() const;
        void setMFlag(const int flag);
        int getMFlag() const;
        void setSFlag(const int flag);
        int getSFlag() const;
        void setInststart(const double value);
        double getInststart()const;
        void setFctIDel(const int id);
        int getFctIDel() const;
        void setElref(const double value);
        double getElref()const;
        void setR1(const double value);
        double getR1()const;
        void setR2(const double value);
        double getR2()const;
        void setR4(const double value);
        double getR4()const;
        void setR5(const double value);
        double getR5()const;

    private:
        /**
         * @brief  Failure plastic strain at uniaxial compression.
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_c1{ 0.0 };
        /**
         * @brief  Failure plastic strain at shear.
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_c2{ 0.0 };
        /**
         * @brief  Failure plastic strain in uniaxial tension.
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_c3{ 0.0 };
        /**
         * @brief  Failure plastic strain at plain strain tension.
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_c4{ 0.0 };
        /**
         * @brief  Failure strain at biaxial tension.
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_c5{ 0.0 };
        /**
         * @brief  	Percentage of through thickness integration points that must fail before the element is deleted (shells only).
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_P_thickfail{ 1.0 };
        /**
         * @brief  Material selector flag
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        int m_M_Flag{ 0 };
        /**
         * @brief  Specific behavior flag. 
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        int m_S_Flag{ 1 };
        /**
         * @brief  Instability start value for localized necking
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_Inst_start{ 0.0 };
        /**
         * @brief  	Element size factor function identifier
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        int m_fct_IDel{ -1 };
        /**
         * @brief  Reference element size.
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_El_ref{ 1.0 };
        /**
         * @brief  Failure plastic strain ratio,  M-Flag=99
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_r1{ 0.0 };
        /**
         * @brief  Failure plastic strain ratio,  M-Flag=99
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_r2{ 0.0 };
        /**
         * @brief  Failure plastic strain ratio,  M-Flag=99
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_r4{ 0.0 };
        /**
         * @brief  Failure plastic strain ratio,  M-Flag=99
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-11-10
         */
        double m_r5{ 0.0 };
    };
    
} // namespace Radioss

#endif // FITK_ABSTRACT_BCS_H
