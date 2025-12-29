#include "RadiossAppSettings.h"
#include <QSettings>
#include <QFile>

void RadiossAPPSettings::read()
{
    //读入文件
    QString file = _appDir + "/IGAAPP.ini";
    QFile f(file);
    //文件不存在则创建
    if (!f.exists())
    {
        if (f.open(QFile::WriteOnly))
        {
            //创建文件
            f.write("");
            f.close();
        }
    }
    //读取文件
    _settings = new QSettings(file, QSettings::IniFormat);
}



