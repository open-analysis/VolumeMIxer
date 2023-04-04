#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../audio/AudioControl.h"
#include "../audio/DeviceControl.h"
#include "../utils/utils.h"

class Parser
{
private:
	std::vector<std::string> m_queue;
	AudioControl* m_audioCntl;
	DeviceControl* m_devCntl;

public:
	Parser();
	Parser(AudioControl* i_audioCntl, DeviceControl* i_devCntl);

	void parseQueue(const std::string i_direction, const std::string i_type);

	void setQueue(char* i_buffer);
	void flushQueue() { m_queue.clear(); }

	void setAudioCntl(AudioControl* i_audioCntl)
	{
		m_audioCntl = i_audioCntl;
	}

	void setDeviceCntl(DeviceControl* i_devCntl)
	{
		m_devCntl = i_devCntl;
	}

private:
	void removeCharsFromString(std::string& str, char* charsToRemove);
};