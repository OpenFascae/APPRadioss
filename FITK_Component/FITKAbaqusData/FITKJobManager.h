/**
 * 
 * @file FITKJobManager.h
 * @brief 作业管理器声明
 * @author BaGuijun (baguijun@163.com)
 * @date 2024-04-01
 * 
 */
#ifndef _FITKJobManager_H_
#define _FITKJobManager_H_
#include "FITKAbaqusDataAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"

namespace AbaqusData
{
    class FITKJob;
    /**
     * @brief 作业管理器声明
     * @author BaGuijun (baguijun@163.com)
     * @date 2024-04-01
     */
    class FITKAbaqusDataAPI FITKJobManager : public Core::FITKAbstractDataManager< FITKJob >
    {
    public:
        /**
         * @brief Construct a new FITKJobManager object
         * @author BaGuijun (baguijun@163.com)
         * @date 2024-04-01
         */
        FITKJobManager();
        /**
         * @brief Destroy the FITKJobManager object
         * @author BaGuijun (baguijun@163.com)
         * @date 2024-04-01
         */
        ~FITKJobManager();
    };
};  // namespace Document
#endif
