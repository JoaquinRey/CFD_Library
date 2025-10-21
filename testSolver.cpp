#include <iostream>
#include "ktree.hpp"
#include "Mesh.hpp"

using namespace CFD;

std::vector<double> testDiv(Mesh::Mesh& mesh) {
    std::vector<double> divField;
    for (size_t i = 0; i < mesh.temperatureField.size(); i++) {
        Mesh::Cell& currCell = mesh.cells[i];
        double cellSum = 0;
        for (size_t f = 0; f < currCell.faces.size(); f++) {
            if (mesh.faces[currCell.faces[f]].neighbor != -1) {
                double surfFlux = Mesh::dot((mesh.faces[currCell.faces[f]]).normal, mesh.velocityField[i]);
                double psi1 = mesh.temperatureField[i];
                double psi2 = mesh.temperatureField[mesh.faces[currCell.faces[f]].neighbor];
                cellSum += surfFlux*(psi1+psi2)/2;
            }
        }
        divField[i] = cellSum / currCell.volume;
    }
    return divField;
}

std::vector<double> testddt(Mesh::Mesh& mesh) {
    
}

void applyBCs(Mesh::Mesh& mesh, std::vector<double>& field) {
    // T at z=1 = 100
    // T at every other wall = 25
    for (Mesh::Face f : mesh.faces) {
        if (f.neighbor == -1) {
            
        }
    }
}

int main() {
    Mesh::Mesh mesh;
    mesh.createGrid(1,1,1);
    return 0;
}