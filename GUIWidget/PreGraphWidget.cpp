#include "PreGraphWidget.h"
#include "FITK_Component/FITKRenderWindowVTK/FITKGraph3DWindowVTK.h"

namespace GUI
{
    PreGraphWidget::PreGraphWidget(QWidget* parent)
        :GraphArea(parent)
    {
        if(_renderWindow)
             _renderWindow->showScaleLegend(false);
    }

    GUI::GraphAreaType PreGraphWidget::getGraphAreaType()
    {
        return GATPre;
    }

}
