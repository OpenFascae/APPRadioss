/**********************************************************************
 * @file   AppInitializer.h
 * @brief  初始化器
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-09-23
 *********************************************************************/
#ifndef _APP_INITIALIZER_H___
#define _APP_INITIALIZER_H___

#include "FITK_Kernel/FITKAppFramework/FITKAbstractAppInitializer.h"

/**
  * @brief  初始化器声明
  * @author liuzhonghua (liuzhonghuaszch@163.com)
  * @date   2025-09-23
  */
class AppInitializer : public AppFrame::FITKAbstractAppInitializer
{
public:
    /**
     * @brief Construct a new App Initializer object
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-09-23
     */
    explicit AppInitializer() = default;
    /**
     * @brief Destroy the App Initializer object
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-09-23
     */
    virtual ~AppInitializer() = default;
    /**
     * @brief 执行初始化操作，初始化失败将直接退出程序
     * @return true  初始化成功
     * @return false  初始化失败
     * @author liuzhonghua (liuzhonghuaszch@163.com)
     * @date   2025-09-23
     */
    bool init() override;

private:
    /**
     * @brief    初始化运行时的设置
     * @return   void
     * @author   liuzhonghua (liuzhonghuaszch@163.com)
     * @date     2025-09-23
     */
    void initRunTimeSetting();
};


#endif
