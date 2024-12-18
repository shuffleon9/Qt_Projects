#include "MockDataSource.h"
#include <QtGlobal>
#include <QDateTime>

MockDataSource::MockDataSource(QObject* parent) : QObject(parent) {
    connect(&m_timer, &QTimer::timeout, this, &MockDataSource::updateData);
    m_timer.start(200); // Update every 200 ms
}

void MockDataSource::updateData() {
    m_speed = (m_speed + rand() % 5) % 240; // 0-240 km/h
    m_rpm = (m_rpm + rand() % 150) % 7000; // 0-7000 RPM
    m_fuel = qMax(0, m_fuel - 1);
    m_temperature = 20 + (rand() % 2); // Random temp 20-30°C
    m_track = QString("Track %1").arg(QDateTime::currentMSecsSinceEpoch() % 10);
    m_artist = QString("Artist %1").arg(QDateTime::currentMSecsSinceEpoch() % 5);
    emit dataUpdated();
}
