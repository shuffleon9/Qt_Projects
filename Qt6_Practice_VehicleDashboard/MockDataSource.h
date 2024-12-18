#ifndef MOCKDATASOURCE_H
#define MOCKDATASOURCE_H

#include <QObject>
#include <QTimer>

class MockDataSource : public QObject {
    Q_OBJECT
    Q_PROPERTY(int speed READ speed NOTIFY dataUpdated)
    Q_PROPERTY(int rpm READ rpm NOTIFY dataUpdated)
    Q_PROPERTY(int fuel READ fuel NOTIFY dataUpdated)
    Q_PROPERTY(QString track READ track NOTIFY dataUpdated)
    Q_PROPERTY(QString artist READ artist NOTIFY dataUpdated)
    Q_PROPERTY(QString albumArt READ albumArt NOTIFY dataUpdated)
    Q_PROPERTY(double temperature READ temperature NOTIFY dataUpdated)
    Q_PROPERTY(bool acOn READ acOn WRITE setAcOn NOTIFY dataUpdated)

public:
    explicit MockDataSource(QObject* parent = nullptr);

    int speed() const { return m_speed; }
    int rpm() const { return m_rpm; }
    int fuel() const { return m_fuel; }
    QString track() const { return m_track; }
    QString artist() const { return m_artist; }
    QString albumArt() const { return m_albumArt; }
    double temperature() const { return m_temperature; }
    bool acOn() const { return m_acOn; }

    void setAcOn(bool acOn) {
        if (m_acOn != acOn) {
            m_acOn = acOn;
            emit dataUpdated();
        }
    }

signals:
    void dataUpdated();

private slots:
    void updateData();

private:
    QTimer m_timer;
    int m_speed = 0;
    int m_rpm = 0;
    int m_fuel = 100;
    QString m_track = "Unknown Track";
    QString m_artist = "Unknown Artist";
    QString m_albumArt = "qrc:/images/albumArt.jpg";
    double m_temperature = 22.0;
    bool m_acOn = false;
};

#endif // MOCKDATASOURCE_H
