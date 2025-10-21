#include "Mesh.hpp"

namespace CFD::Mesh {

double tolerance = 0.0001;

Vec3D Vec3D::operator+(const Vec3D& other) {
    return Vec3D(x+other.x, y+other.y, z+other.z);
}
Vec3D Vec3D::operator+(double val) {
    return Vec3D(x+val, y+val, z+val);
}
Vec3D Vec3D::operator-(const Vec3D& other) {
    return Vec3D(x-other.x, y-other.y, z-other.z);
}
Vec3D Vec3D::operator-(double val) {
    return Vec3D(x-val, y-val, z-val);
}
Vec3D Vec3D::operator*(double val) {
    return Vec3D(x*val, y*val, z*val);
}
Vec3D Vec3D::operator/(double val) {
    return Vec3D(x/val, y/val, z/val);
}
bool Vec3D::operator==(const Vec3D& other) const {
    return  (abs(x-other.x)<tolerance) &&
            (abs(y-other.y)<tolerance) &&
            (abs(z-other.z)<tolerance);
}
std::ostream& operator<<(std::ostream& os, const Vec3D& vec) {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}

double dot(const Vec3D& a, const Vec3D& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
Vec3D cross(const Vec3D& a, const Vec3D& b) {
    return Vec3D(a.y*b.z-a.z*b.y,-a.x*b.z+a.z*b.x,a.x*b.y+a.y*b.x);
}
double mag(const Vec3D& a) {
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
Vec3D getNormal(Vec3D& a) {
    return a/mag(a);
}

}