#include "pch.h"
#include "Converter.h"

Converter::Converter()
{
	_importer = make_shared<Assimp::Importer>();
}

Converter::~Converter()
{
}

void Converter::ReadAssetFile(wstring file)
{
}

void Converter::ReadModelData(aiNode* node, int32 index, int32 parent)
{
}

void Converter::ReadMaterialData()
{
}
