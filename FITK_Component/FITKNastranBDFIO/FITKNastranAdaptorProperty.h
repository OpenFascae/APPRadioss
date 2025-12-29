/**********************************************************************
 * @file   FITKNastranAdaptorProperty.h
 * @brief  Nastran bdf 文件 属性读写适配器
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-03-12
 *********************************************************************/
#ifndef _FITKNASTRANADAPTORPROPERTY_H
#define _FITKNASTRANADAPTORPROPERTY_H

#include "FITKNastranAbstractAdaptor.h"

namespace Nastran
{
    class FITKNastranAdaptorProperty : public FITKNastranAbstractAdaptor
    {
    public:
        explicit FITKNastranAdaptorProperty() = default;
        virtual ~FITKNastranAdaptorProperty() = default;

        /**
         * @brief  适配器读取
         * @return bool 状态 true成功， false失败
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-03-12
         */
        bool adaptR() override;

        /**
         * @brief  适配器写出
         * @return bool 状态 true成功， false失败
         * @author liuzhonghua (liuzhonghuaszch@163.com)
         * @date   2025-03-12
         */
        bool adaptW() override;

    private:

        bool readPSHELL(QStringList data);
        bool writePSHELL();

        bool readPBAR(QStringList data);
        bool writePBAR();
    };

    Register2FITKIOAdaptorFactory(BDF, NastranProperty, FITKNastranAdaptorProperty);
} // namespace Nastran

#endif // FITKNASTRANADAPTORPSHELL_H
