//main function
#include "image.h"

#include <stdio.h>

int main() {
    // Allocate memory for struct
    Bitmap original_image;

    // Load in data from image into struct
    if (load_img("./original.bmp", &original_image) == LOAD_ERROR) {
        printf("Unable to load image. Exiting...");
        return 1;
    }

    // Process the image
    remove_color_channel(GREEN_CHANNEL, &original_image);

    // Save the newly processed data to a file
    if (save_img("green_mask.bmp", &original_image) == SAVE_ERROR) {
        printf("Unable to save image. Exiting...");
        return 1;
    }

    // Revert the image back to the original
    reset_pixel_data(&original_image);


    // TODO: Repeat the process but remove the blue color from the image. Save
    // the file as "blue_mask.bmp".

    // Process the image
    remove_color_channel(BLUE_CHANNEL, &original_image);

    // Save the newly processed data to a file
    if (save_img("blue_mask.bmp", &original_image) == SAVE_ERROR) {
        printf("Unable to save image. Exiting...");
        return 1;
    }

    reset_pixel_data(&original_image);


    // TODO: Repeat the process but remove the red color from the image. Save
    // the file as "red_mask.bmp".

    // Process the image
    remove_color_channel(RED_CHANNEL, &original_image);

    // Save the newly processed data to a file
    if (save_img("red_mask.bmp", &original_image) == SAVE_ERROR) {
        printf("Unable to save image. Exiting...");
        return 1;
    }

    reset_pixel_data(&original_image);


    // TODO: Run grayscale function on bitmap image and save file as "grayscale.bmp".

    grayscale(&original_image);

    if (save_img("grayscale.bmp", &original_image) == SAVE_ERROR) {
        printf("Unable to save image. Exiting...");
        return 1;
    }

    reset_pixel_data(&original_image);
    

    // TODO: Run "or filter" function on bitmap image and save file as "or_filter.bmp".

    or_filter(&original_image);

    if (save_img("or_filter.bmp", &original_image) == SAVE_ERROR) {
        printf("Unable to save image. Exiting...");
        return 1;
    }

    reset_pixel_data(&original_image);



    return 0;
}


//image.c color manipulation functions
