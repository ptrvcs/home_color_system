#pragma once
#include <functional>
#include <QDebug>

class DmxController {
public:
    using ValueChangedCallback = std::function<void(int)>;

    void setChannelValue(int value) {
        if (value != m_channelValue) {
            m_channelValue = value;
            qDebug() << "[DMX] Channel value set to:" << m_channelValue;
            if (onValueChanged)
                onValueChanged(m_channelValue);
        }
    }

    int channelValue() const { return m_channelValue; }

    // callback to notify listeners (ViewModel)
    ValueChangedCallback onValueChanged = nullptr;

private:
    int m_channelValue = 0;
};
