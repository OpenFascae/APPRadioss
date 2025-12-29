 
#ifndef _FITK_PLOTWINDOW_API_H_
#define _FITK_PLOTWINDOW_API_H_

#include <QtCore/QtGlobal>


#if defined(FITKPlotWindow_API)
#define FITKPlotWindowAPI Q_DECL_EXPORT
#else
#define FITKPlotWindowAPI Q_DECL_IMPORT
#endif

#ifndef FITKPLOTWINDOWVERSION
#define FITKPLOTWINDOWVERSION "1.0.0"
#endif

#endif // _FITK_PLOTWINDOW_API_H_