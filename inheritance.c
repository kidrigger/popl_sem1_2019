/*
 * Inheritance.c
 * Author: Anish Bhobe
 * For Principles of Programming Languages, Sem I, 2019-20
 * BITS Pilani, K. K. Birla Goa Campus
 * Date: 09 Sept 2019
 */

#include <stdbool.h>
#include <stdio.h>

typedef enum shape_type_t {
  SHAPE_TYPE_SPHERE,
  SHAPE_TYPE_CUBOID,
  SHAPE_TYPE_RECTANGLE,
  SHAPE_TYPE_TRIANGLE
} shape_type;

typedef struct shape_t {
  shape_type sType;
} shape;

typedef struct vec3_t {
  float x;
  float y;
  float z;
} vec3;

typedef struct sphere_t {
  shape_type sType;
  vec3 center;
  float radius;
} sphere;

typedef struct cuboid_t {
  shape_type sType;
  vec3 min;
  vec3 max;
} cuboid;

typedef struct rectangle_t {
  shape_type sType;
  vec3 min;
  vec3 max;
} rectangle;

typedef struct triangle_t {
  shape_type sType;
  vec3 A;
  vec3 B;
  vec3 C;
} triangle;

typedef struct ray_t {
  vec3 origin;
  vec3 direction;
} ray;

bool hit(shape *s, ray r);
bool hit_sphere(sphere *s, ray r);
bool hit_cuboid(cuboid *s, ray r);
bool hit_rectangle(rectangle *s, ray r);
bool hit_triangle(triangle *s, ray r);

int main() {
  // CHANGE ENUM to check problems.
  sphere m_sphere = {SHAPE_TYPE_SPHERE, {0.f, 0.f, 0.f}, 1.f};
  cuboid m_cuboid = {SHAPE_TYPE_CUBOID, {0.f, 0.f, 0.f}, {1.f, 1.f, 1.f}};
  triangle m_triangle = {
      SHAPE_TYPE_TRIANGLE, {0.f, 0.f, 1.f}, {1.f, 0.f, 1.f}, {0.f, 1.f, 1.f}};

  ray m_ray = {{0.f, 0.f, 0.f}, {0.25f, 0.25f, 0.25f}};

  shape *p_shape = (shape *)&m_sphere;
  hit(p_shape, m_ray);
}

bool hit(shape *s, ray r) {
  // Dispatch by enum.
  switch (s->sType) {
  case SHAPE_TYPE_SPHERE: {
    return hit_sphere((sphere *)s, r);
  }
  case SHAPE_TYPE_CUBOID: {
    return hit_cuboid((cuboid *)s, r);
  }
  case SHAPE_TYPE_RECTANGLE: {
    return hit_rectangle((rectangle *)s, r);
  }
  case SHAPE_TYPE_TRIANGLE: {
    return hit_triangle((triangle *)s, r);
  }
  }
}

bool hit_sphere(sphere *s, ray r) {
  printf("Hit Sphere.\n{(%.2f, %.2f, %.2f),\n(%.2f)}\n", s->center.x,
         s->center.y, s->center.z, s->radius);
  return true;
}
bool hit_cuboid(cuboid *s, ray r) {
  printf("Hit Cuboid.\n{(%.2f, %.2f, %.2f),\n(%.2f, %.2f, %.2f)}\n", s->min.x,
         s->min.y, s->min.z, s->max.x, s->max.y, s->max.z);
  return true;
}
bool hit_rectangle(rectangle *s, ray r) {
  printf("Hit Rectangle.\n{(%.2f, %.2f, %.2f),\n(%.2f, %.2f, %.2f)}\n",
         s->min.x, s->min.y, s->min.z, s->max.x, s->max.y, s->max.z);
  return true;
}
bool hit_triangle(triangle *s, ray r) {
  printf("Hit Triangle.\n{(%.2f, %.2f, %.2f),\n(%.2f, %.2f, %.2f),\n(%.2f, "
         "%.2f, %.2f)}\n",
         s->A.x, s->A.y, s->A.z, s->B.x, s->B.y, s->B.z, s->C.x, s->C.y,
         s->C.z);
  return true;
}
