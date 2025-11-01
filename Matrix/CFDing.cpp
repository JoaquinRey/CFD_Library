#include "Value.hpp"
#include "Matrix.hpp"
#include "Mesh.hpp"

using namespace CFD::Types;

Matrix construct_A( std::vector<Cell> cells, 
                    std::vector<Vector> u_curr, 
                    std::vector<Vector> u_prev) {
    size_t n = u_curr.size();
    Matrix tmp(n);
    for (size_t i = 0; i < n; i++) {

    }
}

Matrix construct_ddt(   std::vector<Cell> cells, 
                        Matrix u_curr, 
                        Matrix u_prev,
                        double dt) 
{

}

Matrix grad(const Matrix& field, const Matrix& u, double density, std::vector<Cell>& cells) {
    Matrix tmp{cells.size(), 1};
    for (size_t i = 0; i < cells.size(); i++) {
        Cell curr_cell = cells[i];
        for (size_t j = 0; j < cells[i].faces.size(); j++) {
            
            tmp.at(i,1) = tmp.at(i,1) + cells[i].faces[j].normal * u.at(i,1) * field.at(i,1) * density;
        }
        tmp.at(i,1) = tmp.at(i,1) / cells[i].volume;
    }
}

Matrix div(const Matrix& field, std::vector<Cell>& cells) {
    Matrix tmp{cells.size(), 1};
}

int main() {
    std::vector<size_t> no_slip_cells;
    std::vector<size_t> freestream_cells;
    Value no_slip_BC = Vector{0,0,0};
    Value constant_flow_BC = Vector{1,0,0};

    size_t num_cells = 100;
    double dt = 0.1;
    Matrix A(num_cells);
    Matrix phi_b{num_cells,1};
    Matrix phi_curr{num_cells,1};
    Matrix phi_prev{num_cells,1};

    for (size_t i = 0; i < num_cells; i++) {
        A.at(i,i) = 1/dt;
        phi_b.at(i,1) = phi_prev.at(i,1)/dt;
    }

    // boundary conditions
    for (size_t i = 0; i < no_slip_cells.size(); i++) {
        A.at(no_slip_cells[i],no_slip_cells[i]) = 1;
        phi_b.at(no_slip_cells[i],1) = no_slip_BC;
    }
    for (size_t i = 0; i < freestream_cells.size(); i++) {
        A.at(freestream_cells[i],freestream_cells[i]) = 1;
        phi_b.at(freestream_cells[i],1) = constant_flow_BC;
    }


    return 0;
}