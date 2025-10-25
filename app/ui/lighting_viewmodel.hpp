#pragma once
#include <QObject>
#include "dmx_controller.hpp"

class LightingViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(int intensity READ intensity WRITE setIntensity NOTIFY intensityChanged)

public:
    explicit LightingViewModel(DmxController *dmx, QObject *parent = nullptr)
        : QObject(parent), m_dmx(dmx) {
        // Connect C++ callback to Qt signal
        m_dmx->onValueChanged = [this](int value) {
            if (m_intensity != value) {
                m_intensity = value;
                emit intensityChanged(m_intensity);
            }
        };
    }

    int intensity() const { return m_intensity; }

public slots:
    void setIntensity(int value) {
        if (m_intensity == value) return;
        m_intensity = value;
        emit intensityChanged(m_intensity);
        m_dmx->setChannelValue(value);
    }

signals:
    void intensityChanged(int value);

private:
    DmxController *m_dmx;
    int m_intensity = 0;
};
