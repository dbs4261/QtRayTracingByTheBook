#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <array>
#include <vector>

#include "raytracer/utilities/vector_types.h"

namespace raytracer {

struct RGBA {
  static constexpr size_t channels = 4;

  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
};

class Image {
 public:
  Image() noexcept;
  Image(size_t x, size_t y) noexcept;
  Image(const Image& other) noexcept;
  Image(Image&& other) noexcept;

  Image& operator=(const Image& other) noexcept;
  Image& operator=(Image&& other) noexcept;

  const Coordinate<size_t, 2>& GetSize() const;

  void SetSize(const Coordinate<size_t, 2>& new_size);

  std::vector<unsigned char> data;
  std::vector<RGBA>& color_data;
 protected:
  Coordinate<size_t, 2> size;
};

}

#endif //RAYTRACER_IMAGE_H
