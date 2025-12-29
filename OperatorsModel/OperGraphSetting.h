/**********************************************************************
 * @file   OperGraphSetting.h
 * @brief  渲染图形设置操作器
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-10-27
 *********************************************************************/
#ifndef _OperGraphSetting_H__
#define _OperGraphSetting_H__

#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"
#include "FITK_Kernel/FITKCore/FITKActionOperator.h"

namespace OperModel
{
    /**
     * @brief  渲染图形设置操作器
     * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
     * @date   2025-10-27
     */
    class OperGraphSetting :public Core::FITKActionOperator
    {
        Q_OBJECT;
    public:
        /**
         * @brief    Gmsh渲染图形设置操作器
         * @return   void
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-10-27
         */
        explicit OperGraphSetting() = default;
        virtual ~OperGraphSetting() = default;

        /**
         * @brief    执行界面操作
         * @return   true     执行成功
         * @return   false     执行失败
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-10-27
         */
        virtual bool execGUI() override;
        /**
         * @brief    执行读入操作
         * @return   true     执行成功
         * @return   false     执行失败
         * @author   ZhouZhaoYi (zhouzhaoyi@diso.cn)
         * @date     2025-10-27
         */
        virtual bool execProfession() override;
    };
    Register2FITKOperatorRepo(actionGraphSetting, OperGraphSetting);
    Register2FITKOperatorRepo(actionPointVisible, OperGraphSetting);
    Register2FITKOperatorRepo(actionLineVisible, OperGraphSetting);
    Register2FITKOperatorRepo(actionGeoVisible, OperGraphSetting);
    Register2FITKOperatorRepo(actionMeshPointVisible, OperGraphSetting);
    Register2FITKOperatorRepo(actionMeshLineVisible, OperGraphSetting);
    Register2FITKOperatorRepo(actionPartVisible, OperGraphSetting);
}
#endif // !_OperGraphSetting_H__
