#include "Camera.h"
#include <pico/stdlib.h>

#include <hardware/spi.h>
#include <hardware/i2c.h>

#define PIN_CS 17

Camera::Camera() {
    // SPI and GPIO initialization specific to your setup
    spi_init(spi0, 4000 * 1000); // Initialize SPI0 at 4MHz. Adjust as necessary.
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);

    // Initialize the ArduCAM
    arducam = ArduCAM(OV2640, PIN_CS);

    // Initialize SPI
    spi_init(SPI_PORT, 8 * 1000 * 1000); // Initialize SPI at 8MHz
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    // Initialize CS pin
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1); // Deselect the CS pin

    // Initialize I2C for sensor configuration
    i2c_init(I2C_PORT, 100 * 1000); // Initialize I2C at 100kHz
    gpio_set_function(PIN_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_SDA);
    gpio_pull_up(PIN_SCL);

    // Initialize the camera
    arducam.InitCAM();
    arducam.set_format(JPEG);
    arducam.InitCAM();

    // Set the JPEG resolution
    arducam.OV2640_set_JPEG_size(OV2640_320x240);
    
    sleep_ms(1000); // Wait for the camera to initialize
}

void Camera::give_color() {
    // Start capture
    arducam.flush_fifo();
    arducam.clear_fifo_flag();
    arducam.start_capture();
    printf("Capturing image...\n");

    // Wait for capture to complete
    while(!arducam.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));
    printf("Capture done.\n");

    // Read the length of the FIFO
    uint32_t length = arducam.read_fifo_length();
    printf("FIFO Length: %d\n", length);

    if (length >= MAX_FIFO_SIZE) {
        printf("Error: FIFO overflow\n");
        return;
    }

    // Read data from FIFO
    // This is where you would read the image data from the FIFO
    // and process/store it according to your application needs
    // For example:
    uint8_t buffer[256]; // Adjust based on your needs
    for (uint32_t i = 0; i < length; i += sizeof(buffer)) {
        uint32_t toRead = length - i;
        if (toRead > sizeof(buffer)) toRead = sizeof(buffer);
        arducam.CS_LOW();
        arducam.set_fifo_burst(); // Set camera to burst read mode
        spi_read_blocking(SPI_PORT, 0, buffer, toRead); // Adjust as necessary
        arducam.CS_HIGH();
        // Process/store buffer here
    }
    printf("Image read complete.\n");
}
