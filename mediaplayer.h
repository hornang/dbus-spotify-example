#pragma once

#include <memory>

#include <QObject>
#include <QVariantMap>
#include <QTimer>

#include "mediaplayer2_interface.h"

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString artist MEMBER m_artist NOTIFY metaDataChanged)
    Q_PROPERTY(QString song MEMBER m_song NOTIFY metaDataChanged)

public:
    MediaPlayer();

private:
    std::unique_ptr<OrgMprisMediaPlayer2PlayerInterface> m_mediaplayer2;
    std::unique_ptr<OrgFreedesktopDBusPropertiesInterface> m_properties;

    QString m_artist;
    QString m_song;

public slots:
    void playPause();
    void stop();
    void previous();
    void next();
    void propertiesChanged();

signals:
    void metaDataChanged();
};
