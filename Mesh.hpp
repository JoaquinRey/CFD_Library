#pragma once
#include "ktree.hpp"
#include <vector>
#include <math.h>
#include <iostream>
#include <cstdint>

namespace CFD::Mesh {
    
struct Vec3D {
    double x;
    double y;
    double z;

    Vec3D() : x(0), y(0), z(0) {}
    Vec3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    Vec3D operator+(const Vec3D& other);
    Vec3D operator+(double val);
    Vec3D operator-(const Vec3D& other);
    Vec3D operator-(double val);
    Vec3D operator*(double val);
    Vec3D operator/(double val);
    bool operator==(const Vec3D& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Vec3D& vec);
};

struct MatrixRange {
    enum RangeTag {Single, Bound, Unbound, Absent};
    RangeTag i_tag;
    size_t i_lower;
    size_t i_upper;
    RangeTag j_tag;
    size_t j_lower;
    size_t j_upper;

    MatrixRange(size_t i, size_t j)
    :   i_tag(Single), j_tag(Single),
        i_lower(i), j_lower(j) {}
    MatrixRange(size_t i);
};
struct MatrixItem {
    size_t i;
    size_t j;
};

class Matrix2D {
private:
    std::vector<std::vector<double>> data;

public:
    Matrix2D();
    Matrix2D(double val);

    Matrix2D operator+(const Matrix2D& other);
    Matrix2D operator-(const Matrix2D& other);
    Matrix2D operator*(const Matrix2D& other);
    Matrix2D operator/(const Matrix2D& other);

    Matrix2D operator[](MatrixRange range);

};

struct Face {
    int a;
    int b;
    int c;
    int d;
    int neighbor;
    Vec3D normal;

    std::ostream& operator<<(std::ostream& os) {
        os << "Face: " << a << ", " << b << ", " << c << ", " << d;
        return os;
    }
};

struct Cell {
    double volume;
    Vec3D cellCenter;
    std::vector<size_t> faces;
};

template <typename Type>
struct Field {
    std::vector<Type> fieldData;

    template <typename OtherType>
    Field<Type> operator*(const Field<OtherType>& other);
};

double dot(const Vec3D& a, const Vec3D& b);
Vec3D cross(const Vec3D& a, const Vec3D& b);
double mag(const Vec3D& a);
Vec3D getNormal(Vec3D& a);

double div(Vec3D& vec);

Vec3D grad(const Vec3D& vec);
Vec3D grad(double val);

class ComparePoints {
public:
    bool operator()(const CFD::Mesh::Vec3D& p1, const CFD::Mesh::Vec3D& p2, uint32_t layer) const {
        switch (layer) {
            case 0:
                return p1.x < p2.x;
                break;
            case 1:
                return p1.y < p2.y;
                break;
            case 2:
                return p1.z < p2.z;
                break;
        }
        return false;
    }
};

struct Mesh {
    KTree<Vec3D,3,ComparePoints> points;
    std::vector<Face> faces;
    std::vector<Cell> cells;
    std::vector<Vec3D> velocityField;
    std::vector<double> pressureField;
    std::vector<double> temperatureField;

    uint32_t addPoint(Vec3D&& point);
    void addSquare(Vec3D origin, Vec3D xaxis, Vec3D yaxis);
    void addCube(Vec3D origin, Vec3D xaxis, Vec3D yaxis);
    void createGrid(size_t width, size_t length, size_t height);
    void printData();
};


class PointContainer : private KTree<Vec3D,3,ComparePoints> {

private:
    std::vector<Vec3D> prev;

public:

};

}