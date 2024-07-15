#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QSettings>
#include <QFile>

class AppConfig {
public:

    AppConfig() {
        if(QFile::exists("setting.ini")) {
            // open file
            settings = new QSettings("setting.ini", QSettings::IniFormat);
            //read into buffer
            loadSettings();
        }else {
            // create file
            // write buffer into file
        }
    }
    virtual ~AppConfig();
    // 不对返回值做审查
    const QVariant ReadValue(const QString &section, const QString &key) const ;

    int Write(const QString &section, const QString &key, const int &value);
    int Write(const QString &section, const QString &key, const double &value);
    int Write(const QString &section, const QString &key, const QString &value);


private:
    int loadSettings();

private:
    QSettings *settings;
    // 初始化buffer的内容
    QMap<QString, QMap<QString, QVariant>> buffer {
        {"sectionA", {{"keyA", "valueA"}, {"keyB", "valueB"}}},
        {"sectionB", {{"keyBA", "valueBA"}, {"keyBB", "valueBB"}}}
    };

};


#endif // APPCONFIG_H
