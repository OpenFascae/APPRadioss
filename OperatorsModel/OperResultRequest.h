/**********************************************************************
 * @file   OperResultRequest.h
 * @brief  结果请求操作器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-09-09
 *********************************************************************/
#ifndef __OperResultRequest__H__
#define __OperResultRequest__H__

#include "FITK_Kernel/FITKCore/FITKActionOperator.h"
#include "FITK_Kernel/FITKCore/FITKOperatorRepo.h"

namespace ModelOper
{
    /**
     * @brief  结果请求操作器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-09-09
     */
    class OperResultRequest :public Core::FITKActionOperator
    {
        Q_OBJECT;
    public:
        /**
         * @brief    构造
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-09
         */
        explicit OperResultRequest() = default;
        /**
         * @brief    析构
         * @return   void
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-09
         */
        virtual ~OperResultRequest() = default;

        /**
         * @brief    执行界面操作
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-09
         */
        virtual bool execGUI() override;
        /**
         * @brief    执行业务逻辑
         * @return   bool
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-09-09
         */
        virtual bool execProfession() override;

    private:

    };
    Register2FITKOperatorRepo(actionResultRequest, OperResultRequest);

}
#endif