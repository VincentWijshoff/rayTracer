#include "viewplane.hpp"

Viewplane::Viewplane(double hres, double vres, double pixelsize) : hres(hres), vres(vres), pixelSize(pixelsize) {}

double Viewplane::getHres() const {return hres;}
double Viewplane::getVres() const {return vres;}
double Viewplane::getPixelSize() const {return pixelSize;}

void Viewplane::setHres(double hResVal) {hres=hResVal;}
void Viewplane::setVres(double vResVal) {vres=vResVal;}
void Viewplane::setPixelSize(double pxval) {pixelSize=pxval;}

// operations
// columns and rows are counted from the bottom left
// x and y coordinates are counted from the middle of the viewplane
//get the x-coordinate of the given index of the column
double Viewplane::getX(int column) const {
    double tmp = static_cast<double>(column);
    tmp += hres2;
    tmp *= pixelSize;
    return tmp;
}
//get the y-coordinate of the given index of the row
double Viewplane::getY(int row) const {
    double tmp = static_cast<double>(row);
    tmp += vres2;
    tmp *= pixelSize;
    return tmp;
};

std::ostream& operator<<(std::ostream& os, const Viewplane& vp) {
    os << "hres: " << vp.hres << std::endl;
    os << "vres: " << vp.vres << std::endl;
    os << "pixel size: " << vp.pixelSize << std::endl;
    os << "(0, 0) on the plane: (" << vp.getX(0) << ", " << vp.getY(0) <<")" << std::endl;
    return os;
}