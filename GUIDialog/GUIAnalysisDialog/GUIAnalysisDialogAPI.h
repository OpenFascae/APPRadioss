/**********************************************************************
 * @file   GUIAnalysisDialogAPI.h
 * @brief  载荷的对话窗外部接口声明
 * @author wangning (2185896382@qq.com)
 * @date   2025-05-22
 *********************************************************************/
#ifndef __GUIAnalysisDialogAPI_H_
#define __GUIAnalysisDialogAPI_H_

#include <QtCore/QtGlobal>

#if defined( GUIAnalysisDialog_API )
#    define GUIAnalysisDialogAPI Q_DECL_EXPORT
#else
#    define GUIAnalysisDialogAPI Q_DECL_IMPORT
#endif

#endif // __GUIAnalysisDialogAPI_H_
