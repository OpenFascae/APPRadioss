#include "PostGraphWidget.h"

namespace GUI
{
    PostGraphWidget::PostGraphWidget(QWidget* parent)
        :GraphArea(parent)
    {
    }

    GUI::GraphAreaType PostGraphWidget::getGraphAreaType()
    {
        return GATPost;
    }

}
