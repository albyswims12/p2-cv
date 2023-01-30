// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"
using namespace std;

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
  
  // Checks if the img points to an Image 
  // and if the width and height meet requirements
  assert(img != nullptr);
  assert(0 < width && width <= MAX_MATRIX_WIDTH);
  assert(0 < height && height <= MAX_MATRIX_HEIGHT);

  // Initializes the Image with the given width and height:
  img->height = height;
  img->width = width;

  Matrix_init(&img->red_channel, width, height);
  Matrix_init(&img->green_channel, width, height);
  Matrix_init(&img->blue_channel, width, height);

  
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
  
  // Checks if the img points to an Image
  assert(img != nullptr); 

  // Reads in the information from the PPM file
  
  // Initializes the variables used
  std::string P3;
  int max_color;
  
  int red;
  int green;
  int blue;

  // Reads in the first three variables from the file
  is >> P3;
  is >> img->width;
  is >> img->height;
  is >> max_color;
  
  Matrix_init(&img->red_channel, img->width, img->height);
  Matrix_init(&img->green_channel, img->width,img->height);
  Matrix_init(&img->blue_channel, img->width, img->height);

  // Reads in the rest of the values and stores them in the image vector for later use

  for (int i = 0; i < img->height; ++i) {
    for (int j = 0; j < img->width; ++j){
      is >> red >> green >> blue;
      *Matrix_at(&img->red_channel, i, j) = red;
      *Matrix_at(&img->green_channel, i, j) = green;
      *Matrix_at(&img->blue_channel, i, j) = blue;
    }
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  
  // Checks if img points to a valid image
  assert(img != nullptr); 
  
  // Prints the basic first three values 
  // of the image to the output stream in the PPM format
  os << "P3" << "\n";
  os << img->width << " " << img->height << "\n";
  os << "255" << "\n";
  // Prints the rows of the image
  for (int i = 0; i < img->height; ++i) {
    for (int j = 0; j < img->width; ++j) {
      os << *Matrix_at(&img->red_channel, i, j) << " "
         << *Matrix_at(&img->green_channel, i, j) << " " 
         << *Matrix_at(&img->blue_channel, i, j) << " ";
    }
    os << "\n";
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  
  // Checks if img points to a valid image
  assert(img != nullptr); // TODO Replace with your implementation!

  // Returns the width of the Image
  return img->width;

}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  
  // Checks if the img points to a valid image
  assert(img != nullptr); // TODO Replace with your implementation!

  // Returns the width of the Image
  return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  
  // Checks if the img points to a valid image 
  // as well as checks if the dimensions fit within the image
  assert(img != nullptr); 
  assert(0 <= row && row < Image_height(img));
  assert(0 <= column && column < Image_width(img));

  // Creates a new Pixel
  Pixel pixel;

  // Sets pixel colors to rgb channels
  pixel.r = *Matrix_at(&img->red_channel, row, column);
  pixel.g = *Matrix_at(&img->green_channel, row, column);
  pixel.b = *Matrix_at(&img->blue_channel, row, column);

  // Returns the color in the Image at the given row and column
  return pixel;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  
  // Checks if the img points to a valid image as well as the 
  assert(img != nullptr); 
  assert(0 <= row && row < Image_height(img));
  assert(0 <= column && column < Image_width(img));

  // i = 4, j = 0, pixel = ...

  // Sets the pixel in the Image at the given row and column
  *Matrix_at(&img->red_channel, row, column)= color.r;
  *Matrix_at(&img->green_channel, row, column)= color.g;
  *Matrix_at(&img->blue_channel, row, column)= color.b;
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  
  // Checks if the img points to a valid image
  assert(img != nullptr); // TODO Replace with your implementation!

  // Sets every pixel in the image to the color value
  Matrix_fill(&img->red_channel, color.r);
  Matrix_fill(&img->green_channel, color.g);
  Matrix_fill(&img->blue_channel, color.b);
  
}
