#include "PlayerController.h"
#include <AudioInfo.h>

#include <QMediaDevices>
#include <QAudioDevice>
#include <QAudioOutput>

PlayerController::PlayerController(QObject *parent)
    : QAbstractListModel{parent}
{
    const auto &audioOutputs = QMediaDevices::audioOutputs();
    if (!audioOutputs.isEmpty()) {
        m_mediaPlayer.setAudioOutput(new QAudioOutput(&m_mediaPlayer));
    }

    // Temp
    addAudio("Anothers Arms Ringtone", "Coldplay",
             QUrl("D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/audio/AnothersArmsRingtone.m4a"),
             QUrl("assets/images/song_1.jpg"));

    addAudio("AuRevoir Ringtone", "OneRepublic",
             QUrl("D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/audio/AuRevoirRingtone.m4a"),
             QUrl("assets/images/song_2.jpg"));

    addAudio("Burning Bridges Ringtone", "OneRepublic",
             QUrl("D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/audio/BurningBridgesRingtone.m4a"),
             QUrl("assets/images/song_3.jpg"),
             QUrl("D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/videos/video_1.avi"));
}

bool PlayerController::playing() const
{
    return m_playing;
}

void PlayerController::playPause()
{
    m_playing = !m_playing;

    emit playingChanged();

    if (m_playing)
        m_mediaPlayer.play();
    else
        m_mediaPlayer.pause();
}

int PlayerController::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_audioList.length();
}

QVariant PlayerController::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >=0 && index.row() < m_audioList.length()) {
        AudioInfo* audioInfo = m_audioList[index.row()];

        switch ((Role) role) {
        case AudioTitleRole:
            return audioInfo->title();
        case AudioAuthorNameRole:
            return audioInfo->authorName();
        case AudioSourceRole:
            return audioInfo->audioSource();
        case AudioImageSourceRole:
            return audioInfo->imageSource();
        case AudioVideoSourceRole:
            return audioInfo->videoSource();
        }
    }

    return {};
}

QHash<int, QByteArray> PlayerController::roleNames() const
{
    QHash<int, QByteArray> result;
    result[AudioTitleRole] = "audioTitle";
    result[AudioAuthorNameRole] = "audioAuthorName";
    result[AudioSourceRole] = "audioSource";
    result[AudioImageSourceRole] = "audioImageSource";
    result[AudioVideoSourceRole] = "audioVideoSource";
    return result;
}

void PlayerController::switchToPreviousSong()
{
    const int index = m_audioList.indexOf(m_currentSong);

    if (index > 0) {
        setCurrentSong(m_audioList[index-1]);
    } else {
        setCurrentSong(m_audioList.last());
    }
}

void PlayerController::switchToNextSong()
{
    const int index = m_audioList.indexOf(m_currentSong);

    if (index + 1 >= m_audioList.length()) {
        setCurrentSong(m_audioList.first());
    } else {
        setCurrentSong(m_audioList[index+1]);
    }
}

void PlayerController::changeAudioSource(const QUrl &source)
{
    m_mediaPlayer.stop();
    m_mediaPlayer.setSource(source);

    if (m_playing)
        m_mediaPlayer.play();
}

void PlayerController::addAudio(const QString &title, const QString &authorName, const QUrl &audioSource, const QUrl &imageSource, const QUrl &videoSource)
{
    beginInsertRows(QModelIndex(), m_audioList.length(), m_audioList.length()); // append to list

    AudioInfo *audioInfo = new AudioInfo(this);
    audioInfo->setTitle(title);
    audioInfo->setAuthorName(authorName);
    audioInfo->setAudioSource(audioSource);
    audioInfo->setImageSource(imageSource);
    audioInfo->setVideoSource(videoSource);

    if (m_audioList.isEmpty()) {
        setCurrentSong(audioInfo);
    }

    m_audioList << audioInfo;

    endInsertRows(); // to emit signal
}

void PlayerController::removeAudio(int index)
{
    if (index >= 0 && index < m_audioList.length()) {
        beginRemoveRows(QModelIndex(), index, index);

        AudioInfo* toRemove = m_audioList[index];

        if (toRemove == m_currentSong) {
            if (m_audioList.length() > 1) {
                if (index > 0) {
                    setCurrentSong(m_audioList[index-1]);
                } else {
                    setCurrentSong(m_audioList.last());
                }
            } else {
                setCurrentSong(nullptr);
            }
        }

        m_audioList.removeAt(index);
        toRemove->deleteLater();

        endRemoveRows();
    }
}

void PlayerController::switchToAudioByIndex(int index)
{
    if (index >= 0 && index < m_audioList.length()) {
        setCurrentSong(m_audioList[index]);
    }
}

AudioInfo *PlayerController::currentSong() const
{
    return m_currentSong;
}

void PlayerController::setCurrentSong(AudioInfo *newCurrentSong)
{
    if (m_currentSong == newCurrentSong)
        return;
    m_currentSong = newCurrentSong;
    emit currentSongChanged();

    if (m_currentSong) {
        changeAudioSource(m_currentSong->audioSource());
    } else {
        m_mediaPlayer.stop();
        m_mediaPlayer.setSource(QUrl());
        m_playing = false;

        emit playingChanged();
    }
}
