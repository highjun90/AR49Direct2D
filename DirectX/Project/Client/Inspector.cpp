#include "pch.h"
#include "Inspector.h"

#include <Engine/CTransform.h>

#include "TransformUI.h"
#include "MeshRenderUI.h"
#include "Collider2DUI.h"
#include "Light2DUI.h"
#include "Animator2DUI.h"

#include "AssetUI.h"


Inspector::Inspector()
	: UI("Inspector", "##Inspector")
	, m_TargetObject(nullptr)
	, m_arrComUI{}
{
	// �ڽ� UI ����
	CreateChildUI();
}

Inspector::~Inspector()
{
}

void Inspector::tick()
{
}

void Inspector::render_update()
{
	if (nullptr == m_TargetObject)
		return;

	if (nullptr != m_TargetObject)
	{
		string strName = string(m_TargetObject->GetName().begin(), m_TargetObject->GetName().end());
		ImGui::Text(strName.c_str());
	}
}

void Inspector::SetTargetObject(CGameObject* _Object)
{
	// Target ������Ʈ ����
	m_TargetObject = _Object;

	// �ش� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� �����ϴ� ������ƮUI Ȱ��ȭ
	for (UINT i = 0; i < (UINT)COMPONENT_TYPE::END; ++i)
	{
		if (nullptr != m_arrComUI[i])
		{
			m_arrComUI[i]->SetTargetObject(_Object);
		}
	}

	// AssetUI ��Ȱ��ȭ
	for (UINT i = 0; i < (UINT)ASSET_TYPE::END; ++i)
	{
		m_arrAssetUI[i]->Deactivate();
	}
}

void Inspector::SetTargetAsset(Ptr<CAsset> _Asset)
{
	SetTargetObject(nullptr);

	m_TargetAsset = _Asset;

	for (UINT i = 0; i < (UINT)ASSET_TYPE::END; ++i)
	{
		m_arrAssetUI[i]->Deactivate();
	}
		
	if(nullptr != m_TargetAsset)
	{
		m_arrAssetUI[(UINT)m_TargetAsset->GetType()]->Activate();
		m_arrAssetUI[(UINT)m_TargetAsset->GetType()]->SetAsset(_Asset);
	}	
}