/**********************************************************************
 * @file   FITKRadiossLSDynaWriter.h
 * @brief  LS-Dyna文件写入器
 * @author guqingtao (15598887859@163.com)
 * @date   2025-07-01
 *********************************************************************/
#ifndef _FITKRadiossLSDynaWriter_H_
#define _FITKRadiossLSDynaWriter_H_

#include "FITK_Interface/FITKInterfaceIO/FITKAbstractTextWriter.h"

namespace Radioss
{
    /**
     * @brief  LS-Dyna文件写入器
     * @author guqingtao (15598887859@163.com)
     * @date   2025-07-01
     */
    class FITKRadiossLSDynaWriter : public Interface::FITKAbstractTextWriter
    {
        Q_OBJECT
    public:
        explicit FITKRadiossLSDynaWriter(bool & success);
        virtual ~FITKRadiossLSDynaWriter() = default;
        /**
         * @brief 执行写入操作
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-07-01
         */
        virtual void run() override;
        /**
         * @brief 打印控制台消息
         * @param[i] level 打印级别 1 normal 2 warning 3error
         * @param[i] str 打印的信息
         * @author   guqingtao (15598887859@163.com)
         * @date     2025-07-01
         */
        void consoleMessage(int level, const QString& str) override;

    private:
        /**
         * @brief  成功标记
         * @author guqingtao (15598887859@163.com)
         * @date   2025-07-01
         */
        bool & _success;
    };
}

#endif