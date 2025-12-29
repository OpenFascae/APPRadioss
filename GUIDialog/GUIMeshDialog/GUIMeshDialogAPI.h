/**********************************************************************
 * @file   GUIMeshDialogAPI.h
 * @brief  宏接口
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-07-22
 *********************************************************************/
#ifndef _GUIMeshDialog_H__
#define _GUIMeshDialog_H__

#include <QtCore/QtGlobal>

#ifdef GUIMeshDialog_API
#define GUIMeshDialogAPI Q_DECL_EXPORT
#else
#define GUIMeshDialogAPI Q_DECL_IMPORT
#endif

#endif
