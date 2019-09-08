/*
 * Inheritance.cpp
 * Author: Anish Bhobe
 * For Principles of Programming Languages, Sem I, 2019-20
 * BITS Pilani, K. K. Birla Goa Campus
 * Date: 09 Sept 2019
 */

#include <cstdio>

typedef struct vec3_t {
  float x;
  float y;
  float z;
} vec3;

typedef struct ray_t {
  vec3 origin;
  vec3 direction;
} ray;

class shape {
public:
  virtual bool hit(ray r) = 0;
};

class sphere : public shape {
public:
  vec3 center;
  float radius;
  sphere(vec3 c, float r) : center(c), radius(r) {}
  virtual bool hit(ray r) {
    printf("Hit Sphere.\n{(%.2f, %.2f, %.2f),\n(%.2f)}\n", center.x, center.y,
           center.z, radius);
    return true;
  }
};

class cuboid : public shape {
public:
  vec3 min;
  vec3 max;
  cuboid(vec3 _min, vec3 _max) : min(_min), max(_max) {}
  virtual bool hit(ray r) {
    printf("Hit Cuboid.\n{(%.2f, %.2f, %.2f),\n(%.2f, %.2f, %.2f)}\n", min.x,
           min.y, min.z, max.x, max.y, max.z);
    return true;
  }
};

class rectangle : public shape {
public:
  vec3 min;
  vec3 max;
  rectangle(vec3 _min, vec3 _max) : min(_min), max(_max) {}
  virtual bool hit(ray r) {
    printf("Hit Rectangle.\n{(%.2f, %.2f, %.2f),\n(%.2f, %.2f, %.2f)}\n", min.x,
           min.y, min.z, max.x, max.y, max.z);
    return true;
  }
};

class triangle : public shape {
public:
  vec3 A;
  vec3 B;
  vec3 C;
  triangle(vec3 a, vec3 b, vec3 c) : A(a), B(b), C(c) {}
  bool hit(ray r) {
    printf("Hit Triangle.\n{(%.2f, %.2f, %.2f),\n(%.2f, %.2f, %.2f),\n(%.2f, "
           "%.2f, %.2f)}\n",
           A.x, A.y, A.z, B.x, B.y, B.z, C.x, C.y, C.z);
    return true;
  }
};

bool hit(shape *s, ray r);

int main() {
  sphere m_sphere{{0.f, 0.f, 0.f}, 1.f};
  cuboid m_cuboid{{0.f, 0.f, 0.f}, {1.f, 1.f, 1.f}};
  triangle m_triangle{{0.f, 0.f, 1.f}, {1.f, 0.f, 1.f}, {0.f, 1.f, 1.f}};

  ray m_ray{{0.f, 0.f, 0.f}, {0.25f, 0.25f, 0.25f}};

  shape *p_shape = (shape *)&m_sphere;
  hit(p_shape, m_ray);
}

bool hit(shape *s, ray r) {
  // Dispatch by enum.
  return s->hit(r);
}