//****************************************************************
//* This file is part of the AsFem framework
//* A Simple Finite Element Method program (AsFem)
//* All rights reserved, Yang Bai/M3 Group @ CopyRight 2022
//* https://github.com/M3Group/AsFem
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Author : Yang Bai
//+++ Date   : 2020.06.26
//+++ Purpose: implement msh(ver=2) mesh file importer
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once
#include "Mesh/MeshIOBase.h"
#include "Mesh/MeshType.h"

#include "Utils/MessagePrinter.h"

class Gmsh2IO:public MeshIOBase{
public:
    Gmsh2IO(){
        _MeshFileName.clear();
        _HasSetMeshFileName=false;
    }

    virtual bool ReadMeshFromFile(Mesh &mesh) override;
    virtual void SetMeshFileName(string filename)override{_MeshFileName=filename;_HasSetMeshFileName=true;}
    virtual string GetMeshFileName()const override{return _MeshFileName;}

private:
    int GetElmtNodesNumFromGmshElmtType(const int &elmttype) const;
    int GetElmtDimFromGmshElmtType(const int &elmttype) const;
    int GetElmtOrderFromGmshElmtType(const int &elmttype)const;
    int GetElmtVTKCellTypeFromGmshElmtType(const int &elmttype)const;
    MeshType GetElmtMeshTypeFromGmshElmtType(const int &elmttype)const;
    string GetElmtTypeNameFromGmshElmtType(const int &elmttype)const;

    int GetSubElmtNodesNumFromGmshElmtType(const int &elmttype) const;
    int GetSubElmtDimFromGmshElmtType(const int &elmttype) const;
    int GetSubElmtOrderFromGmshElmtType(const int &elmttype)const;
    MeshType GetSubElmtMeshTypeFromGmshElmtType(const int &elmttype)const;


    ifstream _in;

    int _nMaxDim=-1,_nMinDim=4;
    int _nPhysicGroups=0;
    int _nNodeSetPhysicalGroups=0;
    int _nNodes=0,_nElmts=0;
    int _nBulkElmts=0,_nSurfaceElmts=0,_nLineElmts=0;
    
    double _Xmax,_Xmin,_Ymax,_Ymin,_Zmax,_Zmin;

    int _nNodesPerBulkElmt=-1;
    int _nNodesPerLineElmt=0;
    int _nNodesPerSurfaceElmt=0;
    int _nOrder=1;


};