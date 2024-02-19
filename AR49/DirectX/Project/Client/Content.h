#pragma once
#include "UI.h"

// AssetMgr �� �ε��Ǿ� �ִ� ��� ���µ��� ����

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

