#pragma once

#include <QtWidgets>
//#include "ui_qselect_version.h"

class QSelect_Version : public QWidget
{
    Q_OBJECT

public:
    QSelect_Version(QWidget *parent = nullptr, QString ndelimiter = ".", QString nprefix = "v");
    ~QSelect_Version();

    void setDelimiter(QString ndelimiter);
    void setPrefix(QString nprefix);

    void load(int ma, int mi, int pa);

    int getMajor();
    int getMinor();
    int getPatch();

    QString getVersion();

private:
    //Ui::QSelect_VersionClass ui;
    QString prefix;
    QString delimiter;

    QLineEdit* major{ nullptr };
    QLineEdit* minor{ nullptr };
    QLineEdit* patch{ nullptr };

    QLabel* sep_0{ nullptr };
    QLabel* sep_1{ nullptr };
    QLabel* sep_2{ nullptr };

    QHBoxLayout* layout{ nullptr };
};
