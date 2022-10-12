#ifndef HOJA_FRONTEND_H
#define HOJA_FRONTEND_H

#include "hoja_includes.h"

/* CORE TYPES */
#define CORE_CONFIGMODE     0 // To be defined mode for changing settings.
#define CORE_NINTENDOSWITCH 1
#define CORE_SNES           2
#define CORE_GAMECUBE       3
#define CORE_N64            4
#define CORE_USBHID         5
#define CORE_BLUETOOTHHID   6

// This struct type is used to
// set up HOJA API before runtime.
// This should be passed through with hoja_api_init()
// Different settings are implemented here which are
// not meant to change during runtime and should
// be set before compilation
typedef struct
{

} hoja_setup_s;

// Pin needs to be defined to set the GPIO pin for SNES/NES function.
uint8_t HOJA_PIN_LATCH;
// Pin needs to be defined to set the GPIO pin for SNES/NES function.
uint8_t HOJA_PIN_CLOCK;
// Pin needs to be defined to set the GPIO pin for SNES/NES/GameCube function.
uint8_t HOJA_PIN_SERIAL;

uint8_t HOJA_PIN_I2C_SDA;

uint8_t HOJA_PIN_I2C_SCL;

SemaphoreHandle_t xSemaphore;

/* Functions relating to the API itself */

// Initialize the API.
// This loads any settings saved and initializes flash storage.
hoja_err_t hoja_api_init();

// Set the controller core
hoja_err_t hoja_api_setcore(uint8_t core_type);

// Starts the controller. You MUST set the core before running this.
hoja_err_t hoja_api_startcore(void);

// Stops the controller. 
hoja_err_t hoja_api_stopcore(void);

// Controller configuration options.
// Set the controller color
hoja_err_t rb_api_setColor(uint8_t red, uint8_t green, uint8_t blue);

// Sets the analog stick values for calibration purposes
hoja_err_t rb_api_setStickCalibration(uint16_t sx_min, uint16_t sx_center, uint16_t sx_max,
                                    uint16_t sy_min, uint16_t sy_center, uint16_t sy_max);

// Resets the current pairing for the current core
hoja_err_t rb_api_resetPairing();

// Core-specific options.

// NINTENDO SWITCH
// ----------------
// Set the Nintendo Switch controller type
hoja_err_t rb_api_setNSControllerType(uint8_t ns_controller_type);

// ----------------

// NES/SNES
// ----------------
// Enable analog stick as D-Pad input
hoja_err_t rb_api_setSNESStickPad(uint8_t enable);

// ----------------

// Vars for callbacks
typedef void (*hoja_callback_t) (void);
hoja_callback_t hoja_button_cb;
hoja_callback_t hoja_stick_cb;
hoja_callback_t hoja_rgb_cb;


// Function to register callback function for setting buttons
// This is called by the core at an appropriate rate to help
// avoid weird timing issues.
hoja_err_t hoja_api_regbuttoncallback(hoja_callback_t func);
// Function to register callback function for setting sticks
hoja_err_t hoja_api_regstickcallback(hoja_callback_t func);

// Register callback for rgb updates
hoja_err_t hoja_api_regrgbcallback(hoja_callback_t func);

#endif