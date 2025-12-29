/**********************************************************************
 * @file   GraphDataProviderAPI.h
 * @brief  接口导出宏
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-04-17
 *********************************************************************/
#ifndef __GRAPHDATAPROVIDERAPI_H__
#define __GRAPHDATAPROVIDERAPI_H__

#include <QtCore/QtGlobal>

#include <QDebug>

#if defined( GRAPHDATAPROVIDER_API )
#    define GraphDataProviderAPI Q_DECL_EXPORT
#else
#    define GraphDataProviderAPI Q_DECL_IMPORT
#endif

#endif // __GRAPHDATAPROVIDERAPI_H__
