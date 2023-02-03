// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

// Libraries manually included
#include <fstream>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

// Test is an fstream, "dog.ppm" will be initialized correctly
TEST(test_print_dog){
  Image *img = new Image;
  
  ifstream is("dog.ppm");
  Image_init(img, is);


  ostringstream os;
  Image_print(img, os);

  ostringstream correct;
  correct << "P3\n5 5\n255\n"
          << "0 0 0 0 0 0 255 255 250 0 0 0 0 0 0 \n"
          << "255 255 250 126 66 0 126 66 0 126 66 0 255 255 250 \n"
          << "126 66 0 0 0 0 255 219 183 0 0 0 126 66 0 \n"
          << "255 219 183 255 219 183 0 0 0 255 219 183 255 219 183 \n"
          << "255 219 183 0 0 0 134 0 0 0 0 0 255 219 183 \n";

  ASSERT_EQUAL(os.str(), correct.str());

  delete img;
}

// Tests if a manually inputed sstream will be initialized correctly
TEST(test_print_manual){
  Image *img = new Image;

  std::string input = "P3 3 3 255 0 0 0 255 255 255 0 0 0 255 255 255 0 0 0 255 255 255 0 0 0 255 255 255 0 0 0";

  std::istringstream is(input);
  Image_init(img, is);
  
  ostringstream os;
  Image_print(img, os);

  ostringstream correct;
  correct << "P3\n3 3\n255\n"
          << "0 0 0 255 255 255 0 0 0 \n"
          << "255 255 255 0 0 0 255 255 255 \n"
          << "0 0 0 255 255 255 0 0 0 \n";

  ASSERT_EQUAL(os.str(), correct.str());

  delete img;
}

// Tests if the width and the height return the correct values
TEST(test_width_height_same){
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);
  int width = Image_width(img);
  int height = Image_height(img);

  ASSERT_EQUAL(width, 2);
  ASSERT_EQUAL(height, 2);

  delete img;
}

TEST(test_width_height_different){
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};

  Image_init(img, 1, 2);
  Image_fill(img, red);
  int width = Image_width(img);
  int height = Image_height(img);

  ASSERT_EQUAL(width, 1);
  ASSERT_EQUAL(height, 2);

  delete img;
}

// Tests if the get_pixel function returns the correct pixel color
TEST(test_get_pixel_red){
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  Pixel test = Image_get_pixel(img, 0,0);

  ASSERT_EQUAL(test.r, 255);
  ASSERT_EQUAL(test.g, 0);
  ASSERT_EQUAL(test.b, 0);

  delete img;
}

TEST(test_get_pixel_green){
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  Pixel test = Image_get_pixel(img, 0,1);

  ASSERT_EQUAL(test.r, 0);
  ASSERT_EQUAL(test.g, 255);
  ASSERT_EQUAL(test.b, 0);

  delete img;
}

TEST(test_get_pixel_blue){
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  Pixel test = Image_get_pixel(img, 1,0);

  ASSERT_EQUAL(test.r, 0);
  ASSERT_EQUAL(test.g, 0);
  ASSERT_EQUAL(test.b, 255);

  delete img;
}

// Tests if the fill function will accurately fill the entire image with the correct color

TEST(test_print_Image_fill_red){
  Image *img = new Image;

  Pixel red = {255,0,0};

  Image_init(img, 4,4 );
  Image_fill(img, red);

  ostringstream os;
  Image_print(img, os);

  // Correct output
  ostringstream correct;
  correct << "P3\n4 4\n255\n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 \n";
  correct << "255 0 0 255 0 0 255 0 0 255 0 0 \n";

  ASSERT_EQUAL(os.str(), correct.str());

  delete img;
}

TEST(test_print_Image_fill_green){
  Image *img = new Image;

  Pixel green = {0,255,0};

  Image_init(img, 4,4 );
  Image_fill(img, green);

  ostringstream os;
  Image_print(img, os);

  // Correct output
  ostringstream correct;
  correct << "P3\n4 4\n255\n";
  correct << "0 255 0 0 255 0 0 255 0 0 255 0 \n";
  correct << "0 255 0 0 255 0 0 255 0 0 255 0 \n";
  correct << "0 255 0 0 255 0 0 255 0 0 255 0 \n";
  correct << "0 255 0 0 255 0 0 255 0 0 255 0 \n";

  ASSERT_EQUAL(os.str(), correct.str());

  delete img;
}

TEST(test_print_Image_fill_blue){
  Image *img = new Image;

  Pixel blue = {0,0,255};

  Image_init(img, 4,4 );
  Image_fill(img, blue);

  ostringstream os;
  Image_print(img, os);

  // Correct output
  ostringstream correct;
  correct << "P3\n4 4\n255\n";
  correct << "0 0 255 0 0 255 0 0 255 0 0 255 \n";
  correct << "0 0 255 0 0 255 0 0 255 0 0 255 \n";
  correct << "0 0 255 0 0 255 0 0 255 0 0 255 \n";
  correct << "0 0 255 0 0 255 0 0 255 0 0 255 \n";
  ASSERT_EQUAL(os.str(), correct.str());

  delete img;
}

TEST(test_print_Image_fill_random){
  Image *img = new Image;

  Pixel random = {93,155,155};

  Image_init(img, 4,4 );
  Image_fill(img, random);

  ostringstream os;
  Image_print(img, os);

  // Correct output
  ostringstream correct;
  correct << "P3\n4 4\n255\n";
  correct << "93 155 155 93 155 155 93 155 155 93 155 155 \n";
  correct << "93 155 155 93 155 155 93 155 155 93 155 155 \n";
  correct << "93 155 155 93 155 155 93 155 155 93 155 155 \n";
  correct << "93 155 155 93 155 155 93 155 155 93 155 155 \n";

  ASSERT_EQUAL(os.str(), correct.str());

  delete img;
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here