#pragma once

#include <memory>

class NPC;
class Elf;
class Druid;
class Dragon;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual bool visit(Elf& elf) = 0;
    virtual bool visit(Druid& druid) = 0;
    virtual bool visit(Dragon& dragon) = 0;
};

class NPCVisitor : public Visitor {
public:
    NPCVisitor(std::shared_ptr<NPC> attacker);
    
    bool visit(Elf& orc) override;
    bool visit(Druid& squirrel) override;
    bool visit(Dragon& bear) override;

private:
    std::shared_ptr<NPC> attacker_;
};