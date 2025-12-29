/**********************************************************************
 * @file   GraphDataVTKAdaptorAPI.h
 * @brief  接口
 * @author ZhouZhaoYi (zhouzhaoyi@diso.cn)
 * @date   2025-05-22
 *********************************************************************/
#ifndef _GraphDataVTKAdaptorAPI_H
#define _GraphDataVTKAdaptorAPI_H

#include <QtCore/QtGlobal>

#if defined(GraphDataVTKAdaptor_API)
#define GraphDataVTKAdaptorAPI Q_DECL_EXPORT
#else
#define GraphDataVTKAdaptorAPI Q_DECL_IMPORT
#endif

#endif
