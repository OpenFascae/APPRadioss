/**
 * 
 * @file   FITKAbaHistoryOutputManager.h
 * @brief  历程输出管理器
 * @author LiJin (1003680421@qq.com)
 * @date   2024-04-22
 * 
 */
#ifndef FITKABAHISTORYOUTPUTMANAGER_H
#define FITKABAHISTORYOUTPUTMANAGER_H
#include "FITK_Kernel/FITKCore/FITKAbstractDataObject.h"
#include "FITK_Kernel/FITKCore/FITKAbstractDataManager.hpp"
#include "FITKInterfaceStructuralAPI.h"
#include "FITKAbaHistoryOutput.h"


namespace Interface {
    class FITKAbaAbstractStep;
    /**
     * @brief  历程输出管理器类
     * @author LiJin (1003680421@qq.com)
     * @date   2024-04-22
     */
    class FITKInterfaceStructuralAPI FITKAbaHistoryOutputManager: public Core::FITKAbstractDataObject
        , public Core::FITKAbstractDataManager<FITKAbaHistoryOutput>
    {
    public:
        /**
         * @brief  构造函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        FITKAbaHistoryOutputManager() = default;
        /**
         * @brief  析构函数
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-28
         */
        ~FITKAbaHistoryOutputManager() = default;
        /**
         * @brief  删除分析步中的所有历程输出
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-22
         */
        void deleteStepHistoryOutput(int stepId);
        /**
         * @brief  为分析步创建默认的历程输出
         * @param[in]  
         * @return 
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-25
         */
        void createDefaultHistoryOutput(FITKAbaAbstractStep* step);
        /**
         * @brief  分析步替换时，对数据进行处理
         * @param[in]
         * @return
         * @author LiJin (1003680421@qq.com)
         * @date   2024-04-26
         */
        void replaceStep(int oldStep, int newStep);
    };
}


#endif // FITKABAHISTORYOUTPUTMANAGER_H
