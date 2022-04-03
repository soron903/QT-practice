#ifndef FILEMD5_H
#define FILEMD5_H

#include <QObject>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QCryptographicHash>
#include <QHash>


class FileMd5 : public QObject
{
    Q_OBJECT
public:
    explicit FileMd5(QObject *parent = nullptr);

public slots:
    void checkDumlate(const QString &path);

signals:
    void gotDumplate(const QHash<QByteArray,QStringList> &dumplates);
    void progress(int current, int total);

private:
    QStringList getfiles(const QString &path);
    QByteArray getFileMd5(const QString &fileName);

};

#endif // FILEMD5_H
