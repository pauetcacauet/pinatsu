#pragma once
#include "defines.h"

#include "systems/handle/handle.h"
#include "systems/components/comp_base.h"

class CEntity : public TCompBase
{
    CHandle comps[CHandle::maxTypes];

public:
    ~CEntity();

    CHandle get(u32 type) const {
        PASSERT(type < CHandle::maxTypes)
        return comps[type];
    }

    template<typename TComp>
    CHandle get() const {
        auto om = getObjectManager<TComp>();
        PASSERT(om)
        return comps[om->getType()];
    }

    void debugInMenu();
    void renderDebug();

    void set(uint32_t comp_type, CHandle new_comp);
    void set(CHandle new_comp);
    void load(const json& j, TEntityParseContext& ctx);
    void onEntityCreated();

    const char* getName() const;
};

// FWD declaration
//template<>
//CObjectManager< CEntity >* getObjectManager<CEntity>();