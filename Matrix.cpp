// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.h"
using namespace std;

// Added ourselves
// using namespace std;

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
  
  // Checks to make sure that the given width and height pass these required conditions
  assert(0 < width && width <= MAX_MATRIX_WIDTH);
  assert(0 < height && height <= MAX_MATRIX_HEIGHT);

  // Sets the mat variables of width and height to the width and height that is given
  mat->width = width;
  mat->height = height;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {

  // Checks if the matrix is valid
  assert(mat != nullptr); // TODO Replace with your implementation!

  // Prints the matrix in accordance to the width and height
  os << mat->width << " " << mat->height << "\n";
  for (int i = 0; i < mat->height; ++i) {
    for (int j = 0; j < mat->width; ++j) {
      os << *Matrix_at(mat, i, j) << " ";
    }
    os << "\n";
  }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {

  // Checks if the matrix is valid
  assert(mat != nullptr); // TODO Replace with your implementation!

  // Returns width of matrix
  return mat->width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
  
  // Checks if the matrix is valid
  assert(mat != nullptr); // TODO Replace with your implementation!

  // Returns height of matrix
  return mat->height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
  
  // Checks if both the matrix and the pointer are valid
  assert(mat != nullptr);
  assert(ptr != nullptr); // TODO Replace with your implementation!

  // Returns the row of the element
  for (int i = 0; i < (mat->width * mat->height); ++i) {
    if (&mat->data[i] == ptr){
      return i/(mat->width);
    }
  }
  return -1;
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
  
  // Checks if both the matrix and the pointer are valid
  assert(mat != nullptr);
  assert(ptr != nullptr); // TODO Replace with your implementation!

  // Returns the column of the element
  for (int i = 0; i < (mat->width * mat->height); ++i) {
    if (&mat->data[i] == ptr){
      return i % (mat->width);
    }
  }
  return -1;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
  // Checks if the matrix is valid as well as 
  // if the row and column values meet the min/max
  assert(mat != nullptr);
  if (row < 0 || row >= Matrix_height(mat)) {
    cout << "the row is " << row;
    cout << "height" << Matrix_height(mat);
  }
  assert(0 <= row && row < Matrix_height(mat));
  assert(0 <= column && column < Matrix_width(mat));

  // Return the address at a certain row and column
  int index = (row*(mat->width)) + column;
  return &mat->data[index];;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
  
  // Checks if the matrix if valid as well as 
  // if the row and column values meet the min/max
  assert(mat != nullptr);
  assert(0 <= row && row < Matrix_height(mat));
  assert(0 <= column && column < Matrix_width(mat)); 

  // Return the address at a certain row and column
  int index = (row*(mat->width)) + column;
  const int* ptr = &mat->data[index];
  return ptr;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
  assert(mat != nullptr); // TODO Replace with your implementation!
  
  // Fills the matrix with the given value
  for (int i = 0; i < (mat->width * mat->height); ++i) {
      mat->data[i] = value;
  }
}
// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
  assert(mat != nullptr); 
  
  // Fills the first row
  for (int i = 0; i < mat->width; ++i){
    mat->data[i] = value;
  }

  // Fills the first column
  for (int j = 0; j < mat->width * mat->height; j+=mat->width) {
    mat->data[j] = value;
  }

  // Fills the last row
  for (int k = mat->width * mat->height - mat->width; k < mat->width * mat->height; ++k){
    mat->data[k] = value;
  }

  // Fills the last column
  for (int l = mat->width-1; l < mat->width * mat->height; l+=mat->width) {
    mat-> data[l] = value;
  }
}

// REQUIRES: mat points to a valid matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
  
  // Check if matrix is valid
  assert(mat != nullptr); // TODO Replace with your implementation!
  
  // Initializes the temporary max value to the first value
  int max = mat->data[0];
  
  // Finds and returns the maximum value of the matrix
  for (int i = 1; i < mat->height * mat->width; ++i){
    if (mat->data[i] > max){
      max = mat->data[i];
    }
  }
  return max;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row, 
                                      int column_start, int column_end) {
  
  // Checks if the matrix is valid and if the row and columns fit the min/max
  assert(mat != nullptr);
  assert(0 <= row && row < Matrix_height(mat));
  assert(0 <= column_start && column_end <= Matrix_width(mat));
  assert(column_start < column_end); // TODO Replace with your implementation!

  // Sets the min value as the first value of the section that we are iterating through
  int min = mat->data[((mat->width * row) + column_start)];
  int temp = (mat->width * row) + column_start;

  // Finds and returns the column of the minimum value in a certain row
  for (int i = ((mat->width * row) + column_start) + 1; 
            i < ((mat->width * row) + column_end); ++i){
    if (mat->data[i] < min){
      min = mat->data[i];
      temp = i;
    }
  }
  return temp % (mat->width);
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row, 
                          int column_start, int column_end) {
  assert(mat != nullptr);
  assert(0 <= row && row <= Matrix_height(mat));
  assert(0 <= column_start && column_end <= Matrix_width(mat));
  assert(column_start < column_end); // TODO Replace with your implementation!

// Sets the min value as the first value of the section that we are iterating through
int min = mat->data[((mat->width * row) + column_start)];

// Finds and returns the minimum value within the section that we are iterating through
for (int i = (mat->width * row) + column_start + 1; 
          i < (mat->width * row) + column_end; ++i){
  if (mat->data[i] < min){
    min = mat->data[i];
  }
}
return min;
}
