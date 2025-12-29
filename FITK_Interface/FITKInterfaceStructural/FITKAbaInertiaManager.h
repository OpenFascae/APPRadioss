/**
 * 
 * @file   FITKAbaInertiaManager.h
 * @brief  惯性元素管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-05-10
 * 
 */
#ifndef FITKABAINERTIAMANAGER_H
#define FITKABAINERTIAMANAGER_H
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaAbstractInertia.h"


namespace Interface {
    /**
     * @brief  惯性元素管理器
     * @author LiJin (1003680421@qq.com)
     * @date   2024-05-10
     */
    class FITKInterfaceStructuralAPI FITKAbaInertiaManager: public Core::FITKAbstractDataManager<FITKAbaAbstractInertia>,
                                                         public Core::FITKAbstractNDataObject
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-05-10
         */
        FITKAbaInertiaManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-05-10
         */
        ~FITKAbaInertiaManager() = default;
    };
}


#endif // FITKABAINERTIAMANAGER_H
