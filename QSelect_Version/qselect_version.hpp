#pragma once

#include <QtWidgets>

class QSelect_Version : public QWidget
{
    Q_OBJECT

public:
    QSelect_Version(QWidget *parent = nullptr,
                    const QString ndelimiter = ".",
                    QString nprefix = "v");
    ~QSelect_Version();

    void setDelimiter(const QString& ndelimiter);
    void setPrefix(QString nprefix);

    void load(int maj, int min, int pat);
    void load(QString maj, QString min, QString pat);

    QString getMajor();
    QString getMinor();
    QString getPatch();

    QString getVersion();

private:
    QString prefix;
    QString delimiter;

    QLineEdit* major { nullptr };
    QLineEdit* minor { nullptr };
    QLineEdit* patch { nullptr };

    QLabel* sep_0{ nullptr };
    QLabel* sep_1{ nullptr };
    QLabel* sep_2{ nullptr };

    QHBoxLayout* layout { nullptr };
};
