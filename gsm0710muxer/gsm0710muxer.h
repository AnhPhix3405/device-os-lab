/**
 * @file gsm0710muxer.h
 * @brief Header file for GSM0710 muxer.
 *
 * This file contains the declarations for GSM0710 muxer functionality.
 */

#pragma once

class GSM0710Muxer {
public:
    GSM0710Muxer() : buffer(nullptr), bufferSize(1024) {}
    ~GSM0710Muxer();

    void initialize();
    void cleanup();

private:
    char* buffer;
    size_t bufferSize;
};