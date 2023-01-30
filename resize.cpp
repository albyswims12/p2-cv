// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include <fstream>
#include "processing.h"

using namespace std;




// There are 4 or 5 arguments, including the executable name itself (i.e. argv[0]).

// The desired width is greater than 0 and less than 
// or equal to the original width of the input image.

// The desired height is greater than 0 and 
// less than or equal to the original height of the input image.

// cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" 
// << "WIDTH and HEIGHT must be less than or equal to original" << endl;
int main(int argc, char *argv[]) {

    // Checks if the number of arguments is either 4 or 5
    if (!(argc == 4 || argc == 5)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" 
            << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return -1;
    }

    // Reads in the two filename arguments and prints error statements if they don't work
    string filename = argv[1];
    string output = argv[2];

    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return -1;
    }
    // Initializes the image with the file given in the argument
    Image* image = new Image;
    Image_init(image, fin);
    
    if (argc == 5) {

        // Initializes the new width and height lengths
        int newWidth = atoi(argv[3]);
        int newHeight = atoi(argv[4]);

        // Checks if the new Width and Height meet the criteria
        if (newWidth <= 0 || newWidth > Image_width(image) || newHeight <= 0 
                                                    || newHeight > Image_height(image)){
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" 
                << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            return -1;
        } else {
            seam_carve(image, newWidth, newHeight);
        }
    } else if (argc == 4) {
        
        // Initializes just the new width and not the height
        int newWidth = atoi(argv[3]);

        // Checks if the new Width and Height meet the criteria
        if (newWidth <= 0 || newWidth > Image_width(image)){
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" 
                << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            return -1;
        } else {
            seam_carve_width(image, newWidth);
        }
    }
    // Prints out the image in ppm format to the output 
    // filename and makes sure it opens correctly
    ofstream fout(output);
    if (!fout.is_open()) {
        cout << "Error opening file: " << output << endl;
        return -1;
    }
    Image_print(image, fout);

    delete image;
    fin.close();
    fout.close();
}