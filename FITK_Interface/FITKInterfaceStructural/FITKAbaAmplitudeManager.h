/**
 * 
 * @file   FITKAbaAmplitudeManager.h
 * @brief  幅值曲线管理
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-03
 * 
 */
#ifndef FITKABAAMPLITUDEMANAGER_H
#define FITKABAAMPLITUDEMANAGER_H
#include "FITKInterfaceStructuralAPI.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITKAbaAbstractAmplitude.h"


namespace Interface {
    /**
     * @brief  幅值曲线管理类
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-03
     */
    class FITKAbaAmplitudeManager: public Core::FITKAbstractDataObject
        , public Core::FITKAbstractDataManager<FITKAbaAbstractAmplitude>
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaAmplitudeManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaAmplitudeManager() = default;
    };

}
#endif // FITKABAAMPLITUDEMANAGER_H


