#pragma once

typedef struct{
    uint8_t cx;
    uint8_t cy;
}person_struct;

typedef struct{
    uint8_t frame_header[3];
    uint8_t size_0;
    uint8_t size_1;
    uint8_t command;
    person_struct person[2];
    uint8_t check_sum;
    uint8_t frame_end[3];
}data_packet_struct;

typedef struct{
    uint8_t frame_header[3];
    uint8_t size_0;
    uint8_t size_1;
    uint8_t command;
    uint8_t command_val;
    uint8_t reserved_0;
    uint8_t reserved_1;
} frame_start_struct;

typedef struct {
    uint8_t type;
} reporting;

typedef struct {
    int16_t X0;
    int16_t Y0;
    int16_t X1;
    int16_t Y1;
} region;

typedef struct {
    uint8_t type;
    uint8_t reserved;
    region coordinates[3];
} regions;

typedef struct{
    uint8_t buffer[256];
    uint8_t size;
    uint8_t frame_start;
}serial_buffer_struct;

typedef struct {
    double x;
    double y;
} coordinates;
