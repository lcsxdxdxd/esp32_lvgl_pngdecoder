/*
 * @Descripttion: 文件描述
 * @version: 文件版本
 * @Author: jinsc
 * @Date: 2022-09-04 19:24:25
 * @LastEditors: jinsc
 * @LastEditTime: 2022-09-05 21:15:53
 * @FilePath: \lvgl\main\lvgl_main.c
 */
/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_fs_if.h"
#include "lv_demos.h"

/*freertos任务函数*/
void lvgl_handler_func(void *pvParameters)
{
    while (1)
    {
        /* code */

        lv_task_handler();

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

/*用定时器给LVGL提供时钟*/
static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(10);
}
void app_main(void)
{
    printf("Hello world!\n");
    lv_init();
    lv_port_disp_init();
    lv_fs_if_init();
    /*  esp_register_freertos_tick_hook(lv_tick_task);
    Create and start a periodic timer interrupt to call lv_tick_inc
    */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 10 * 1000));

    // metux = xSemaphoreCreateMutex();
    // xTaskCreatePinnedToCore(lvgl_handler_func,
    //                         "lvgl_handler",
    //                         4096,
    //                         NULL,
    //                         2,
    //                         lvgl_handler,
    //                         1);

    // xTaskCreatePinnedToCore(t1,
    //                         "t1",
    //                         4096,
    //                         NULL,
    //                         5,
    //                         t11,
    //                         1);
}
