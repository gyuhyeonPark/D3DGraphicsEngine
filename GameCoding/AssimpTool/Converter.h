#pragma once
#include "AsTypes.h"

class Converter
{
public:
	Converter();
	~Converter();

public:
	void ReadAssetFile(wstring file);

private:
	void ReadModelData(aiNode* node, int32 index, int32 parent);

private:
	void ReadMaterialData();
	void WriteMaterialData(wstring finalPath);

private:
	wstring _assetPath = L".../Resources/Asset/ "


private:
	shared_ptr<Assimp::Importer> _importer;
	const aiScene* _scene;

private:
	vector<shared_ptr<asBone>> _bones;
	vect
};

