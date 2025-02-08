#include "PlayerController.h"

PlayerController::PlayerController(QObject *parent)
    : QObject{parent}
{}

int PlayerController::currentSongIndex() const
{
    return m_currentSongIndex;
}

int PlayerController::songCount() const
{
    return m_songCount;
}

bool PlayerController::playing() const
{
    return m_playing;
}

void PlayerController::playPause()
{
    m_playing = !m_playing;

    emit playingChanged();
}

void PlayerController::switchToPreviousSong()
{
    if (m_currentSongIndex > 0) {
        m_currentSongIndex--;
    } else {
        m_currentSongIndex = m_songCount - 1;
    }

    emit currentSongIndexChanged();
}

void PlayerController::switchToNextSong()
{
    if (m_currentSongIndex + 1 >= m_songCount) {
        m_currentSongIndex = 0;
    } else {
        m_currentSongIndex++;
    }

    emit currentSongIndexChanged();
}
