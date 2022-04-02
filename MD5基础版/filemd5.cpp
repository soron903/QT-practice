#include "filemd5.h"

FileMd5::FileMd5(QObject *parent) : QObject(parent)
{

}

void FileMd5::checkDumlate(const QString &path)
{
    QHash<QByteArray,QStringList> ret;
    QStringList files = getfiles(path);


    for(int i=0; i<files.count(); i++)
    {
        QString fileName = files.at(i);
        QByteArray md5 = getFileMd5(fileName);
//        qDebug()<<md5.toHex();

        ret[md5].push_back(fileName);

        emit progress(i+1,files.count());
    }

    emit gotDumplate(ret);
}


QStringList FileMd5::getfiles(const QString &path)
{
    QStringList ret;
    QDir dir(path);
    QFileInfoList infolist = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Files|QDir::Dirs);

    for(int i = 0; i<infolist.count(); i++)
    {
        QFileInfo info = infolist.at(i);
        if(info.isDir())
        {
            QString subDir = info.absoluteFilePath();
            //如果目录存在，就启用getfile，传入目录，参数
            QStringList files = getfiles(subDir);

            ret.append(files);
        }
        else
        {
            QString fileName = info.absoluteFilePath();
            ret.append(fileName);
        }
    }


    return ret;
}
QByteArray FileMd5::getFileMd5(const QString &fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {

        //文件较大时，内存不一定够用，可以使用这种方法
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd())
        {
            QByteArray content = file.read(100*1024*1024);
            hash.addData(content);

        }
        QByteArray md5 = hash.result().toHex();

        return md5;

        file.close();
    }
    else
    {
        perror("文件打开错误： ");
        return QByteArray();
    }
    return QByteArray();
}



