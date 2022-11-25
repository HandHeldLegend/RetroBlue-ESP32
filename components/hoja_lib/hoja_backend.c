#include "hoja_backend.h"

GamepadButtonData g_button_data = {};
GamepadStickData g_stick_data = {};
hoja_params_s hoja_params = {0};

// Resets all button data set
void hoja_button_reset()
{
    g_button_data.b_right  = 0;
    g_button_data.b_down   = 0;
    g_button_data.b_up     = 0;
    g_button_data.b_left   = 0;

    g_button_data.b_home     = 0;
    g_button_data.b_start     = 0;
    g_button_data.t_r        = 0;
    g_button_data.t_zr        = 0;

    g_button_data.d_left         = 0;
    g_button_data.d_right        = 0;
    g_button_data.b_select    = 0;
    g_button_data.b_capture      = 0;

    g_button_data.t_l    = 0;
    g_button_data.t_zl    = 0;
    g_button_data.d_up       = 0;
    g_button_data.d_down     = 0;
}

void hoja_button_task(void * parameters)
{
    const char* TAG = "hoja_button_task";
    vTaskDelay(2000/portTICK_PERIOD_MS);
    ESP_LOGI(TAG, "Starting task...");
    // Buttons update at a 2000hz rate.
    for(;;)
    {
        hoja_button_cb();
        vTaskDelay(0.5/portTICK_PERIOD_MS);
    }
}
