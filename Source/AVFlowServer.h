/*
  ==============================================================================

    AVFlowServer.h
    Created: 1 Dec 2024 2:53:30pm
    Author:  Lukas Timmerman

  ==============================================================================
*/

#pragma once

#include <iostream>
#include <JuceHeader.h>

class AVFlowServer {
    public:
        AVFlowServer() {
            if (! sender.connect ("127.0.0.1", 9001))
                std::cout << "Error: could not connect OSC sender." << std::endl;
        }
    
        bool send(std::string url, float value) { return sender.send(url.c_str(), value); }
    private:
        juce::OSCSender sender;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AVFlowServer);
};
