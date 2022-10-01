# QSelect_Version
semantic version selection widget. version strings are digit-only, and limited to nine characters.
## construction
all parameters are optional.
```
  QWidget* parent = new QWidget; //defaults to nullptr
  QString delimiter = ","; //defaults to "."
  QString prefix = "ver."; //defaults to "v"
  QSelect_Version versionSelect(parent, first_year, last_year);
  versionSelect.show();
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
a QString overload is provided
```
  void load(int maj, int min, int pat);
  void load(QString maj, QString min, QString pat);
```
