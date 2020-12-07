#include <QDBusConnection>

#include "mediaplayer.h"

static const QString s_serviceName = QStringLiteral("org.mpris.MediaPlayer2.spotify");
static const QString s_object = QStringLiteral("/org/mpris/MediaPlayer2");

MediaPlayer::MediaPlayer()
{
    m_mediaplayer2.reset(
        new OrgMprisMediaPlayer2PlayerInterface(s_serviceName,
                                                s_object,
                                                QDBusConnection::sessionBus(),
                                                this)
        );

    m_properties.reset(
        new OrgFreedesktopDBusPropertiesInterface(s_serviceName,
                                                  s_object,
                                                  QDBusConnection::sessionBus(),
                                                  this)
        );

    connect(m_properties.get(),
            &OrgFreedesktopDBusPropertiesInterface::PropertiesChanged,
            this,
            &MediaPlayer::propertiesChanged);
}

void MediaPlayer::propertiesChanged()
{
    QVariantMap map = m_mediaplayer2->property("Metadata").toMap();
    QVariant artistList = map[QStringLiteral("xesam:artist")];
    QVariantList list = artistList.toList();

    if (list.length() == 1) {
        m_artist = list.at(0).toString();
    } else {
        m_artist.clear();
    }

    QVariant song = map[QStringLiteral("xesam:title")];
    m_song = song.toString();
    emit metaDataChanged();
}


void MediaPlayer::playPause()
{
    m_mediaplayer2->PlayPause();
}

void MediaPlayer::stop()
{
    m_mediaplayer2->Stop();
}

void MediaPlayer::previous()
{
    m_mediaplayer2->Previous();
}

void MediaPlayer::next()
{
    m_mediaplayer2->Next();
}
