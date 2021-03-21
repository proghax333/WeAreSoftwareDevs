
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int shape_id;
  int should_exit = 0, finish_input = 0;

  const double PI = 3.1415926535;
  const int NUMBER_OF_SHAPES = 6;

  while (!should_exit)
  {
    finish_input = 0;
    printf("**** Centroid Calculator ****\n\n");

    double x = 0, y = 0, cgx = 0, cgy = 0, cx = 0, cy = 0, total_area = 0, area = 0, angle = 0;

    // Shape input loop
    while (!finish_input)
    {
      // Current shape details.
      x = 0, y = 0;
      cx = 0, cy = 0, area = 0;
      angle = 0;

      printf(
          "[Shape IDs]\n"
          "1 => Square\n"
          "2 => Rectangle\n"
          "3 => Right Angled Triangle\n"
          "4 => Full Circle\n"
          "5 => Half Circle\n"
          "6 => Quarter Circle\n"
          "7 => Finish input\n"
          "8 => Exit the program\n"
          "\n");
      scanf("%d", &shape_id);
      printf("\n");

      if (shape_id >= -NUMBER_OF_SHAPES && shape_id <= NUMBER_OF_SHAPES && shape_id != 0)
      {
        printf("Enter x: ");
        scanf("%lf", &x);

        printf("Enter y: ");
        scanf("%lf", &y);
      }

      switch (shape_id)
      {
      case 1: case -1:
      {
        // Square
        double side_length;

        printf("Enter side length: ");
        scanf("%lf", &side_length);
        area = side_length * side_length;
        cx = (side_length / 2);
        cy = (side_length / 2);
        break;
      }
      case 2: case -2:
      {
        // Rectangle
        double width, height;

        printf("Enter width: ");
        scanf("%lf", &width);
        printf("Enter height: ");
        scanf("%lf", &height);
        area = width * height;
        cx = (width / 2);
        cy = (height / 2);

        break;
      }
      case 3: case -3:
      {
        // Right Angled Triangle
        double width, height, angle;

        printf("Enter width: ");
        scanf("%lf", &width);
        printf("Enter height: ");
        scanf("%lf", &height);
        printf("Enter angle(in degrees): ");
        scanf("%lf", &angle);

        area = 0.5 * abs(width) * abs(height);
        cx = width / 3;
        cy = height / 3;

        double epoch = atan2(cy, cx);
        double r = sqrt(cx * cx + cy * cy);
        cx = r * cos((angle / 180 * PI + epoch));
        cy = r * sin((angle / 180 * PI + epoch));

        break;
      }
      case 4: case -4:
      {
        // Full Circle
        double x, y, r;

        printf("Enter radius: ");
        scanf("%lf", &r);

        area = PI * r * r;
        cx = 0;
        cy = 0;

        break;
      }
      case 5: case -5:
      {
        // Half Circle
        double x, y, r;

        printf("Enter radius: ");
        scanf("%lf", &r);
        printf("Enter angle(in degrees): ");
        scanf("%lf", &angle);
        angle = angle / 180 * PI;

        area = PI * r * r / 2;
        
        double t = 4 * r / (3 * PI);
        cx = 0;
        cy = t * sin(angle + PI / 2);

        break;
      }
      case 6: case -6:
      {
        // Quarter Circle
        double x, y, r;

        printf("Enter radius: ");
        scanf("%lf", &r);

        printf("Enter angle(in degrees): ");
        scanf("%lf", &angle);
        angle = angle / 180 * PI;

        area = PI * r * r / 4;
        double t = 4 * r / (3 * PI);
        t = sqrt(2 * t * t);

        cx = t * cos(angle + PI / 4);
        cy = t * sin(angle + PI / 4);

        break;
      }
      case 7:
      {
        finish_input = 1;
        break;
      }
      case 8:
      {
        finish_input = 1;
        should_exit = 1;

        printf("** Calculator Closed **\n");

        return 0;
        break;
      }
      default:
      {
        printf("ERROR: Invalid option chosen.\n");
      }
      }

      // If the shape has to be cut out
      if (shape_id < 0)
        area = -area;

      // Print the centroid of the current shape
      printf("\n[Current cx: %lf | Current cy: %lf]\n", x + cx, y + cy);

      cgx += area * (x + cx);
      cgy += area * (y + cy);
      total_area += area;

      // Print the computed centroid of all currently entered shape
      printf(
          "[Current Result]\n"
          "  Centroid X = %lf\n"
          "  Centroid Y = %lf\n\n",
          cgx / total_area, cgy / total_area);
    }

    /* Display Final Result */
    printf("Sum of Area: %lf\n"
           "  GX = %lf\n"
           "  GY = %lf\n\n",
           total_area, cgx, cgy);

    cgx /= total_area;
    cgy /= total_area;

    printf(
        "[Result]\n"
        "-  Centroid X = %lf\n"
        "-  Centroid Y = %lf\n\n",
        cgx, cgy);

    // End loop
    printf("\n");
  }

  return 0;
}
