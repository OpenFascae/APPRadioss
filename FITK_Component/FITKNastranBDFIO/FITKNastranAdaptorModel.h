/**********************************************************************
 * @file   FITKNastranAdaptorModel.h
 * @brief  Nastran bdf 文件 模型读写适配器
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-03-13
 *********************************************************************/
#ifndef _FITKNASTRANADAPTORMODEL_H
#define _FITKNASTRANADAPTORMODEL_H

#include "FITKNastranAbstractAdaptor.h"

namespace Interface
{
    class FITKAbstractElement;
}

namespace Nastran
{
    class FITKNastranAdaptorModelNode : public FITKNastranAbstractAdaptor
    {
    public:
        explicit FITKNastranAdaptorModelNode() = default;
        virtual ~FITKNastranAdaptorModelNode() = default;

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

    };

    class FITKNastranAdaptorModelElement : public FITKNastranAbstractAdaptor
    {
    public:
        explicit FITKNastranAdaptorModelElement() = default;
        virtual ~FITKNastranAdaptorModelElement() = default;

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

        bool readCBAR(QStringList data);

        bool readCTRIA3(QStringList data);

        bool readCQUAD4(QStringList data);

        bool readCHEXA(QStringList data);

        bool readCTETRA(QStringList data);

        bool writeCBAR(Interface::FITKAbstractElement* element);

        bool writeCTRIA3(Interface::FITKAbstractElement* element);

        bool writeCQUAD4(Interface::FITKAbstractElement* element);

        bool writeCHEXA(Interface::FITKAbstractElement* element);

        bool writeCTETRA(Interface::FITKAbstractElement* element);
    };

    Register2FITKIOAdaptorFactory(BDF, NastranModelNode, FITKNastranAdaptorModelNode);
    Register2FITKIOAdaptorFactory(BDF, NastranModelElement, FITKNastranAdaptorModelElement);
} // namespace Nastran

#endif // FITKNASTRANADAPTORPART_H
