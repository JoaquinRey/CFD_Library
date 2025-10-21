#include "Mesh.hpp"

namespace CFD::Mesh {

void Mesh::addSquare(Vec3D origin, Vec3D xaxis, Vec3D yaxis) {
    int p1 = points.push(xaxis*0.5 + yaxis*0.5 + origin);
    int p2 = points.push(xaxis*-0.5 + yaxis*0.5 + origin);
    int p3 = points.push(xaxis*0.5 - yaxis*0.5 + origin);
    int p4 = points.push(xaxis*-0.5 - yaxis*0.5 + origin);
    // p4 -> p3 -> p1
    Vec3D normal = cross(xaxis, yaxis);
    faces.push_back({p1,p2,p3,p4,0,normal});
}

void Mesh::addCube(Vec3D origin, Vec3D xaxis, Vec3D yaxis) {

}

void Mesh::createGrid(size_t width, size_t length, size_t height) {
    Vec3D xaxis = {1,0,0};
    Vec3D yaxis = {0,1,0};
    Vec3D zaxis = {0,0,1};
    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < length; j++) {
            for (size_t k = 0; k < height; k++) {
                Cell curr;
                double x = static_cast<double>(i);
                double y = static_cast<double>(j);
                double z = static_cast<double>(k);
                int p1 = points.push({x,y,z});
                int p2 = points.push({x+1,y,z});
                int p3 = points.push({x+1,y+1,z});
                int p4 = points.push({x,y+1,z});

                int p5 = points.push({x,y,z+1});
                int p6 = points.push({x+1,y,z+1});
                int p7 = points.push({x+1,y+1,z+1});
                int p8 = points.push({x,y+1,z+1});

                for (size_t idx = faces.size(); idx < faces.size()+6; idx++) {
                    curr.faces.push_back(idx);
                }

                faces.push_back({p1,p2,p3,p4,0,zaxis*(-1)});
                faces.push_back({p5,p6,p7,p8,0,zaxis});
                faces.push_back({p1,p2,p5,p6,0,yaxis*(-1)});
                faces.push_back({p3,p4,p7,p8,0,yaxis});
                faces.push_back({p1,p4,p5,p8,0,xaxis*(-1)});
                faces.push_back({p2,p3,p6,p7,0,xaxis});
                cells.push_back(curr);
            }
        }
    }
}

void Mesh::printData() {
    std::cout << "Point ";
    points.printData();
    std::cout << faces.size() << " num faces\n";
    for (auto f : faces) {
        std::cout << "Face: " << f.a << ", " << f.b << ", " << f.c << ", " << f.d << "\n";
    }
    std::cout << cells.size() << " num cells\n";
    for (auto c : cells) {
        std::cout << "Cell points: \n";
        std::cout << c.faces.size() << "\n";
        for (auto p : c.faces) {
            std::cout << p << "\n";
        }
    }
}


}