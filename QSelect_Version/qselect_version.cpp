#include "qselect_version.hpp"
#include <QRegularExpressionValidator>
#include <QRegularExpression>

QSelect_Version::QSelect_Version(QWidget *parent, QString ndelimiter, QString nprefix)
    : QWidget(parent), delimiter{ ndelimiter }, prefix{ nprefix }
{
    QRegularExpression vrgx("\\d{9}");

    major = new QLineEdit(this);
        major->setValidator(new QRegularExpressionValidator(vrgx, major));

    minor = new QLineEdit(this);
        minor->setValidator(new QRegularExpressionValidator(vrgx, minor));

    patch = new QLineEdit(this);
        patch->setValidator(new QRegularExpressionValidator(vrgx, patch));

    sep_0 = new QLabel(prefix, this);
    sep_1 = new QLabel(delimiter, this);
    sep_2 = new QLabel(delimiter, this);

    layout = new QHBoxLayout(this);
        layout->addWidget(sep_0);
        layout->addWidget(major);
        layout->addWidget(sep_1);
        layout->addWidget(minor);
        layout->addWidget(sep_2);
        layout->addWidget(patch);

    setLayout(layout);
}

QSelect_Version::~QSelect_Version()
{
    delete major;
    delete minor;
    delete patch;
}

void QSelect_Version::setDelimiter(QString ndelimiter)
{
    delimiter = ndelimiter;
    sep_1->setText(delimiter);
    sep_2->setText(delimiter);
}

void QSelect_Version::setPrefix(QString nprefix)
{
    prefix = nprefix;
    sep_0->setText(prefix);
}

void QSelect_Version::load(int maj, int min, int pat)
{
    major->clear();
    major->setText(QString::number(maj));
    minor->clear();
    minor->setText(QString::number(min));
    patch->clear();
    patch->setText(QString::number(pat));
}

void  QSelect_Version::load(QString maj, QString min, QString pat)
{
    load(maj.toInt(), min.toInt(), pat.toInt());
}

QString QSelect_Version::getMajor()
{
    return major->text();
}

QString QSelect_Version::getMinor()
{
    return minor->text();
}

QString QSelect_Version::getPatch()
{
    return patch->text();
}

QString QSelect_Version::getVersion()
{
    return QString(prefix + getMajor() + delimiter + getMinor() + delimiter + getPatch());
}