#include "Mesh.hpp"

using namespace CFD::Mesh;

void solve(CFD::Mesh::Mesh& mesh, double Tf, int N) {
    double dT = Tf / N;
    for (int i = 0; i < N; i++) {
        std::vector<double> residuals;
        residuals.reserve(mesh.points.size());
        for (int j = 0; j < mesh.points.size(); j++) {
            Vec3D uT = mesh.velocityField[j] * mesh.temperatureField[j];
            Vec3D alfT = grad(mesh.temperatureField[j]);
            residuals[j] = div(uT) - div(alfT);
        }
    }
}