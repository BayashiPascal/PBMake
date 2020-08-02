#include "gui.h"

// Main function
int main(
     int argc,
  char** argv) {

  // Initialise the Buzzy
  buzzy = BuzzyCreateStatic();
  BuzzySetFormat(
    &buzzy, 
    16,
    44100,
    2);
  BuzzyOpen(&buzzy);

  // Initialise the GTK library
  gtk_init(
    &argc,
    &argv);

  // Create the application
  app =
    GUICreate(
      argc,
      argv);

  // Run the application
  int status = GUIMain();

  // Return the status at the end of the application
  return status;

}
