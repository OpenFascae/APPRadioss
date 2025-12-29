#include "FITKPolarPlotProperty.h"
#include "FITKPolarPlotWindow.h"
#include <qwt_polar_plot.h>

namespace Plot
{
    FITKPolarPlotProperty::FITKPolarPlotProperty(FITKPolarPlotWindow * Window):_window(Window)
    {
    }
    FITKPolarPlotProperty::~FITKPolarPlotProperty()
    {
    }
    void FITKPolarPlotProperty::setTitle(const QString & name)
    {
        if (!_window)return;
        if (name.isEmpty())return;
        _window->getPolarWidget()->setTitle(name);
    }
}