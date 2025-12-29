/**********************************************************************
 * @file   FITKAdaptorGeoModelCylinder.h
 * @brief  圆柱体适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-04-28
 *********************************************************************/
#ifndef FITKADAPTORGEOMODELCYLINDER_H
#define FITKADAPTORGEOMODELCYLINDER_H

#include "FITKAdaptorGeoCommand.h"
#include "FITKInterfaceGeoIOHDF5API.h"

namespace Interface
{
    /**
     * @brief  圆柱体适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-04-28
     */
    class FITKINTERFACEGEOIOHDF5API FITKAdaptorGeoModelCylinder : public FITKAdaptorGeoCommand
    {
    public:
        /**
         * @brief    构造
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        explicit FITKAdaptorGeoModelCylinder() = default;
        /**
         * @brief    析构
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        virtual ~FITKAdaptorGeoModelCylinder() = default;

   
    protected:
        /**
         * @brief    写出参数数据
         * @param[i] g 
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        virtual bool writeParameters(H5::Group & g) override;
        /**
         * @brief    读取参数数据
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        virtual bool readParameters() override;
         

    private:
        // 添加需要的私有成员
    };
}

#endif // FITKADAPTORGEOMODELCYLINDER_H
