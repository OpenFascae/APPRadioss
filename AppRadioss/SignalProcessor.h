/**
 * 
 * @file SignalProcessor.h
 * @brief 信号处理器
 * @author LiBaojun (libaojunqd@foxmail.com)
 * @date 2024-11-04
 * 
 */
#ifndef _SIGNAL_PROCESSOR_H___
#define _SIGNAL_PROCESSOR_H___
 
#include <QObject>

namespace AppFrame
{
    class FITKAbstractProgramerDriver;
}
/**
 * @brief 信号处理器
 * @author LiBaojun (libaojunqd@foxmail.com)
 * @date 2024-11-04
 */
class SignalProcessor : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Construct a new Signal Processor object
     * @author LiBaojun (libaojunqd@foxmail.com)
     * @date 2024-11-04
     */
    explicit SignalProcessor() = default;
    /**
     * @brief Destroy the Signal Processor object
     * @author LiBaojun (libaojunqd@foxmail.com)
     * @date 2024-11-04
     */
    virtual ~SignalProcessor() = default;


protected slots:
    /**
     * @brief 处理求解信息
     * @param[i]  driver         求解驱动器
     * @param[i]  messageType    信息类型
     * @param[i]  message        信息内容
     * @author LiBaojun (libaojunqd@foxmail.com)
     * @date 2024-11-04
     */
    void on_sendProgramDriverMessageSig(AppFrame::FITKAbstractProgramerDriver* driver, int messageType, const QString& message);

    /**
      * @brief 线程进度信号 0~100
      * @param[o]  sender         发送的进程任务
      * @param[o]  process        线程进度 0-100
      * @author LiBaojun (libaojunqd@foxmail.com)
      * @date 2024-11-04
      */
    void on_sendProcessSig(QObject* sender, int process);
};

#endif
