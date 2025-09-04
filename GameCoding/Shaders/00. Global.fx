// 다른 셰이더에서 #include를 통해 공용으로 사용하게 될 셰이더 파일.

// #pragme once 처럼 중복 방지하기.
#ifndef _GLOBAL_FX_
#define _GLOBAL_FX_

///////////////////
// ConstantBuffer//
///////////////////

cbuffer GlobalBuffer
{
	matrix V;
	matrix P;
	matrix VP;
};

cbuffer TransformBuffer
{
	matrix W;
};

////////////////
// VertexData //
////////////////

struct Vertex
{
	float4 position : POSITION;
};

struct VertexTexture
{
	float4 position : POSITION;
	float2 uv : TEXCOORD;
};

struct VertexColor
{
	float4 position : POSITION;
	float4 color : COLOR;
};

struct VertexTextureNormal
{
	float4 position : POSITION;
	float2 uv : TEXCOORD;
	float3 normal : NORMAL;
};

//////////////////
// VertexOutput //
//////////////////

struct VertexOutput
{
	float4 position : SV_POSITION;
	float2 uv       : TEXCOORD0;
	float3 normal   : TEXCOORD1;  // NORMAL → TEXCOORD1 로 변경
};

//////////////////
// SamplerState //
//////////////////

SamplerState LinearSampler
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;
	AddressV = Wrap;
};

SamplerState PointSampler
{
	Filter = MIN_MAG_MIP_POINT;
	AddressU = Wrap;
	AddressV = Wrap;
};

/////////////////////
// RasterizerState //
/////////////////////

RasterizerState FillModeWireFrame
{
	FillMode = WireFrame;
};

///////////
// Macro //
///////////

#define PASS_VP(name, vs, ps)						\
pass name											\
{													\
	SetVertexShader(CompileShader(vs_5_0, vs()));	\
	SetPixelShader(CompileShader(ps_5_0, ps()));	\
}													

//////////////
// Function //
//////////////



#endif
