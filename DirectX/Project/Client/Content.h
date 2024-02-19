#pragma once
#include "UI.h"

// AssetMgr 에 로딩되어 있는 모든 에셋들을 나열

class TreeUI;

class Content :
    public UI
{
private:
    TreeUI*     m_Tree;

public:
    void ResetContent();

    void SelectAsset(DWORD_PTR _Node);


public:
    virtual void render_update() override;

public:
    Content();
    ~Content();
};

