# QSelect_Version
semantic version selection widget. version strings are digit-only, and limited to nine characters.
## construction
all parameters are optional.
```
   QSelect_Version(QWidget *parent = nullptr,
                    QString ndelimiter = ".",
                    QString nprefix = "v");
```

## changing the delimiter and prefix
```
  void setDelimiter(QString ndelimiter);
  void setPrefix(QString nprefix);
```

## accessing data
```
  QString getMajor();
  QString getMinor();
  QString getPatch();
  
  QString getVersion(); //returns the full version string: [prefix] major [delimiter] minor [delimiter] patch
```

## setting data
a QString overload is provided:
```
  void load(int maj, int min, int pat);
  void load(QString maj, QString min, QString pat);
```
