// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"


// Libraries manually included
using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----

// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 5;
  const int height = 3;
  const int value = 2;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }
  delete mat;
}
TEST(test_height_width_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Setting the basic variables
  const int width = 5;
  const int height = 3;
  const int value = 2;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  
  // Testing for height and width output
  ASSERT_EQUAL(Matrix_height(mat), height);
  ASSERT_EQUAL(Matrix_width(mat), width);

  delete mat;
}

TEST(test_row_column_ptr_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Setting the basic variables
  const int width = 5;
  const int height = 3;
  const int value = 2;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  // Testing for correct row and column output
  const int *ptr = Matrix_at(mat, 2, 4);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 4);

  delete mat;
}

TEST(test_max_basic){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Setting the basic variables
  const int width = 5;
  const int height = 3;
  const int value = -1;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  // Checks if the right maximum output is given
  ASSERT_EQUAL(Matrix_max(mat), -1);

  delete mat;
} 
  // SITLL LEFT TO IMPLEMENT ---- CHANGE VALUES AND ADD NEGATIVE NUMBERS HERE

TEST(test_fill_border_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Setting the basic variables
  const int width = 5;
  const int height = 3;
  const int value = -1;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
 
  // Checks if the border is filled as well as the column/value of the minimum value in a row
  Matrix_fill_border(mat, 1);
  ASSERT_EQUAL(Matrix_max(mat), 1);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 2), 1);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 1, 2), -1);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 1, 2), 1);

  delete mat; 
}

// 
TEST(test_fill_HUGE) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Sets the maxmium dimensions in the test
  const int width = 500;
  const int height = 500;
  const int value = 69;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  // Checks if the fill function is working
  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat;
}

TEST(test_height_width_HUGE){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Sets the maxmium dimensions in the test
  const int width = 500;
  const int height = 500;
  const int value = 69;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  // Checks if the height and width are the correct output
  ASSERT_EQUAL(Matrix_height(mat), height);
  ASSERT_EQUAL(Matrix_width(mat), width);

  delete mat;
}
  
TEST(test_row_column_HUGE){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Sets the maxmium dimensions in the test
  const int width = 500;
  const int height = 500;
  const int value = 69;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  // Checks if the row and column outputs are correct
  const int *ptr = Matrix_at(mat, 469, 310);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 469);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 310);

  delete mat;
}
TEST(test_max_HUGE){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Sets the maxmium dimensions in the test
  const int width = 500;
  const int height = 500;
  const int value = 69;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);

  // Checks if the maxmimum value in the matrix is correct
  ASSERT_EQUAL(Matrix_max(mat), 69);

  delete mat;
}

TEST(test_border_HUGE){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  // Sets the maxmium dimensions in the test
  const int width = 500;
  const int height = 500;
  const int value = 69;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  
  // Checks if the fill border works at the maximum level
  Matrix_fill_border(mat, 1);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 231, 0, 500), 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 7, 0, 500), 1)

  delete mat;
}

TEST(test_matrix_print) {
  
  // Initializes the matrix
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);

  // Checks if the expected and the actual are the same
  *Matrix_at(mat, 0, 0) = 42;
  ostringstream expected;
  expected << "1 1\n"
          << "42 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat;
}

TEST(test_matrix_print_border){
  
  // Initializes the matrix
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 5);

  // Checks if the expected and the actual are the same
  Matrix_fill(mat, 1);
  Matrix_fill_border(mat, 2);

  // for (int i = 0; i < 5; ++i){
  //   for (int j = 0; j < 5; ++j){
  //     cout << mat->data[(i*5) + j];
  //   }
  //   cout << "\n";
  // }
  ostringstream expected;
  expected << "5 5\n"
          << "2 2 2 2 2 \n"
          << "2 1 1 1 2 \n"
          << "2 1 1 1 2 \n"
          << "2 1 1 1 2 \n"
          << "2 2 2 2 2 \n";

  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
  
  delete mat;
}


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
