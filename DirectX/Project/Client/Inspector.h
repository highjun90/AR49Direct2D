#pragma once
#include "UI.h"

// GameObject ����
//  - ������Ʈ
//  - ��ũ��Ʈ

// Asset ����
//  - �� ������ ����

#include <Engine/CGameObject.h>
#include <Engine/CAsset.h>

class ComponentUI;
class AssetUI;

class Inspector :
    public UI
{
private:
    CGameObject*    m_TargetObject;
    Ptr<CAsset>     m_TargetAsset;

    ComponentUI*    m_arrComUI[(UINT)COMPONENT_TYPE::END];
    AssetUI*        m_arrAssetUI[(UINT)ASSET_TYPE::END];

public:
    virtual void tick() override;
    virtual void render_update() override;

public:
    void SetTargetObject(CGameObject* _Object);
    void SetTargetAsset(Ptr<CAsset> _Asset);

    CGameObject* GetTargetObject() { return m_TargetObject; }

private:
    void CreateChildUI();
    void CreateComponentUI();
    void CreateAssetUI();

public:
    Inspector();
    ~Inspector();
};
