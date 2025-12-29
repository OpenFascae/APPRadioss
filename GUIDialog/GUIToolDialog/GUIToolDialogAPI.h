/**********************************************************************
 * @file   GUIToolDialogAPI.h
 * @brief  外部宏接口
 * @author liuzhonghua (liuzhonghuaszch@163.com)
 * @date   2025-08-22
 *********************************************************************/
#ifndef _GUITOOLDIALOG_API_H__
#define _GUITOOLDIALOG_API_H__

#include <QtCore/QtGlobal>

#ifdef  GUIToolDialog_API
#define GUIToolDialogAPI Q_DECL_EXPORT
#else
#define GUIToolDialogAPI Q_DECL_IMPORT
#endif

#endif
