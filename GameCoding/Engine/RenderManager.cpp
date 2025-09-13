#include "pch.h"
#include "RenderManager.h"
#include "Camera.h"

void RenderManager::Init(shared_ptr<Shader> shader)
{
	_shader = shader;

	_globalBuffer = make_shared<ConstantBuffer<GlobalDesc>>();
	_globalBuffer->Create();
	_globalEffectBuffer = shader->GetConstantBuffer("GlobalBuffer");	// 셰이더 파일에서 가져온다.
	
	_transformBuffer = make_shared<ConstantBuffer<TransformDesc>>();
	_transformBuffer->Create();
	_transformEffectBuffer = shader->GetConstantBuffer("TransformBuffer");	// 셰이더 파일에서 가져온다.

	_lightBuffer = make_shared<ConstantBuffer<LightDesc>>();
	_lightBuffer->Create();
	_lightEffectBuffer = shader->GetConstantBuffer("LightBuffer");	// 셰이더 파일에서 가져온다.

	_materialBuffer = make_shared<ConstantBuffer<MaterialDesc>>();
	_materialBuffer->Create();
	_materialEffectBuffer = shader->GetConstantBuffer("MaterialBuffer");	// 셰이더 파일에서 가져온다.
}

void RenderManager::Update()
{
	PushGlobalData(Camera::S_MatView, Camera::S_MatProjection);
}

void RenderManager::PushGlobalData(const Matrix& view, const Matrix& projection)
{
	_globalDesc.V = view;
	_globalDesc.P = projection;
	_globalDesc.VP = view * projection;
	_globalBuffer->CopyData(_globalDesc);
	
	_globalEffectBuffer->SetConstantBuffer(_globalBuffer->GetComPtr().Get());
}

void RenderManager::PushLightData(const LightDesc& desc)
{
	_lightDesc = desc;

	_lightBuffer->CopyData(_lightDesc);

	_lightEffectBuffer->SetConstantBuffer(_lightBuffer->GetComPtr().Get());
}

void RenderManager::PushMaterialData(const MaterialDesc& desc)
{
	_materialDesc = desc;

	_materialBuffer->CopyData(_materialDesc);

	_materialEffectBuffer->SetConstantBuffer(_materialBuffer->GetComPtr().Get());
}

void RenderManager::PushTransformData(const TransformDesc& desc)
{
	_transformDesc = desc;
	_transformBuffer->CopyData(_transformDesc);
	_transformEffectBuffer->SetConstantBuffer(_transformBuffer->GetComPtr().Get());
}
