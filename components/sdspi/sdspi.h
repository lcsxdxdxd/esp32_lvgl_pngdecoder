#ifndef SD_SPI_H
#define SD_SPI_H
 
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"


#define MOUNT_POINT "/sdcard"
 
// Pin mapping
#define PIN_NUM_MISO 15
#define PIN_NUM_MOSI 14
#define PIN_NUM_CLK  18
#define PIN_NUM_CS   19
#define PIN_NUM_CD   17
 
esp_err_t sdCard_Init();
 
#endif