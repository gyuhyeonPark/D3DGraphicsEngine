#include "00. Global.fx"
#include "00. Light.fx"

float3 LightDir;
float4 LightSpecular;
float4 MaterialSpecular;

MeshOutput VS(VertexTextureNormal input)
{
	MeshOutput output;
	output.position = mul(input.position, W);
	output.worldPosition = input.position.xyz;
	output.position = mul(output.position, VP);
	output.uv = input.uv;
	output.normal = mul(input.normal, (float3x3)W);

	return output;
}

// Specular (�ݻ籤)
// �� �������� ������ �ݻ�Ǵ� �� (Phong)
float4 PS(MeshOutput input) : SV_TARGET
{
	float4 color = ComputeLight(input.normal, input.uv, input.worldPosition);

	return color;
}

technique11 T0
{
	PASS_VP(PO, VS, PS)
};
