/**********************************************************************
 * @file   FITKAdaptorGeoModelSphere.h
 * @brief  球体适配器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-04-28
 *********************************************************************/
#ifndef FITKADAPTORGEOMODELSPHERE_H
#define FITKADAPTORGEOMODELSPHERE_H

#include "FITKAdaptorGeoCommand.h"
#include "FITKInterfaceGeoIOHDF5API.h"

namespace Interface
{
    /**
     * @brief  球体适配器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-04-28
     */
    class FITKINTERFACEGEOIOHDF5API FITKAdaptorGeoModelSphere : public FITKAdaptorGeoCommand
    {
    public:
        /**
         * @brief    构造
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        explicit FITKAdaptorGeoModelSphere() = default;
        /**
         * @brief    析构
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-04-28
         */
        virtual ~FITKAdaptorGeoModelSphere() = default;

   
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

#endif // FITKADAPTORGEOMODELSPHERE_H
