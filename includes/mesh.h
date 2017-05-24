#ifndef _MESH_H_
#define _MESH_H_

#include <iostream>
#include <vector>

#include "point.h"
#include "normal.h"

using std::vector;
using std::ostream;

template <typename T>
struct Mesh{

    vector<Point<T>>    vertices;
    vector<Normal<T>>   normals;
    vector<T>           v;
    vector<T>           u;
    vector<vector<int>> vertexfaces;
    int                 numvertices;
    int                 numtriangles;

    Mesh(void) : numvertices(0), numtriangles(0) {}
    Mesh(const Mesh<T>&);
    
    Mesh<T>& operator=(const Mesh<T>&);

    friend ostream &operator<<(ostream& os, const Mesh<T>& in)
    {
        os << "Mesh: numvert- " << in.numvertices << " numtri- " << in.numtriangles;
        return os;
    }
};
typedef Mesh<float>  Meshf;
typedef Mesh<double> Meshd;

template <typename T>
Mesh<T>::Mesh(const Mesh<T>& in)
    :   vertices(in.vertices),
        normals(in.normals),
        u(in.u),
        v(in.v),
        numvertices(in.numvertices),
        numtriangles(in.numtriangles)
{}

template <typename T>
Mesh<T>&
Mesh<T>::operator=(const Mesh<T>& rhs)
{
    if(this == &rhs)
        return (*this);

    vertices    = rhs.vertices;
    normals      = rhs.normals;
    u            = rhs.u;
    v            = rhs.v;
    numvertices = rhs.numvertices;
    numtriangles = rhs.numtriangles;
    
    return (*this);
}

#endif
