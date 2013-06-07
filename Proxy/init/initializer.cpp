#include "initializer.h"

#include "messagehelper.h"
#include "applicationdatastorage.h"

#include "proxyinitializer.h"
#include "moduleinitializer.h"
#include "jobinitializer.h"
#include "settingsinitializer.h"
#include "applicationenvironment.h"
#include "settings.h"

#include <QCoreApplication>

Initializer::Initializer(QObject *parent)
    : QObject(parent)
{
}

void Initializer::init()
{
    QCoreApplication::setOrganizationName("Matus Tomlein");
    QCoreApplication::setApplicationName("Mr Fusion");

    ApplicationEnvironment().init();

    (new SettingsInitializer(this))->init();
    (new ProxyInitializer(this))->init();
    (new ModuleInitializer(this))->init();
    (new JobInitializer(this))->init();

    MessageHelper::debug("READY");
}
