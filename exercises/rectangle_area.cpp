#include <iostream>

#define max(a, b) (a > b) ? a : b
#define min(a, b) (a > b) ? b : a

int rectangle_area(const int A,
                   const int B,
                   const int C,
                   const int D,
                   const int E,
                   const int F,
                   const int G,
                   const int H)
{
  int overlap_left = max(A, E);
  int overlap_right = max(min(C, G), overlap_left);
  int overlap_bottom = max(B, F);
  int overlap_top = max(min(D, H), overlap_bottom);

  return (C - A)*(D - B) +
         (G - E)*(H - F) -
         (overlap_right - overlap_left)*(overlap_top-overlap_bottom);
}
int main(int argc, char** argv) {
  if (argc != 9)
  {
    std::cout << "usage: " << argv[0] <<
    " <(x, y) bottom left rect 1> <(x, y) top right rect 1>" <<
    " <(x, y) bottom left rect 2> <(x, y) top right rect 2>" << std::endl;
    return 1;
  }

  int a = std::atoi(argv[1]);
  int b = std::atoi(argv[2]);
  int c = std::atoi(argv[3]);
  int d = std::atoi(argv[4]);
  int e = std::atoi(argv[5]);
  int f = std::atoi(argv[6]);
  int g = std::atoi(argv[7]);
  int h = std::atoi(argv[8]);

  std::cout << "rect 1: (" << a << ", " << b << ") " <<
                       "(" << c << ", " << d << ") " << std::endl;
  std::cout << "rect 2: (" << e << ", " << f << ") " <<
                       "(" << g << ", " << h << ") " << std::endl;

  std::cout << "total area: " << rectangle_area(a, b, c, d, e, f, g, h) << std::endl;
  return 0;
}
